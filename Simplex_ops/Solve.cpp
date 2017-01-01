/*Solve.cpp reads the parameters and returns a <double> optimal value.
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"Solve.h"
#include<iostream>
#include<Eigen/Core>
#include<string>
#include<vector>
//using namespace Eigen;
using namespace std;
Solve::Solve(){
//    cout<<"Start solvefunc"<<endl;

};
/*Funktion zur Ausgangstableauerstellung bei der Maximierung der Funktion*/
Eigen::MatrixXd Solve::minimieren(int n, double* c, int k, double** A, double* b){
    cout<<"startmin"<<endl;
    Eigen::MatrixXd tableau(n+1,n+k+1);//ausgangstabelle
    tableau.setZero();
//  Adds values of vector b
//    cout<<"b"<<endl;
    int col=n+k+1;
    for(int i=0;i<k;i++){ 
        tableau(0,i)=b[i]*-1;
    }
//    adds values of vector c
//    cout<<"c"<<endl;
    for(int j=0;j<(n);j++){
        tableau(1+j,col-1)=(c[j]);
    }
//    adds values of matrix A and Schlupfvariablen
//    cout<<"A"<<endl;
    for(int l=0;l<n;l++){//spalte
        tableau(l+1,l+k)=1;
////        cout<<"A1"<<endl;
        for(int m=0;m<k;m++){//zeile
//            cout<<"A2"<<endl;
            tableau(l+1,m)=A[l][m];
//     A[spalte][zeile]
//            cout<<A[l][m]<<"    ";
        }
    }
    cout<<"tableau:\n"<<tableau<<endl;
        return tableau;
    
}
/*Funktion zur Ausgangstableauerstellung bei der Maximierung der Funktion*/
Eigen::MatrixXd Solve::maximieren(int n, double* c, int k, double** A, double* b){
    Eigen::MatrixXd tableau(k+1,n+k+1);//ausgangstabelle
    tableau.setZero();
    //  Adds values of vector b
    for(int i=0;i<k;i++){
        tableau(1+i,(n+k+1)-1)=b[i];        
    }
//    adds values of vector c
    for(int j=0;j<(n);j++){
        tableau(0,j)=(c[j]*-1);
    }
//    adds values of matrix A and Schlupfvariablen
    for(int l=0;l<k;l++){
        tableau(l+1,n+l)=1;
        for(int m=0;m<n;m++){
            tableau(l+1,m)=A[m][l];
        }
    }
    cout<<"tableau:\n"<<tableau<<endl;
        return tableau;
}

