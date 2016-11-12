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

//vector<double>  arrayIn(string l);
int main(int argc, char** argv) {
    int z=0;
    string werteuebergabe;
    int n=0;
    int k=0;
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
    char inputtemp[100];
    vector<double> temp;
//   adds all values to array inputtemp
    file.read(inputtemp,100);
//    closes Filestreams
    file.close();
    x->close();
//    converts char in string
    werteuebergabe.append(inputtemp);
//    cout<<werteuebergabe<<endl;
//    converts the string in an vector<double>
    Convertdouble cs;
    temp=cs.convertstring(werteuebergabe);
/* output of double-values in vector.
    cout << "vector contains:";
  for (unsigned i=0; i<temp.size(); ++i)
    cout << ' ' << temp[i]<<endl;
*/
    n=temp[0];
    k=temp[1];
    z=temp.size();  //amount of elements.
    int zz=(k*(n+1))+2+n;
//    creates Matrix and Vectors with values.
    if(z-1!=zz){
        cerr<<"Fehler bei der Matrixgröße!"<<"_z_"<<z<<"_zz_"<<zz<<endl;
        return 2;
    }
    int zaelwert=0;
    double c[n];
    double b[k];
    zaelwert+=2;//beginn 2te zeile
    double **A=nullptr;
    A=new double* [n];
    for(int i=0; i<n;i++){
        A[i]=new double[k];
    }
    for(int vc=0;vc<n;vc<n){
        c[vc]=temp[vc+2];
    }
    zaelwert+=n;//wert, der sofort in der 3ten zeile beginnt.
        int temo=zaelwert-1;
    for(int vb=0;vb<k;vb++){
        b[vb]=temp[temo+=n];
    }
        for(int aa=0;aa<n;aa++){
            for(int aaa=0; aaa<k;aaa++){
                cout<<x<<endl;
            }
        }
    
    
    return 0;
}

