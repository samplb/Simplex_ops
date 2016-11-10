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
using namespace std;

/*
 * 
 */

vector<double>  arrayIn(string l);
int main(int argc, char** argv) {
    ifstream file;
    filebuf *x=file.rdbuf();
    x->open("ops.txt",ios_base::in);
//   file is open.
    
    if(!file){
        cerr << "Einlesefehler"<<file.exceptions()<<endl;
        return 2;
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
    while(zeile<=k+2){//(file.getline(inputtemp,100)){
        switch(zeile) {
            case 0: file.getline(inputtemp,100); 
            l.append(inputtemp);
            temp=arrayIn(l);
                    break;
            case 1: break;
            case 2: break;
        }
        cout<<inputtemp<<"  ... "<<inputtemp[1]<<endl;z++;
        temp.push_back(inputtemp[0]);
        l.append(inputtemp);
        cout<<"string:"<<l<<endl;
    };
//    cout<<"test:"<<n[50]<<":"<<sizeof(n)<<"_"<<z<<endl;
////    cout<<"string"<<l<<endl;
    file.close();
    x->close();
    return 0;
}

vector<double> arrayIn(string x) {
    int l=x.length();
    vector<double> end;
   while(l){
       string te;
       int temp= x.find(' ');
       string xxx;
       for(int i=0;i<l;i++){
           while(x[i++]!=' '){
               xxx=xxx.push_back(x[i]);
           }
           end.push_back();
       }
       
   }
}