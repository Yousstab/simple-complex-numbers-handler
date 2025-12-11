#include <stdio.h>
#include <stdlib.h>
#include "complexFunctionsLibHeader.h"



//π
void oneComplex();
void twoComplex();

void cartesianInput(complex_number *complexNumber);
void polarInput(complex_number *complexNumber);

void setupComplexNumber(complex_number *complexNumber);
void displayFullComplexNumber(complex_number *complexNumber);
void displayLittleComplexNumber(complex_number *complexNumber) ;



void nonImplementedError();

int main(void) {
    char choice = "";
    while (choice != 'e') {
        printf("choose(1 number or letter):\n");
        printf("1. one complex\n");
        printf("2. two complex\n");
        //printf("3. three or more complex\n");
        //printf("4. equation solver\n");
        printf("u. util testing\n");
        printf("e. exit\n");
        scanf(" %c", &choice);
        printf("\n");
        if (choice != 'e') {
            switch (choice) {
                case '1':
                    oneComplex();
                    break;
                case '2':
                    twoComplex();
                    break;
                /*      case '3':
                          nonImplementedError();
                          break;
                      case '4':
                          nonImplementedError();
                      break;*/
                case 'u':
                    utilNthRootComparison(10000,4);

                default:
                    printf("pick a valid choice.\n");
                    break;
            }
        }
    }
    return 0;
}

void oneComplex() {
    complex_number complexNumber;
    errorWrap error;
    setupComplexNumber(&complexNumber);

    char choice = "";
    while (choice != 'e') {
        printf("choose: \n");
        printf("1. display complex number full information(polar coord. , cartesian coord., etc.)\n");
        printf("2. display conjugate full information\n");
        printf("3. calculate a power\n");
        printf("4. calculate the n-roots\n");
        printf("5. calculate a rotation\n");
        printf("6. calculate reciprocal(1/Z)\n");
        printf("e. exit\n");
        scanf(" %c", &choice);
        printf("\n");
        if (choice != 'e') {
            switch (choice) {
                case '1':
                    displayFullComplexNumber(&complexNumber);
                    break;
                case '2':
                    complex_number conjugate;
                    complexConjugate(&complexNumber, &conjugate);
                    displayFullComplexNumber(&conjugate);
                    break;
                case '3':
                    complex_number complexPower;
                    double power = 0.0;
                    printf("what power?\n");
                    scanf(" %lf", &power);
                    printf("\n");
                    complexRaisePowerDeMoivre(&complexNumber, &complexPower, power);
                    displayFullComplexNumber(&complexPower);
                    break;
                case '4':
                    complex_number* complex_roots;
                    int numRoots;
                    printf("number of roots: ");
                    scanf(" %d", &numRoots);
                    complex_roots=(complex_number*)malloc(numRoots*sizeof(complex_number));
                    complexFindRoots(&complexNumber,numRoots,complex_roots,&error);
                    if (error.errorPresent==FALSE) {
                        for (int i = 0; i < numRoots; i++) {
                            printf("root %d\n",i+1);
                            displayLittleComplexNumber(&complex_roots[i]);
                            printf("----------------------\n");
                        }
                    }else {
                        printf("error please check\n");
                        printf("error message: %s \n",error.errorMessage);
                    }
                    free(complex_roots);
                    break;
                case '5':
                    complex_number complexRotation;
                    double rotation = 0.0;
                    int angleType = RADIANS;
                    printf("rotation angle type?\n");
                    printf("r. radians\n");
                    printf("d. degrees\n");
                    scanf(" %c", &choice);
                    printf("\n");
                    if (choice == 'd') {
                        angleType = DEGREES;
                        printf("insert angle: ");
                        scanf(" %lf", &rotation);
                    } else {
                        printf("input the constant in front of pi(0 if no pi): ");
                        scanf("%lf", &rotation);
                        printf("\n");
                        rotation = PI * rotation;
                        if (rotation == 0) {
                            double app = 0;
                            printf("input the rest: ");
                            scanf("%lf", &app);
                            printf("\n");
                            rotation = rotation + app;
                        }
                    }
                    complexRotate(&complexNumber, &complexRotation, rotation, angleType);
                    displayFullComplexNumber(&complexRotation);

                    break;
                case '6':
                        complex_number complexReciprocalResult;
                        complexReciprocal(&complexNumber,&complexReciprocalResult,&error);
                        if (error.errorPresent==FALSE) {
                            displayFullComplexNumber(&complexReciprocalResult);
                        }else {
                            printf("error please check\n");
                            printf("error message: %s \n",error.errorMessage);
                        }
                    break;
                default:
                    printf("pick a valid choice.\n\n");
                    break;
            }
        }
    }
    displayFullComplexNumber(&complexNumber);
}


