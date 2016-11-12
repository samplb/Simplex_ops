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
    string path="C:/Users/Bernhard Sampl/Documents/NetBeansProjects/a1401504-unet.univie.ac.at/Simplex_ops/Textfile/ops.txt";
    
    //-------------------------------------------------------------------------------------------------------------------
    
    
//    /*
    
//   file is open. 
    try{
       x->open(path,ios_base::in);
    if(!file.is_open()){
        cerr << "Einlesefehler"<<file.exceptions()<<endl;
        return 2;
    }
    } catch(...) {
        cout<<"Error with File-Reading"<<endl;
    }
    char inputtemp[1000];
    vector<double> temp;
//   adds all values to array inputtemp
    file.read(inputtemp,1000);
//    closes Filestreams
    file.close();
    x->close();
//    converts char in string
    werteuebergabe.append(inputtemp);
//    cout<<werteuebergabe<<endl;
//    converts the string in an vector<double>
//    */
//    cout<<"Array: "<<werteuebergabe<<endl;
    Convertdouble cs;
    temp=cs.convertstring(werteuebergabe);
/* output of double-values in vector.
    cout << "vector contains:";
  for (unsigned i=0; i<temp.size(); ++i)
    cout << ' ' << temp[i]<<endl;
 * */
    n=temp[0];
    k=temp[1];
    z=temp.size();  //amount of elements.
    int zz=(k*(n+1))+2+n;
//    creates Matrix and Vectors with values.
    if(z!=zz){
        cerr<<"Fehler bei der Matrixgröße!"<<"_z_"<<z<<"_zz_"<<zz<<endl;
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
    
    // for Test of new textfile just un-comment all cout<< until row 117
    
    
    cout<<"c: ";
    for(int vc=0;vc<n;vc++){
        c[vc]=temp[vc+2];
        cout<<c[vc]<<"  ";
    }
    zaelwert+=n;//wert, der sofort in der 3ten zeile beginnt.
        int temo=zaelwert;
    cout<<endl<<"b: ";
    for(int vb=0;vb<k;vb++){
        b[vb]=temp[temo+=n];
        cout<<" "<<b[vb];
        temo++;
    }
    cout<<endl<<"Array: "<<endl;
        for(int aa=0;aa<k;aa++){
        cout<<endl;
            for(int aaa=0; aaa<n;aaa++){
                A[aaa][aa]=temp[zaelwert];
                zaelwert++;
                cout<<A[aaa][aa]<<" ";
            }
        zaelwert++;
        }
    cout<<endl<<"ok"<<endl;
    Solve r;
    r.lpsolve(n,c,k,A,b);
        
    for(int j=0; j<n;j++)  delete [] A[j];
    delete [] A;
    cout<<"end"<<endl;
    return 0;
}

