/*
 * Programm to Calculate Simplex Algorithms
 */

/* 
 * File:   main.cpp
 * Author: Bernhard Sampl
 *
 */

//#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>
////#include<cmath>
#include<vector>
#include <iomanip>
#include"Convertdouble.h"
#include"Solve.h"
using namespace std;

void wait(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string readFile(char temp[]){
    string werteuebergabe="";
    string tem;
    ifstream x(temp,ios_base::in);
                    if(x.is_open()){
                        while(getline(x,tem)){
                            werteuebergabe+=tem+"\n";
                        }
                        x.close();
                    } else {
                        cout<<"File not found"<<endl;
                    }
    return werteuebergabe;
}
 
bool getMin(){
    bool ok=false;//gültige auswahl:
    bool minprob=false;
    do{
        cout<<"Minimierung('1') oder Maximierung('2') des Problems? Bitte geben Sie die Zahl ein: "<<endl;
        int minim=0;
        cin>>minim;
	if(!(minim != 1 || minim!=2) || cin.fail()){
            minim=0;
            cin.clear();
            cin.ignore(256,'\n');
            ok=true;		
        }
        if(minim==1){minprob=true;}
        else if(minim==2){minprob=false;}
        else {
            ok=true;
        }
    } while(ok);
    return minprob;
}
int main() {
    bool finish=true;
    do{
    int z=0;
    string werteuebergabe;//in diesem string sind die daten
    int n=0;
    int k=0;
    int option=0;
    bool minprob=false;//minimieren?
    bool end=true;//menue beenden
    string menu="\tOptions:\n\tPlease input the number of one of those options: "
                "\n\t\t 1 -path"
                "\n\t\t 2 -help"
                "\n\t\t 3 -maximising"
                "\n\t\t 4 -not implemented"
                "\n\t\t 5 -minimising"
                "\n\t\t 6 -close Program";
    string help=" Help:\n Please choose one of these options. You just have to choose a number and follow the next steps."
                    "\n\t-1 path: path to file in fomat: /home/../x.txt"
                    "\n\t-2 help: shows this help menue"
                    "\n\t-3 maximising is a exampleproblem->max "
                    "\n\t-4 would be a problem to solve with the use of Big-M."
                    "\n\t-5 minimizing is a exampleproblem->min"
                    "\n\t-6 exit: closes Programm"
                    "\n "
                    "\n Our Team hopes that you can sucessfully use our small tool and it solves your problems."
                    "\n Contact: a14015xx@unet.univie.ac.at\n \n";
    cout<<"\n\nWelcome to our Program: Simplex-EasySolver\n"<<endl;
    do{
        cout<<menu<<endl;
        cin.clear();
        cin>>option;
        if(!(option > 0 && option<7) || cin.fail()){
            cout<<"Please check your Input\n"<<endl;
            option=2;
            cin.clear();
            cin.ignore(256,'\n');
        }
        switch(option){
            case 2: cout<<help<<endl;
                    break;
            case 3: werteuebergabe="3 4\n15 20 130\n5 0 0 2\n10 10 0 3\n0 20 20 4\n0 0 50 5";//von aufgabensammlung.txt bsp. 5
            cout<<"3";
                    end=false;
                    break;
            case 4: werteuebergabe="2 2\n1 3\n-1 -2 -2\n1 1 3\n";//von aufgabensammlung.txt bsp. 5
            cout<<"4!";
                    end=false;
                    break;
            case 5: werteuebergabe="2 3\n8 12\n0.1 0.2 1\n0.2 0.1 0.8\n0.1 0.6 1.8\n";//von http://www.gm.fh-koeln.de/~hk/lehre/ala/ws0506/Praktikum/Projekt/A_blau/Simplex_Dokumentation.pdf S.10
                    cout<<"5";end=false;
                    minprob=true;
                    break;
            case 6: cout<<"Programm closed"<<endl;
                    return 0;
            //default:cin.clear();
             //cout<<"Please check you Input!"<<endl;
              //      break;
//                    C:/Users/Bernhard Sampl/Documents/NetBeansProjects/Simples_OPS/a1401504-unet.univie.ac.at/Simplex_ops/Textfile/ops1.txt
            case 1: 
                    minprob=getMin();
                    cout<<"Filepath 'C:/Users/../x.txt': "<<endl;
                    int siz=900;
                    char temp[siz];
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin.getline(temp,siz);
                    werteuebergabe=readFile(temp);
                    end=false;
                    break;
        }
    } while(end);
    //-------------------------------------------------------------------------------------------------------------------
    
    vector<double> temp;
    cout<<"\nStarte die Berechnung:\n"<<endl;
    Convertdouble cs;
//    gibt ein double array mit den werten zurück.
    temp=cs.convertstring(werteuebergabe);
    n=temp[0];
    k=temp[1];
    z=temp.size();  //amount of elements.

    int zz=(k*(n+1))+2+n;
//    creates Matrix and Vectors with values.
    if(z!=zz){
        cerr<<"Size of Matrix inkonsistent! "<<"\n_IstLength-Array_"<<z<<"\n_shouldLength-Array_"<<zz<<endl;
        cerr<<"\nAutomatic resize of Array to should be-size according to k und n values.\nWarning:Result could be wrong:"<<endl;
        temp.resize(zz);
    }
    
    int zaelwert=0;
    double c[n];
    double b[k];
    zaelwert=2;//beginn 2te zeile
    double **A;
    //array erzeugen mit n spatlten und k zeilen.
    A=new double* [n];
    for(int i=0; i<n;i++){
        A[i]=new double[k];
    }
    
    
    
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
    double *zwert;
        try{
    Solve r;
    zwert=r.lpsolve(n,c,k,A,b,minprob);
        } catch(int a) {
            if(a==20){
                cout<<"\nUndefined Values because Pivot is impossible to calculate."<<endl;;
                return 1;
            } else if(a==21) {
                cout<<"\nBig-M Methode is not implemented yet, because not mandatory. please contact the development-team"<<endl;
                return 2;
            } else if(a==23) {
                cout<<"\nUndefined Values in Tableau"<<endl;
            }
        }
    cout<<"\t|\t\n\t|Loesung:"<<endl;
    for(int zz=0;zz<n;zz++){
        cout<<"\t|\tx"<<zz+1<<": "<<fixed<<setprecision(2) <<zwert[zz]<<endl;
    }
    cout<<"\t|optimaler Wert: "<<fixed<<setprecision(2)<<zwert[n+k]<<endl;
    
    cout<<"\t|\t\n\t|\n\t|Schlupfvariablen:"<<endl;
    for(int yy=n;yy<n+k;yy++){
        cout<<"\t|\ty"<<yy+1<<": "<<fixed<<setprecision(2)<<zwert[yy]<<"\n";
    }
    
    
//-------------------------------------------------------------------------------------------------------------------


    
    cout<<endl<<"\nSensibilitaetsanalyse: "<<endl;
    for(int xx=n;xx<n+k;xx++){
        if(zwert[xx]!=0){
            double temp=zwert[n+k]-zwert[xx];
            cout<<"\tWenn Sie die Schlupfvariablen y"<<xx+1<<" um 1 erhöhen, sinkt auch"
                    "\n\tbei der Bedingung "<<xx-n+1<<" der Wert b: "<<b[xx-n]<<" auf "
                    <<b[xx-n]-1<<".\n\tDer Optimalwert ändert sich dadurch auf "
                    ""<<temp<<"("<<zwert[n+k]<<zwert[xx]*-1<<")."<<endl<<
                    "Umgekehrt, wenn Sie b um 1 erhoehen, kann Z um den Wert "
                    <<zwert[xx]<<" erhoeht werden"<<endl<<endl;
        } else {
            cout<<"\tDie Variable y"<<xx+1<<" ist ein Buffer im Wert von "<<zwert[xx]<<" "
                    "der Bedingung "<<xx-n+1<<endl;
        }
        
    }
    cout<<"\nHinweis:\tDie genauen Aenderungen der einzelnen Variablen "
            "sind im Tableau abzulesen."<<endl;
    for(int j=0; j<n;j++)  
        delete [] A[j];
    delete [] A;
    cout<<"Press any key"<<endl;
    wait();
    }while(finish);
    return 0;
}