void twoComplex() {
    complex_number complexNumber1, complexNumber2;
    errorWrap error;
    printf("Enter the first complex number:\n");
    setupComplexNumber(&complexNumber1);
    printf("Enter the second complex number:\n");
    setupComplexNumber(&complexNumber2);

    char choice = "";
    while (choice != 'e') {
        printf("choose: \n");
        printf("1. display complex numbers full information(polar coord. , cartesian coord., etc.)\n");
        printf("2. display conjugates full information\n");
        printf("3. calculate the sum\n");
        printf("4. calculate the subtraction (first-second)\n");
        printf("5. calculate multiplication\n");
        printf("6. calculate division\n");
        printf("e. exit\n");
        scanf(" %c", &choice);
        printf("\n");
        if (choice != 'e') {
            switch (choice) {
                case '1':
                    displayFullComplexNumber(&complexNumber1);
                    displayFullComplexNumber(&complexNumber2);
                    break;
                case '2':
                    complex_number conjugate1, conjugate2;

                    complexConjugate(&complexNumber1, &conjugate1);
                    displayFullComplexNumber(&conjugate1);
                    complexConjugate(&complexNumber2, &conjugate2);
                    displayFullComplexNumber(&conjugate2);
                    break;
                case '3':
                    complex_number complexSumResult;
                    complexSum(&complexSumResult, &complexNumber1, &complexNumber2);
                    displayFullComplexNumber(&complexSumResult);
                    break;
                case '4':
                    complex_number complexDiffResult;
                    complexDiff(&complexDiffResult, &complexNumber1, &complexNumber2);
                    displayFullComplexNumber(&complexDiffResult);
                    break;
                case '5':
                    complex_number complexMultiplicationResult;
                    complexMultip(&complexMultiplicationResult, &complexNumber1, &complexNumber2);
                    displayFullComplexNumber(&complexMultiplicationResult);
                    break;
                case '6':
                    complex_number complexDivisionResult;
                    complexDiv(&complexDivisionResult, &complexNumber1, &complexNumber2,&error);
                    if (error.errorPresent==FALSE) {
                        displayFullComplexNumber(&complexDivisionResult);
                    }else {
                        printf(error.errorMessage);
                    }

                    break;
                default:
                    printf("pick a valid choice.\n\n");
                    break;
            }
        }
    }
}

void displayFullComplexNumber(complex_number *complexNumber) {
    printf("The complex number is:\n");
    if (complexNumber->imaginary < 0) {
        printf("cartesian form: %.2lf - i(%.2lf)\n", complexNumber->real, -complexNumber->imaginary);
    } else {
        printf("cartesian form: %.2lf + i(%.2lf)\n", complexNumber->real, complexNumber->imaginary);
    }
    printf("polar form(radians): %.2lf(cos(%.2lfpi)+isin(%.2lfpi))\n", complexNumber->magnitude,
           complexNumber->angle.argumentInRadians / PI, complexNumber->angle.argumentInRadians / PI);
    printf("polar form(degrees): %.2lf(cos(%.2lf)+isin(%.2lf))\n", complexNumber->magnitude,
           complexNumber->angle.argumentInDegrees, complexNumber->angle.argumentInDegrees);

    printf("real: %.2lf\n", complexNumber->real);
    printf("imaginary: %.2lf\n", complexNumber->imaginary);
    printf("magnitude: %.2lf\n", complexNumber->magnitude);
    printf("argument in radians: %.2lfpi\n", complexNumber->angle.argumentInRadians / PI);
    printf("argument in degrees: %.2lf\n", complexNumber->angle.argumentInDegrees);
    printf("principal value in degrees %.2lf\n", complexNumber->angle.principalValueInDegrees);
    printf("principal value in radians %.2lfpi\n", complexNumber->angle.principalValueInRadians / PI);
}

void displayLittleComplexNumber(complex_number *complexNumber) {
    printf("The complex number is:\n");
    if (complexNumber->imaginary < 0) {
        printf("cartesian form: %.2lf - i(%.2lf)\n", complexNumber->real, -complexNumber->imaginary);
    } else {
        printf("cartesian form: %.2lf + i(%.2lf)\n", complexNumber->real, complexNumber->imaginary);
    }
    printf("polar form(radians): %.2lf(cos(%.2lfpi)+isin(%.2lfpi))\n", complexNumber->magnitude,
           complexNumber->angle.argumentInRadians / PI, complexNumber->angle.argumentInRadians / PI);
    printf("polar form(degrees): %.2lf(cos(%.2lf)+isin(%.2lf))\n", complexNumber->magnitude,
           complexNumber->angle.argumentInDegrees, complexNumber->angle.argumentInDegrees);
}

void setupComplexNumber(complex_number *complexNumber) {
    char choice = "";
    while (choice != 'c' && choice != 'p') {
        printf("choose: \n");
        printf("c. input cartesian\n");
        printf("p. input polar\n");
        scanf(" %c", &choice);
        printf("\n");
    }
    if (choice == 'c') {
        cartesianInput(complexNumber);
    } else if (choice == 'p') {
        polarInput(complexNumber);
    }
}



void cartesianInput(complex_number *complexNumber) {
    double real, imaginary;
    printf("insert real part: ");
    scanf("%lf", &real);
    printf("\n");
    printf("insert imaginary part: ");
    scanf("%lf", &imaginary);
    printf("\n");
    cartesianSetup(complexNumber, real, imaginary);
}

void polarInput(complex_number *complexNumber) {
    char choice = "";
    double magnitude = 0;
    double angle = 0;
    printf("insert magnitude: ");
    scanf("%lf", &magnitude);
    while (choice != 'r' && choice != 'd') {
        printf("choose input argument type: \n");
        printf("r. radiants \n");
        printf("d. degrees \n");
        scanf(" %c", &choice);
        printf("\n");
    }
    if (choice == 'r') {
        printf("input the constant in front of pi(0 if no pi): ");
        scanf("%lf", &angle);
        printf("\n");
        angle = PI * angle;
        if (angle == 0) {
            double app = 0;
            printf("input the rest: ");
            scanf("%lf", &app);
            printf("\n");
            angle = angle + app;
        }
        polarSetup(complexNumber, magnitude, angle, RADIANS);
    } else {
        printf("input angle in degrees: ");
        scanf("%lf", &angle);
        printf("\n");
        polarSetup(complexNumber, magnitude, angle, DEGREES);
    }
}

void nonImplementedError() {
    printf("This program does not support this operation yet.\n");
}

