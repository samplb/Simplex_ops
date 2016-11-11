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
using namespace std;

/*
 * 
 */

//vector<double>  arrayIn(string l);
int main(int argc, char** argv) {
    string werteuebergabe;
    int z=0;
    int n=0;
    int k=0;
    vector<double> c;
    vector<double> b;
    
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
//    converts char in string
    werteuebergabe.append(inputtemp);
//  cout<<"string:"<<werteuebergabe<<endl;
//    converts the string in an vector<double>
    Convertdouble cs;
    temp=cs.convertstring(werteuebergabe);
/* output of double-values in vector.
    cout << "myvector contains:";
  for (unsigned i=0; i<temp.size(); ++i)
    cout << ' ' << temp[i]<<endl;
*/
    n=temp[0];
    k=temp[1];
    cout<<"1:"<<n<<"  k:"<<k<<endl;
    file.close();
    x->close();
    return 0;
}

