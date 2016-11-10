/*89="Hu
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: Bernhard Sampl
 *
 * Created on 10. November 2016, 16:39
 */

//#include <stdlib.h>
#include <iostream>
using namespace std;
/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "newsimpletest test 1" << std::endl;
}

void test2() {
    std::cout << "newsimpletest test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (newsimpletest) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    char u[8]="Huge";
    cout<<sizeof(u)<<" ..." <<u<<endl;

    return (EXIT_SUCCESS);
}

