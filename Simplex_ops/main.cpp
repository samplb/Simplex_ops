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

int main() {
    int z=0;
    string werteuebergabe;//in diesem string sind die daten
    int n=0;
    int k=0;
    int option=0;
    bool minprob=false;//minimieren?
    bool end=true;//menü beenden
    cout<<"Welcome to our Program: Simplex-EasySolver\n"<<endl;
    do{
        cout<<"Please input the number of one of those options: "
            "\n 1 -path\n 2 -help\n 3 -Maximierungsproblem\n 4 -Problem with BigM-Method\n 5 -Miniemierungsproblem\n 6 -exit"<<endl;
        cin.clear();
        cin>>option;
        if(!(option > 0 && option<7) || cin.fail()){
            option=2;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Please check your Input\n"<<endl;
        }
        switch(option){
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
            case 5: werteuebergabe="2 3\n8 12\n0.1 0.2 1\n0.2 0.1 0.8\n0.1 0.6 1.8\n";//von http://www.gm.fh-koeln.de/~hk/lehre/ala/ws0506/Praktikum/Projekt/A_blau/Simplex_Dokumentation.pdf S.10
                    end=false;
                    minprob=true;
                    break;
            case 6: cout<<"Programm closed"<<endl;
                    return 1;
            default:cin.clear();
            cout<<"Please check you Input"<<endl;
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
                   /* ifstream filestream(path,ios_base::binary);//opens stream im binarymodus
                    filestream.seekg(0,ios_base::end);//setzt marker an das ende des streams
                    int length;
                    length=filestream.tellg();//liest die letzte Stelle aus.
                    filestream.seekg(0,ios_base::beg);//setzt den marker wieder an den anfang
                    char buffer[length];//erzeugt char mit richtiger länge
                    filestream.read(buffer,length);//liest stream in char ein
                    werteuebergabe=buffer;//convert char in stream
                    filestream.close();*/
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
    double **A;
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
    cout<<"\nLösung:"<<endl;
    for(int zz=0;zz<n;zz++){
        cout<<"x"<<zz+1<<": "<<zwert[zz]<<endl;
//        cout<<zwert[zz]<<" / ";
    }
    cout<<"optimaler Wert: "<<zwert[n+k]<<endl;
    for(int j=0; j<n;j++)  
        delete [] A[j];
    delete [] A;
//    cout<<endl<<"end"<<endl;
    return 0;
}

