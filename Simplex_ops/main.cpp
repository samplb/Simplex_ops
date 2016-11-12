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
//    */
    
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
//    cout<<"c: _ ";
    for(int vc=0;vc<n;vc++){
        c[vc]=temp[vc+2];
//        cout<<c[vc]<<"  ";
    }
    zaelwert+=n;//wert, der sofort in der 3ten zeile beginnt.
        int temo=zaelwert;
//    cout<<endl<<"b: _ ";
    for(int vb=0;vb<k;vb++){
        b[vb]=temp[temo+=n];
//        cout<<" "<<b[vb];
        temo++;
    }
//    cout<<endl;
        for(int aa=0;aa<k;aa++){
//        cout<<"---------zw: ---"<<zaelwert<<" !!!! "<<temp[zaelwert]<<endl;
            
            for(int aaa=0; aaa<n;aaa++){
//                cout<<"zw: "<<zaelwert<<"--WERT: "<<temp[zaelwert]<<endl;
                A[aaa][aa]=temp[zaelwert];
                zaelwert++;
//                cout<<"5: "<<aaa<<endl;
//                cout<<"Array: "<<A[aaa][aa]<<endl;
            }
        zaelwert++;
        }
    
        cout<<"ok"<<endl;
    for(int j=0; j<n;j++)  delete [] A[j];
    delete [] A;
    return 0;
}

