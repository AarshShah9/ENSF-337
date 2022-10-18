/*
 *  File Name: lab1_exe_D.c
 *  Assignment: Lab 1 Exercise D
 *  Lab section: B01
 *  Completed by: Aarsh
 *  Submission Date: Thursday Sept 23, before (2:00 PM)
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double angle, sinExact, sinApprox;

    // Prompt for input angle in units of radians.
    printf("Input an angle in radian units:\n");

    // Read input angle in units of radians.
    scanf("%lf", &angle);

    // Compute and output the sine of the input angle using built-in trigonometric functions.
    sinExact = sin(angle);
    printf("The exact value of sin(%lf) is: %lf\n", angle, sinExact);

    // Compute and output the Taylor series approximation of including terms up to order seven (i.e., ).
    sinApprox = angle - ((pow(angle, 3.0)) / (3 * 2 * 1)) + ((pow(angle, 5.0)) / (5 * 4 * 3 * 2 * 1)) - ((pow(angle, 7.0)) / (7 * 6 * 5 * 4 * 3 * 2 * 1));
    printf("The approx. value of sin(%lf) is: %lf", angle, sinApprox);

    return 0;
}