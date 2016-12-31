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

int main(int argc, char** argv) {
    int z=0;
    string werteuebergabe;
    int n=0;
    int k=0;
    int option=0;
    bool minprob=false;
    bool end=true;
    cout<<"Welcome to our Program: Simplex-EasySolver\n"<<endl;
    do{
        cout<<"Please input the number of one of those options: "
            "\n 1 -path\n 2 -help\n 3 -Standardproblem\n 4 -Problem with BigM-Method\n 5 -exit"<<endl;
        cin>>option;
        switch(option){
            case 0: break;
            case 2: cout<<"Help:\n Please choose one of the options. You just have to choose a number and follow the next steps."
                    "\n-path: path to file in fomat: C:/Users/../x.txt"
                    "\n-help: shows this help menue"
                    "\n-3 is normal problem->max and -4 is a problem to solve with the use of Big-M."
                    "\n-exit: closes Programm"
                    "\n "
                    "\n Our Team hopes that you can sucessfully use our small tool and it helps you with your problems."
                    "\n Contact: a14015xx@unet.univie.ac.at\n \n"<<endl;
                    break;
            case 3: werteuebergabe="3 4\n15 20 130\n5 0 0 2\n10 10 0 3\n0 20 20 4\n0 0 50 5";//von aufgabensammlung.txt bsp. 5
                    end=false;
                    break;
            case 4: werteuebergabe="2 2\n1 3\n-1 -2 -2\n1 1 3\n";//von aufgabensammlung.txt bsp. 5
                    end=false;
                    break;
            case 5: return 1;
            default:cin.clear();
                    break;
//                    C:/Users/Bernhard Sampl/Documents/NetBeansProjects/Simples_OPS/a1401504-unet.univie.ac.at/Simplex_ops/Textfile/ops1.txt
            case 1: 
                    bool ok=false;
                    do{
                        cout<<"Minimierung('1') oder Maximierung('2') des Problems? Bitte geben Sie die Zahl ein: "<<endl;
                        int minim=0;
                        cin>>minim;
                        if(minim==1){minprob=true;}
                        else if(minim==2){minprob=false;}
                        else {ok=true;}
                    } while(ok);
                    cout<<"Filepath 'C:/Users/../x.txt': "<<endl;
                    string path;
                    cin.clear();
                    cin>>path;
                    ifstream filestream(path,ios::binary);
                    filestream.seekg(0,ios::end);
                    int length;
                    length=filestream.tellg();
                    filestream.seekg(0,ios::beg);
                    char buffer[length];
                    filestream.read(buffer,length);
                    werteuebergabe=buffer;
                    filestream.close();
                    end=false;
                   
                    break;
        }
    } while(end);
    
    
    
 
    //-------------------------------------------------------------------------------------------------------------------
    
    vector<double> temp;
    
    cout<<"Starte die Berechnung:\n"<<endl;
    Convertdouble cs;
//    cout<<"Array:"<<werteuebergabe<<endl;
    temp=cs.convertstring(werteuebergabe);
    n=temp[0];
    k=temp[1];
    z=temp.size();  //amount of elements.
//    for(int i=0;i<z;i++){
//        cout<<temp[i]<<" ";
//    }
    int zz=(k*(n+1))+2+n;
//    creates Matrix and Vectors with values.
    if(z!=zz){
        cerr<<"Fehler bei der Matrixgröße!"<<"_IstLength-Array_"<<z<<"_shouldLength-Array_"<<zz<<endl;
        cerr<<"Resize Array to should be-size, please check for errors:"<<endl;
        temp.resize(zz);
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
//    cout<<endl<<"b: ";
    for(int vb=0;vb<k;vb++){
        b[vb]=temp[temo+=n];
//        cout<<" "<<b[vb];
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
    double *zwert=r.lpsolve(n,c,k,A,b,minprob);
    cout<<"Lösung:"<<endl;
    for(int zz=0;zz<n;zz++){
        cout<<"x"<<zz+1<<": "<<zwert[zz]<<endl;
//        cout<<zwert[zz]<<" / ";
    }
    cout<<"optimaler Maximalwert: "<<zwert[n+k]<<endl;
    for(int j=0; j<n;j++)  
        delete [] A[j];
    delete [] A;
    cout<<endl<<"end"<<endl;
    return 0;
}

