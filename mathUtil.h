//
// Created by tabit on 27/11/2025.
//

#ifndef MATHUTIL_H
#define MATHUTIL_H


double calculateNthRootBinaryMethod(double degree,double number);
double calculateNthRootNewtonMethod(double degree,double number);
double calculatePower(double number, int power);

// testing
void utilNthRootComparison(double number,int power);
double testCalculateNthRootBinaryMethod(double degree, double number);
double testCalculateNthRootNewtonMethod(double degree, double number);
#endif //MATHUTIL_H