/* returns a double array in the format of: xxxxxxxx??*/
double* Solve::lpsolve(int n, double* c, int k, double** A, double* b,bool minim){
    // A hat A[zeilen][spalten];spalten ist n+k+1 wegen schlupfvariablen und der 
    bool negb=false;//if true, bigM method:
    int col=n+k+1;
    static double* answer=new double[col];
    for(int x=0;x<col;x++){
        answer[x]=0;
    }
    double *bV=new double[k];
    for(int xxx=0;xxx<k;xxx++){
        bV[xxx]=xxx+n;
    }
    
    if(minim){
//        cout<<"Minimierung:"<<endl;
        Eigen::MatrixXd tableau(n+1,col);//ausgangstabelle
        tableau.setZero();
        tableau=minimieren(n,c,k,A,b);
        int *pivot;
        int count=0;
        for(int i=0;i<n;i++){
            if(c[i]<0) {
                negb=true;
            }
        }
        cout<<"Das Ausgangstableau: \n"<<tableau<<endl<<"____________________________________________\n\n"<<endl;
        if(!negb) {
         while(!finished(tableau)){
            pivot=getPivot(tableau);
            int rr=pivot[0]-1;
            bV[rr]=pivot[1];
//        cout<<"Z: "<<pivot[0]<<" S:"<<pivot[1]<<endl;
//        cout<<"Basisvariablen:\t";
//        for(int xx=0;xx<k;xx++){
//            cout<<bV[xx]<<" ";
//        }
         tableau=solvetableau(tableau,pivot);
//      cout<<"Das Pivotelement ist in spalte/zeile: "<<pivot[1]<<"/"<<pivot[0]<<endl;
//      cout<<"Berechnungstableau:\t"<<count<<"\n"<<tableau<<endl<<"...........................................................................\n"<<endl;
        count++;
        
        cout<<"Tableau: \n"<<tableau<<endl;
    }
    Eigen::VectorXd ergeb(col);
    ergeb=tableau.row(0);
    cout<<"egeb:"<<ergeb<<endl;
    for(int x=0;x<n;x++){
        answer[x]=ergeb(x+k);
//        cout<<answer[x]<<"    ";
    }
    answer[col-1]=ergeb(col-1);
    delete [] bV;
    return answer;
    } else {
        cout<<"Shit-USE BIG M METHOD"<<endl;
    }
    
    } else if(!minim) {
        cout<<"Maximierung:"<<endl;
        Eigen::MatrixXd tableau(k+1,col);//ausgangstabelle
        tableau.setZero();
        tableau=maximieren(n,c,k,A,b);
        int *pivot;
    int count=0;
    for(int i=0;i<k;i++){
        if(b[i]<0) {
            negb=true;
        }
    }
    cout<<"Das Ausgangstableau: \n"<<tableau<<endl<<"____________________________________________\n\n"<<endl;
    if(!negb) {
         while(!finished(tableau)){
//        cout<<"Tableau: "<<tableau<<endl;
            pivot=getPivot(tableau);
            int rr=pivot[0]-1;
            bV[rr]=pivot[1];
//        cout<<"Z: "<<pivot[0]<<" S:"<<pivot[1]<<endl;
//        cout<<"Basisvariablen:\t";
//        for(int xx=0;xx<k;xx++){
//            cout<<bV[xx]<<" ";
//        }
         tableau=solvetableau(tableau,pivot);
//      cout<<"Das Pivotelement ist in spalte/zeile: "<<pivot[1]<<"/"<<pivot[0]<<endl;
//      cout<<"Berechnungstableau:\t"<<count<<"\n"<<tableau<<endl<<"...........................................................................\n"<<endl;
        count++;
    }
    Eigen::VectorXd ergeb(k+1);
    ergeb=tableau.col(col-1);
//    cout<<"egeb:"<<ergeb<<endl;
    for(int x=0;x<k;x++){
        int stelle=bV[x];
        answer[stelle]=ergeb(x+1);
    }
    answer[col-1]=ergeb(0);
    delete [] bV;
    return answer;
    } else {
        cout<<"Shit-USE BIG M METHOD"<<endl;
    }
    }
    
    delete [] answer;
};
/*returns a Eigen Matrix after finding a pivot and calculate all other coefficients new.*/
Eigen::MatrixXd Solve::solvetableau(Eigen::MatrixXd& ta, int *x){
//    cout<<"Starte solvetableau func."<<endl;
    Eigen::MatrixXd copy=ta;
//    cout<<"Copy: \n"<<copy<<endl;
//    cout<<copy<<"\nPivo3t: Zeile0/Spalte1 "<<x[0]<<"/"<<x[1]<<endl;
    for(int i=0;i<ta.rows();i++) {//zeilen
        for(int j=0;j<ta.cols();j++) {//spalten
            if(i!=x[0] && copy(i,x[1])!=0){//Berechnung aller anderen Matrixelemente.
                ta(i,j)-=((copy(x[0],j)/copy(x[0],x[1]))*copy(i,x[1]));
//                cout<<"i: "<<i<<"   j: "<<j<<endl;
//                cout<<"neuer Wert: "<<ta(i,j)<<endl;
//                cout<<"1: "<<copy(x[0],j)<<endl;
//                cout<<"2: "<<copy(x[0],x[1])<<endl;
//                cout<<"3: "<<copy(i,x[1])<<endl;
            } else if(i!=x[0] && copy(i,x[1])==0) {//keine änderung wenn pivotspaltenelement null ist
//                cout<<"keine werteänderung!"<<endl;
                break;
            } else if(i==x[0]) {//if pivotzeile, alles durch das Pivotelement dividieren.
                ta(i,j)/=copy(x[0],x[1]);
//                cout<<"neuer pivotzeilenwert: "<<ta(i,j)<<endl;
            } else {
                cout<<"What else?"<<endl;
            }
        }
    }
    return ta;
};
/*returns a double vector with Pivotzeile,Pivotspalte*/
int* Solve::getPivot(Eigen::MatrixXd t) {
    static int pv[2]={0}; //static, da wert nach funktionsende noch existieren muss.
    double xtemp=0;
    for(int i=0;i<t.cols();i++){
        if(t(0,i)<xtemp) {
            pv[1]=i;
            xtemp=t(0,i);
        }
    }
//    zeile!:
    xtemp=1.7E+307;
    double xquot;
    for(int j=1;j<t.rows();j++){
        if(t(j,pv[1])>0){
            xquot=t(j,t.cols()-1)/t(j,pv[1]);
            if(xquot<xtemp){
                pv[0]=j;
                xtemp=xquot;
            }
        }
    }
    
    int* ppv=pv;
//    cout<<"ppv: "<<*ppv<<endl;
    return ppv;
};
/*returns true, if no negative coefficients in ZF*/
bool Solve::finished(Eigen::MatrixXd f){
    if(f.row(0).minCoeff()>=0){
        return true;
    }
    return false;
};
/* Minimierungsproblem-Transformation:*/
 
Solve::~Solve(){
    

//    cout<<"Destruction of Solve function"<<endl;
};