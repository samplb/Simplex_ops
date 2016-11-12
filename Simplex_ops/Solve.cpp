/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"Solve.h"
#include<iostream>
#include<Eigen/Core>
//using namespace Eigen;
using namespace std;
Solve::Solve(){
    cout<<"Start solvefunc"<<endl;

};
Solve::~Solve(){
    cout<<"end of Solve function"<<endl;
};

double* Solve::lpsolve(int n, double* c, int k, double** A, double* b){
    // c hat länge n+k wegen schlupfvariablen, 
    //  b hat länge kk; wegen spaltenbeschriftung.
    // A hat A[zeilen][spalten];spalten ist n+k+1 wegen schlupfvariablen und der 
    int col=n+k+1;
    Eigen::MatrixXd tableau(k+1,col);//ausgangstabelle
    tableau.setZero();
    Eigen::VectorXd vc(n+k); //Vectpr c ist die zielfunktion
    Eigen::VectorXd vb(k);  //vector b sind die werte
    double z=0;    //zielwert, somit ergebnis
    cout<<"vectorb: "<<endl;
    for(int i=0;i<k;i++){
        vb(i)=b[i];
        cout<<" "<<vb(i);
    }
    cout<<endl<<"vectorc: "<<endl;
    for(int j=0;j<(n+k);j++){
        vc(j)=c[j];
        cout<<" "<<vc(j);
    }
    cout<<endl<<"Ausgangstableau: "<<endl;
    for(int l=0;l<k+1;l++){
        for(int m=0;m<col;m++){
//            tableau.;
            cout<<" "<<tableau(l,k);
                   
        }
        cout<<endl;
    }
    return NULL;
};