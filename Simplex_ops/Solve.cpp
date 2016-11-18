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
    cout<<"end of Solve function"<<endl;
};
/* returns a double array in the format of: xxxxxxxx??*/
double* Solve::lpsolve(int n, double* c, int k, double** A, double* b){
//     c hat länge n+k wegen schlupfvariablen, 
    //  b hat länge kk; wegen spaltenbeschriftung.
    // A hat A[zeilen][spalten];spalten ist n+k+1 wegen schlupfvariablen und der 
    int col=n+k+1;
    double* pivot=nullptr;
    Eigen::MatrixXd tableau(k+1,col);//ausgangstabelle
//    Eigen::MatrixXd tableau1(k+1,col);//kopie von tableau zum rechnentabelle
    tableau.setZero();
//    tableau1.setZero();
//    cout<<"vectorb: "<<endl;
    for(int i=0;i<k;i++){
        tableau(1+i,col-1)=b[i];
//        cout<<" "<<tableau(i+1,col-1);
    }
//    cout<<endl<<"vectorc: "<<endl;
    for(int j=0;j<(n);j++){
        tableau(0,j)=(c[j]*-1);
//        cout<<" "<<tableau(0,j);
    }
//    cout<<endl<<"Ausgangstableau: \n"<<tableau<<endl;
    for(int l=0;l<k;l++){
        tableau(l+1,n+l)=1;
        for(int m=0;m<n;m++){
            tableau(l+1,m)=A[m][l];
//            cout<<" "<<A[m][l];;
                   
        }
//        cout<<endl;
    }
        cout<<endl<<tableau<<endl;
//        while(!finished(tableau1)){
//            pivot=getPivot(tableau);
//            
//        }
    return NULL;
};
/*returns a Eigen Matrix after finding a pivot and calculate all other coefficients new.*/
Eigen::MatrixXd Solve::solvetablet(Eigen::MatrixXd& tableau1){
    
};
/*returns a double vector with Pivotzeile,Pivotspalte*/
double* Solve::getPivot(Eigen::MatrixXd tableau1) {
    
};
/*returns true, if no negative coefficients in ZF*/
bool Solve::finished(Eigen::VectorXd f){
    if(f.minCoeff()>=0){
        return true;
    }
    return false;
};