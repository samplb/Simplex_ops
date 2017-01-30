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
#include<exception>
using namespace std;
Solve::Solve(){
    cout<<"start solve.cpp\n";

};
/*Funktion zur Ausgangstableauerstellung bei der Maximierung der Funktion*/
Eigen::MatrixXd Solve::minimieren(int n, double* c, int k, double** A, double* b){
    Eigen::MatrixXd tableau(n+1,n+k+1);//ausgangstabelle
    tableau.setZero();
//Adds values of vector b
    int col=n+k+1;
    for(int i=0;i<k;i++){ 
        tableau(0,i)=b[i]*-1;
    }
//adds values of vector c
    for(int j=0;j<(n);j++){
        tableau(1+j,col-1)=(c[j]);
    }
//adds values of matrix A and Schlupfvariablen
    for(int l=0;l<n;l++){//spalte
        tableau(l+1,l+k)=1;
        for(int m=0;m<k;m++){//zeile
            tableau(l+1,m)=A[l][m];
        }
    }
        return tableau;
    
}
/*Funktion zur Ausgangstableauerstellung bei der Maximierung der Funktion*/
Eigen::MatrixXd Solve::maximieren(int n, double* c, int k, double** A, double* b){
    Eigen::MatrixXd tableau(k+1,n+k+1);//ausgangstabelle
    tableau.setZero();
    //Adds values of vector b
    for(int i=0;i<k;i++){
        tableau(1+i,(n+k+1)-1)=b[i];        
    }
//adds values of vector c
    for(int j=0;j<(n);j++){
        tableau(0,j)=(c[j]*-1);
    }
//adds values of matrix A and Schlupfvariablen
    for(int l=0;l<k;l++){
        tableau(l+1,n+l)=1;
        for(int m=0;m<n;m++){
            tableau(l+1,m)=A[m][l];
        }
    }
        return tableau;
}

/* returns a double array in the format of:  Alle Werte der Variablen, 
 * erst x und dann schlupfvariablen, letzte stelle ist Z-Wert*/
