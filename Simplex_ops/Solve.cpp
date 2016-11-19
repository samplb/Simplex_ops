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
    cout<<"Start solvefunc"<<endl;

};
Solve::~Solve(){
    cout<<"Destruction of Solve function"<<endl;
};
/* returns a double array in the format of: xxxxxxxx??*/
double* Solve::lpsolve(int n, double* c, int k, double** A, double* b){
//     c hat länge n+k wegen schlupfvariablen, 
    //  b hat länge kk; wegen spaltenbeschriftung.
    // A hat A[zeilen][spalten];spalten ist n+k+1 wegen schlupfvariablen und der 
    
    int col=n+k+1;
    static double* answer=new double[col];
    for(int x=0;x<k;x++){
        answer[x]=0;
    }
    double *bV=new double[k];
    for(int xxx=0;xxx<k;xxx++){
        bV[xxx]=xxx+n;
    }
    Eigen::MatrixXd tableau(k+1,col);//ausgangstabelle
    tableau.setZero();
//  Adds values of vector b
    for(int i=0;i<k;i++){
        tableau(1+i,col-1)=b[i];
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
    int *pivot;
    cout<<endl<<tableau<<endl;
//        cout<<endl<<tableau1<<endl;
    int count=0;
    while(!finished(tableau)){
        pivot=getPivot(tableau);
//        cout<<"Z: "<<pivot[0]<<" S:"<<pivot[1]<<endl;
        bV[pivot[0]]=pivot[1];
        cout<<"Basisvariablen:"<<endl;
        for(int xx=0;xx<k;xx++){
            cout<<bV[xx]<<" ";
        }
          tableau(0,pivot[1])=0;//temporär.
        tableau=solvetableau(tableau,pivot);
    cout<<endl<<tableau<<endl;
    count++;
    cout<<"count: "<<count<<endl;
    }        
    double* ret=answer;
    delete [] bV;
    delete [] answer;
    return ret;
};
/*returns a Eigen Matrix after finding a pivot and calculate all other coefficients new.*/
Eigen::MatrixXd Solve::solvetableau(Eigen::MatrixXd& ta, int *x){
    Eigen::MatrixXd copy=ta;
//    cout<<copy<<"\nPivot: Zeile/Spalte "<<x[0]<<"/"<<x[1]<<endl;
    for(int i=0;i<ta.rows();i++) {//zeilen
        for(int j=0;j<ta.cols();j++) {//spalten
            if(i!=x[0] && copy(i,x[1])!=0){
                ta(i,j)-=((copy(x[0],j)/copy(x[0],x[1]))*copy(i,x[1]));
            } else if(i!=x[0] && copy(i,x[1])==0) {
                break;
            } else if(i==x[0]) {
                ta(i,j)/=copy(x[0],x[1]);
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
//    cout<<"pivotelement s/z: "<<pv[1]<<"/"<<pv[0]<<endl;
    
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