/*
 * Programm to Calculate Simplex Algorithms
 */

/* 
 * File:   main.cpp
 * Author: Bernhard Sampl
 *
 */

#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<vector>
//include headerfiles
#include"Convertdouble.h"
using namespace std;

/*
 * 
 */

//vector<double>  arrayIn(string l);
int main(int argc, char** argv) {
    
    ifstream file;
    filebuf *x=file.rdbuf();
    x->open("ops.txt",ios_base::in);
//   file is open.
    try{
    if(!file){
        cerr << "Einlesefehler"<<file.exceptions()<<endl;
        return 2;
    }
    } catch(...) {
        cout<<"Error with File-Reading"<<endl;
    }
    int z=0;
    int n=0;
    int k=0;
    vector<double> c;
    vector<double> b;
    string l;
    char inputtemp[100];
    vector<double> temp;
    int arraylenght=1;
    int zeile=1;
//    l=inputtemp.
    file.read(inputtemp,100);
    file.
        cout<<inputtemp<<endl;z++;
        temp.push_back(inputtemp[0]);
        l.append(inputtemp);
        cout<<"string:"<<l<<endl;
//    };
//    cout<<"test:"<<n[50]<<":"<<sizeof(n)<<"_"<<z<<endl;
////    cout<<"string"<<l<<endl;
    file.close();
    x->close();
    return 0;
}

