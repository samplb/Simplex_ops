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
#include"Solve.h"
using namespace std;
/*
 * 
 */
//Test if renamed repository still works
//vector<double>  arrayIn(string l);
int main(int argc, char** argv) {
    int z=0;
    string werteuebergabe;
    int n=0;
    int k=0;
    int length;
    string path;
    path="C:/Users/Bernhard Sampl/Documents/NetBeansProjects/Simples_OPS/a1401504-unet.univie.ac.at/Simplex_ops/Textfile/ops.txt";
    ifstream filestream("C:/Users/Bernhard Sampl/Documents/NetBeansProjects/Simples_OPS/a1401504-unet.univie.ac.at/Simplex_ops/Textfile/ops1.txt",ios::binary);
    filestream.seekg(0,ios::end);
    length=filestream.tellg();
    filestream.seekg(0,ios::beg);
    char buffer[length];
    filestream.read(buffer,length);
     werteuebergabe=buffer;
    filestream.close();
 
    //-------------------------------------------------------------------------------------------------------------------
    

    vector<double> temp;
    cout<<"Array: "<<werteuebergabe<<endl;
    Convertdouble cs;
    temp=cs.convertstring(werteuebergabe);
    n=temp[0];
    k=temp[1];
    z=temp.size();  //amount of elements.
    int zz=(k*(n+1))+2+n;
//    creates Matrix and Vectors with values.
    if(z!=zz){
        cerr<<"Fehler bei der Matrixgröße!"<<"_IstLengthArray_"<<z<<"_shouldLengthArray_"<<zz<<endl;
        return 2;
    }
    int zaelwert=0;
    double c[n];
    double b[k];
    zaelwert+=2;//beginn 2te zeile
    double **A=nullptr;
    //array erzeugen mit n spatlten und k zeilen.
    A=new double* [n];
    for(int i=0; i<n;i++){
        A[i]=new double[k];
    }
    
    // for Test of new textfile just un-comment all cout<< until row 117 to see the inprogramm-arrays and vectors
    
    
//    cout<<"c: ";
    for(int vc=0;vc<n;vc++){
        c[vc]=temp[vc+2];
//        cout<<c[vc]<<"  ";
    }
    zaelwert+=n;//wert, der sofort in der 3ten zeile beginnt.
        int temo=zaelwert;
    cout<<endl<<"b: ";
    for(int vb=0;vb<k;vb++){
        b[vb]=temp[temo+=n];
        cout<<" "<<b[vb];
        temo++;
    }
//    cout<<endl<<"Array: "<<endl;
        for(int aa=0;aa<k;aa++){
//        cout<<endl;
            for(int aaa=0; aaa<n;aaa++){
                A[aaa][aa]=temp[zaelwert];
                zaelwert++;
//                cout<<A[aaa][aa]<<" ";
            }
        zaelwert++;
        }
//    cout<<endl<<"ok"<<endl;
    
//    Start solving problem:
    
    
    Solve r;
    double *zwert=r.lpsolve(n,c,k,A,b);
//    cout<<"Lösung:"<<endl;
//    for(int zz=0;zz<n+k+1;zz++){
//        cout<<zwert[zz]<<" / ";
//    }
    for(int j=0; j<n;j++)  delete [] A[j];
    delete [] A;
    cout<<endl<<"end"<<endl;
    return 0;
}

