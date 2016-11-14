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

double* Solve::lpsolve(int n, double* c, int k, double** A, double* b){
//     c hat länge n+k wegen schlupfvariablen, 
    //  b hat länge kk; wegen spaltenbeschriftung.
    // A hat A[zeilen][spalten];spalten ist n+k+1 wegen schlupfvariablen und der 
    int col=n+k;
    double pivot=0;
    Eigen::MatrixXd tableau(k,col);//ausgangstabelle
    Eigen::MatrixXd tableau1(k,col);//kopie von tableau zum rechnentabelle
    tableau.setZero();
    tableau.setZero();
    Eigen::VectorXd vc(n+k); //Vectpr c ist die zielfunktion
    Eigen::VectorXd vb(k);  //vector b sind die werte
    double z=0;    //zielwert, somit ergebnis
    vector<string> pv;
    vector<string> sv;
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
    vc*=-1;//Zielfunktion auf rechte Seite bringen für Standardform
//    cout<<endl<<"Ausgangstableau: \n"<<tableau<<endl;
    for(int l=0;l<k;l++){
        tableau(l,n+l)=1;
        for(int m=0;m<n;m++){
            tableau(l,m)=A[m][l];
//            cout<<" "<<A[m][l];;
                   
        }
//        cout<<endl;
    }
        cout<<endl<<tableau<<endl;
        while(!finished(c)){
            pivot=getPivot(tableau,*vc,*vb);
            
        }
    return NULL;
};
bool Solve::solvetablet(Eigen::MatrixXd& tableau1, Eigen::VectorXd& c, Eigen::VectorXd& b){
    
};

double Solve::getPivot(Eigen::MatrixXd tableau1, Eigen::VectorXd& c, Eigen::VectorXd& b){

};

bool Solve::finished(Eigen::VectorXd f){
    if(f.minCoeff()>=0){
        return true;
    }
    return false;
};