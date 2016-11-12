/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Solve.h
 * Author: Bernhard Sampl
 *
 * Created on 12. November 2016, 02:30
 */

#ifndef SOLVE_H
#define SOLVE_H

class Solve {
public:
    Solve();
    double* lpsolve(int n, double* c, int k, double** A, double* b);
    ~Solve();
};

#endif /* SOLVE_H */

