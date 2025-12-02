#include "mathUtil.h"
#include <math.h>

double calculateNthRootBinaryMethod(double degree, double number)
{
    double root = 0;
    int sign = number < 0 ? -1 : 1;
    double absNumber = fabs(number);

    if(degree == 0 || (fabs(fmod(degree, 2.0)) < 1e-10 && number < 0)){
        return -1; //error either no degree or even root with negative base
    } else if(fabs(number) == 1){
        return sign * 1;
    } else if(degree == 2){
        return sign * sqrt(absNumber);
    } else {
        //binary search
        double tolerance = 0.01;
        int maxIterations = 100;
        int iterations = 0;

        double upperLimit = fmax(absNumber, 1);
        double lowerLimit = 0;
        double mid = (upperLimit + lowerLimit) / 2;

        while(fabs(calculatePower(mid, degree) - absNumber) >= tolerance && iterations < maxIterations){
            mid = (upperLimit + lowerLimit) / 2;
            if(calculatePower(mid, degree) < absNumber){
                lowerLimit = mid;
            } else {
                upperLimit = mid;
            }
            iterations++;
        }
        root = mid;
    }
    return sign * root;
}
double calculateNthRootNewtonMethod(double degree,double number) {
    double root=5;// select a better point
    // divide by sign and oddity
    int steps=10;// add a check for tolerance
    for(int i=1;i<=steps;i++) {
        root=1/degree*((degree-1)*root+number/calculatePower(root,degree-1));
    }
    return root;
}
double calculatePower(double number, int power){
  // to handle double power
  double result=1;
  for(int i = 0; i < power; i++){
    result *= number;
  }
  return result;
  }