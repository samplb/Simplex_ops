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
    int ab=x.length()+1;
    vector<double> arr;
    double u=0;
    int anzahl=0;
//    cout<<"string übergabe:"<<ab<<endl;
    for(int i=0; i<ab;){
        string fo;
           do{
               int gg=i;
               i++;
               if(x[gg]=='\n'){
//                   cout<<"break"<<endl;
                   break;
               }
               fo+=x[gg];
//               cout<<fo<<endl;
            }while(x[i]!=' ' && i<ab);
//           cout<<fo<<endl;
           anzahl++;
           u=atof(fo.c_str());
           cout<<u<<endl;
//           cout<<anzahl<<endl;
           arr.push_back(u);
           fo.empty();    
    }
    arr.resize(anzahl);
    return arr;
}

        