double* Solve::lpsolve(int n, double* c, int k, double** A, double* b,bool minim)  {
    //A hat A[zeilen][spalten];spalten ist n+k+1 wegen schlupfvariablen und der 
    bool negb=false;//if true, bigM method:
    int col=n+k+1;
        int count=0;
    double* answer=new double[col];
    for(int x=0;x<col;x++){
        answer[x]=0;
    }
    double *bV=new double[k];
    for(int xxx=0;xxx<k;xxx++){
        bV[xxx]=xxx+n;
    }
    
    if(minim) {
        Eigen::MatrixXd tableau(n+1,col);//ausgangstabelle
        tableau.setZero();
        tableau=minimieren(n,c,k,A,b);
        int *pivot;
        for(int i=0;i<n;i++){
            if(c[i]<0) {
                negb=true;
            }
        }
        cout<<endl<<"____________________________________________\n\n"<<endl<<"Das Ausgangstableau: \n"<<tableau<<endl<<"____________________________________________\n\n"<<endl;
        if(!negb) {
            count=0;
         while(!finished(tableau)){
            pivot=getPivot(tableau);
            int rr=pivot[0]-1;
            bV[rr]=pivot[1];
         tableau=solvetableau(tableau,pivot); 
         count++;
        
        cout<<"Schritt "<<count<<": \n"<<tableau<<endl;
    }
         
    cout<<endl<<"____________________________________________\n\n"<<endl<<"End-Tableau: \n"<<tableau<<endl<<"____________________________________________\n\n"<<endl;
    Eigen::VectorXd ergeb(col);
    ergeb=tableau.row(0);
    for(int x=0;x<k;x++){
        if(ergeb(col-x-2)!=0 ) {
            int stelle=bV[x];
            answer[stelle]=ergeb(col-x-2);//answer[n+k+1]
        }
    }
    Eigen::VectorXd z=tableau.col(n+k);
    int a=0;
    for(int ii=0;ii<col;ii++){
        double val=0.0;
        
        if(answer[col-1-ii]==0){
            val=z(a);
            answer[col-1-ii]=val;
            a++;
        }
    }
    answer[col-1]=ergeb(col-1);
    delete [] bV;
    return answer;
    } else {
            tableau=solveBigM(tableau);
    }
    
    } else if(!minim) {
        count=0;
        Eigen::MatrixXd tableau(k+1,col);//ausgangstabelle
        tableau.setZero();
        tableau=maximieren(n,c,k,A,b);
        int *pivot;
    for(int i=0;i<k;i++){
        if(b[i]<0) {
            negb=true;
        }
    }
    cout<<endl<<"____________________________________________\n\n"<<endl<<"Das Ausgangstableau: \n"<<tableau<<endl<<"____________________________________________\n\n"<<endl;
    if(!negb) {
         while(!finished(tableau)){
            pivot=getPivot(tableau);
            int rr=pivot[0]-1;
            bV[rr]=pivot[1];
            count++;
            tableau=solvetableau(tableau,pivot);
            
        cout<<"Schritt "<<count<<": \n"<<tableau<<endl;
    }
    cout<<endl<<"____________________________________________\n\n"<<"End-Tableau: \n"<<tableau<<endl<<"____________________________________________\n\n"<<endl;
    Eigen::VectorXd ergeb(k+1);
    ergeb=tableau.col(col-1);
    
    for(int x=0;x<k;x++){
        int stelle=bV[x];
        answer[stelle]=ergeb(x+1);
    }
    Eigen::VectorXd z=tableau.row(0);
    for(int ii=0;ii<col;ii++){
        if(z(ii)!=0){
            answer[ii]=z(ii);
        }
    }
    delete [] bV;
    return answer;
    } else {
         tableau=solveBigM(tableau);
    }
    }
    
    delete [] answer;
};
/*returns a Eigen Matrix after finding a pivot and calculate all other coefficients new.*/
Eigen::MatrixXd Solve::solvetableau(Eigen::MatrixXd& ta, int *x){
    Eigen::MatrixXd copy=ta;
    for(int i=0;i<ta.rows();i++) {//zeilen
        for(int j=0;j<ta.cols();j++) {//spalten
            if(i!=x[0] && copy(i,x[1])!=0){//Berechnung aller anderen Matrixelemente.
                ta(i,j)-=((copy(x[0],j)/copy(x[0],x[1]))*copy(i,x[1]));
//cout<<ta(i,j)<<"-="<<copy(x[0],j)<<"/"<<copy(x[0],x[1])<<"*"<<copy(i,x[1])<<endl;
            } else if(i!=x[0] && copy(i,x[1])==0) {//keine aenderung wenn pivotspaltenelement null ist
//cout<<"keine werteaenderung!"<<endl;
                break;
            } else if(i==x[0]) {//if pivotzeile, alles durch das Pivotelement dividieren.
                ta(i,j)/=copy(x[0],x[1]);
//cout<<"neuer pivotzeilenwert: "<<ta(i,j)<<endl;
            } else {
                cout<<"What else?"<<endl;
            }
            if(ta(i,j)!=ta(i,j)) {
                throw 23;
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
//zeile!:
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
    if(t(pv[0],pv[1])==0) {
//string error="undefined Pivot. Not possible to calculate.";
        throw 20;
    }
    return ppv;
};
/*returns true, if no negative coefficients in ZF*/
bool Solve::finished(Eigen::MatrixXd f){
    if(f.row(0).minCoeff()>=0){
        return true;
    }
    return false;
};
/* Big-M methode*/
Eigen::MatrixXd Solve::solveBigM(Eigen::MatrixXd& ta)   {
    throw 21;
    Eigen::MatrixXd x(2,2);
    return x.Random();
}
 
Solve::~Solve(){
};