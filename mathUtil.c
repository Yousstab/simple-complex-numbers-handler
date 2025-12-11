#include "mathUtil.h"
#include <math.h>
#include <stdio.h>

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
    double root=number>1?sqrt(number):1; // 1 as initial guess if number smaller than 1 else sqrt
    int maxSteps=50;// add a check for tolerance
    double tolerance =1e-10;
    for (int i = 0; i < maxSteps; i++) {
        double powerDegreeMinusOne = calculatePower(root, degree - 1);
        double power = root * powerDegreeMinusOne;  // Reuse calculation

        double error = fabs(power - number);  // Check actual error
        if (error < tolerance * fabs(number)) {
            break;  // Converged
        }

        // Newton's method formula
        root = ((degree - 1) * root + number / powerDegreeMinusOne) / degree;
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


void utilNthRootComparison(double number, int power) {
// do a comparison about methods
    printf("\n initializing comparison...\n");
    printf("newton vs binary calculating %d-root of number %lf\n",power,number);
    printf("binary\n");
    testCalculateNthRootBinaryMethod(power,number);
    printf("newton\n");
    testCalculateNthRootNewtonMethod(power,number);
}


double testCalculateNthRootBinaryMethod(double degree, double number)
{
    double root = 0;
    int sign = number < 0 ? -1 : 1;
    double absNumber = fabs(number);

    if(degree == 0 || (fabs(fmod(degree, 2.0)) < 1e-10 && number < 0)){
        printf("number of iterations: 0\n");
        return -1; //error either no degree or even root with negative base

    } else if(fabs(number) == 1){
        printf("guess: %lf precision: %lf\n",number,0.0);
        printf("number of iterations: 1\n");
        return sign * 1;

    } else if(degree == 2){
        printf("guess: %lf precision: %lf\n",sign * sqrt(absNumber),fabs(calculatePower(sign * sqrt(absNumber), degree) - absNumber)/100);
        printf("number of iterations: %d\n",1);
        return sign * sqrt(absNumber);

    } else {
        //binary search
        double tolerance = 1e-3;
        int maxIterations = 100;
        int iterations = 0;

        double upperLimit = fmax(absNumber, 1);
        double lowerLimit = 0;
        double mid = (upperLimit + lowerLimit) / 2;

        while(fabs(calculatePower(mid, degree) - absNumber) /100>= tolerance && iterations < maxIterations){
            mid = (upperLimit + lowerLimit) / 2;
            if(calculatePower(mid, degree) < absNumber){
                lowerLimit = mid;
            } else {
                upperLimit = mid;
            }
            printf("guess: %lf precision: %lf\n",mid,fabs(calculatePower(mid, degree) - absNumber)/100);
            printf("number of iterations: %d\n",iterations);
            iterations++;

        }
        root = mid;

    }

    return sign * root;
}
double testCalculateNthRootNewtonMethod(double degree,double number) {
    double root=number>1?sqrt(number):1; // 1 as initial guess if number smaller than 1 else sqrt
    int maxSteps=50;// add a check for tolerance
    double tolerance =1e-3;
    int iterations=1;
    for (int i = 0; i < maxSteps; i++) {
        double powerDegreeMinusOne = calculatePower(root, degree - 1);
        double power = root * powerDegreeMinusOne;  // Reuse calculation

        double error = fabs(power - number);  // Check actual error
        if (error < tolerance * fabs(number)) {

            printf("final guess: %lf precision: %lf\n",root,error );
            printf("number of iterations: %d\n",iterations);
            break;  // Converged
        }

        // Newton's method formula
        printf("guess: %lf precision: %lf\n",root,error);
        printf("number of iterations: %d\n",iterations);
        root = ((degree - 1) * root + number / powerDegreeMinusOne) / degree;
        iterations=i;
    }
    return root;
}