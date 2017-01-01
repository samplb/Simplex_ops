/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<string>
#include<vector>
#include<stdlib.h>  //includes atof for conversion
#include"Convertdouble.h"
#include<iostream>
using namespace std;


/*This function returns all numbers separetet with blank as a vector with double values.*/
vector<double> Convertdouble::convertstring(string x) {
//    cout<<"Start Convertdouble.cpp"<<endl;
    int ab=x.length()+1;
    vector<double> arr;
    double u=0;
    cout<<"Textfile: \n"<<x<<endl;
    string fo;
    for(int i=0; i<ab;){
        fo.clear();
        if(x[i]!=' ' && i<ab && x[i]!='\n') {
            while(x[i]!=' ' && i<ab && x[i]!='\n') {
            fo+=x[i];
            i++;
//            cout<<"fo"<<fo<<" ";
        }
        } else {
//            cout<<"X"<<endl;
            fo.clear();
            i++;
        }
//           do{
//               int gg=i;
//               i++;
//               if(x[gg]=='\n'){
//                   break;
//               }
//               fo+=x[gg];
//               cout<<"fo: "<<fo<<" ";
//            }while(x[i]!=' ' && i<ab && x[i]!='\n');
//            cout<<endl;
           if(!fo.empty()){
           u=atof(fo.c_str());
//           cout<<"u"<<i<<": "<<u<<endl;
           arr.push_back(u);
           }
           fo.clear();    
    }
    return arr;
}

        