
#ifndef COMPLEXFUNCTIONSLIBHEADER_H
#define COMPLEXFUNCTIONSLIBHEADER_H
#include <math.h>
#define PI 3.14159265358979323846
#define E 2.7182818
typedef enum {
    RADIANS = 0,
    DEGREES = 1
} angleType;

typedef enum {
    FALSE = 0,
    TRUE = 1
} bool;


typedef struct {
    double argumentInRadians;
    double argumentInDegrees;
    double principalValueInRadians;
    double principalValueInDegrees;
} angle_struct;

typedef struct {
    double real;
    double imaginary;
    double magnitude;
    angle_struct angle;
} complex_number;
double degreesToRadians(double degrees);
double radiansToDegrees(double radians);

double principalValueInRadians(double angle);
double principalValueInDegrees(double angle);


void cartesianSetup(complex_number *complexNumber, double real, double imaginary);


void polarSetup(complex_number *complexNumber, double magnitude, double angle, int angleType);


void complexConjugate(complex_number *complexNumber, complex_number *complexConjugateResult);
void complexRaisePowerDeMoivre(complex_number *complexNumber, complex_number *complexPower, double power);
void complexRotate(complex_number *complexNumber, complex_number *complexRotation, double rotation, int angleType);



void complexSum(complex_number *complexSum, complex_number *complexNumber1, complex_number *complexNumber2);
void complexDiff(complex_number *complexDiff, complex_number *complexNumber1, complex_number *complexNumber2);
void complexMultip(complex_number *complexMultiplicationResult, complex_number *complexNumber1,complex_number *complexNumber2);
void complexDiv(complex_number *complexDivisionResult, complex_number *complexNumber1,complex_number *complexNumber2);
void complexReciprocal(complex_number *complexNumber, complex_number *complexReciprocal);
#endif //COMPLEXFUNCTIONSLIBHEADER_H
