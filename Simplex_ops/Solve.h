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
#include<Eigen/Core>
class Solve {
public:
    Solve();
    /*returns a double vector with Pivotzeile,Pivotspalte*/
    int* getPivot(Eigen::MatrixXd tableau1);
    /*returns a Eigen Matrix after finding a pivot and calculate all other coefficients new.*/
    Eigen::MatrixXd solvetableau(Eigen::MatrixXd& ta, int* x);
    double* lpsolve(int n, double* c, int k, double** A, double* b);
    /*returns true, if no negative coefficients in ZF*/
    bool finished(Eigen::MatrixXd f);
    ~Solve();
};

#endif /* SOLVE_H */

