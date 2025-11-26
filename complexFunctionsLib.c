#include "complexFunctionsLibHeader.h"



double degreesToRadians(double degrees) {
    return degrees * PI / 180;
}

double radiansToDegrees(double radians) {
    return radians * 180 / PI;
}
void complexConjugate(complex_number *complexNumber, complex_number *complexConjugateResult) {
    double conjugateReal = complexNumber->real;
    double conjugateImaginary = -complexNumber->imaginary;
    cartesianSetup(complexConjugateResult, conjugateReal, conjugateImaginary);
}

void cartesianSetup(complex_number *complexNumber, double real, double imaginary) {
    double magnitude = 0;
    double argumentInRadians = 0;
    double argumentInDegrees = 0;
    magnitude = sqrt(real * real + imaginary * imaginary);
    argumentInRadians = atan2(imaginary, real);
    argumentInDegrees = radiansToDegrees(argumentInRadians);
    complexNumber->imaginary = imaginary;
    complexNumber->real = real;
    complexNumber->magnitude = magnitude;
    complexNumber->angle.argumentInDegrees = argumentInDegrees;
    complexNumber->angle.argumentInRadians = argumentInRadians;
    complexNumber->angle.principalValueInDegrees = principalValueInDegrees(complexNumber->angle.argumentInDegrees);
    complexNumber->angle.principalValueInRadians = degreesToRadians(complexNumber->angle.principalValueInDegrees);
}

///
/// @param complexNumber
/// @return returns the angle between 0 and 2π that corresponds to the input angle minus rotations.
void polarSetup(complex_number *complexNumber, double magnitude, double angle, int angleType) {
    complexNumber->magnitude = magnitude;
    if (angleType == RADIANS) {
        complexNumber->angle.argumentInRadians = angle;
        complexNumber->angle.argumentInDegrees = radiansToDegrees(angle);
        complexNumber->angle.principalValueInRadians = principalValueInRadians(angle);
        complexNumber->angle.principalValueInDegrees = radiansToDegrees(complexNumber->angle.principalValueInRadians);
    } else if (angleType == DEGREES) {
        complexNumber->angle.argumentInDegrees = angle;
        complexNumber->angle.argumentInRadians = degreesToRadians(angle);
        complexNumber->angle.principalValueInDegrees = principalValueInDegrees(angle);
        complexNumber->angle.principalValueInRadians = degreesToRadians(complexNumber->angle.principalValueInDegrees);
    }
    complexNumber->real = magnitude * cos(complexNumber->angle.argumentInRadians);
    complexNumber->imaginary = magnitude * sin(complexNumber->angle.argumentInRadians);
}

///
/// @param angle
/// @return returns the angle between 0 and 2π that corresponds to the input angle minus rotations.
double principalValueInRadians(double angle) {
    return angle - 2 * PI * floor(angle / (2 * PI));
}

double principalValueInDegrees(double angle) {
    return angle - 360 * floor(angle / 360);
}

void complexRaisePowerDeMoivre(complex_number *complexNumber, complex_number *complexPower, double power) {
    complexPower->magnitude = pow(complexNumber->magnitude, power);
    complexPower->angle.argumentInRadians = complexNumber->angle.argumentInRadians * power;
    polarSetup(complexPower, complexPower->magnitude, complexPower->angle.argumentInRadians, RADIANS);
}

void complexRotate(complex_number *complexNumber, complex_number *complexRotation, double rotation, int angleType) {
    double newAngle = complexNumber->angle.argumentInRadians + rotation;
    polarSetup(complexRotation, complexNumber->magnitude, newAngle, angleType);
}

void complexSum(complex_number *complexSum, complex_number *complexNumber1, complex_number *complexNumber2) {
    cartesianSetup(complexSum, complexNumber1->real + complexNumber2->real,
                   complexNumber1->imaginary + complexNumber2->imaginary);
}

void complexDiff(complex_number *complexDiff, complex_number *complexNumber1, complex_number *complexNumber2) {
    cartesianSetup(complexDiff, complexNumber1->real - complexNumber2->real,
                   complexNumber1->imaginary - complexNumber2->imaginary);
}

void complexMultip(complex_number *complexMultiplicationResult, complex_number *complexNumber1,
                   complex_number *complexNumber2) {
    //(real1+imag1i)*(real2+imag2i) = real1real2+real1imag2i+real2imag1i-imag1imag2= real1real2-imag1imag2+i(real1imag2+real2imag1)
    double resultReal = complexNumber1->real * complexNumber2->real - complexNumber1->imaginary * complexNumber2->
                        imaginary;
    double resultImaginary = complexNumber1->real * complexNumber2->imaginary + complexNumber1->imaginary *
                             complexNumber2->real;
    cartesianSetup(complexMultiplicationResult, resultReal, resultImaginary);
}

void complexDiv(complex_number *complexDivisionResult, complex_number *complexNumber1,complex_number *complexNumber2) {
    complex_number reciprocal2;
    complexReciprocal(complexNumber2,&reciprocal2);
    complexMultip(complexDivisionResult,complexNumber1,&reciprocal2);

}

void complexReciprocal(complex_number *complexNumber, complex_number *complexReciprocal) {
    double realResult=complexNumber->real/(complexNumber->real*complexNumber->real+complexNumber->imaginary*complexNumber->imaginary);
    double imaginaryResult=-complexNumber->imaginary/(complexNumber->real*complexNumber->real+complexNumber->imaginary*complexNumber->imaginary);
    cartesianSetup(complexReciprocal, realResult, imaginaryResult);
}