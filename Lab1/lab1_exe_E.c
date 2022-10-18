/*
 *  File Name: lab1_exe_E.c
 *  Assignment: Lab 1 Exercise A
 *  Lab section: B01
 *  Completed by: Aarsh
 *  Submission Date: Thursday Sept 23, before (2:00 PM)
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    // Initializes variables for quadratic equation
    double a, b, c, radicand, denominator, x1, x2;

    // Prompt for input for a, b and c.
    printf("Input values for a, b, c:\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    // Compute value under the square root and in the denominator
    radicand = (pow(b, 2)) - (4 * a * c);
    denominator = (2 * a);

    // If there is real roots with 2 distinct roots
    if (radicand > 0)
    {
        // Compute quadratic formula
        x1 = (-b + sqrt(radicand)) / denominator;
        x2 = (-b - sqrt(radicand)) / denominator;
        printf("The roots are: x1= %lf, x2= %lf", x1, x2);
    }
    // If it is a perfect square (two identical roots)
    else if (radicand == 0)
    {
        // Compute quadratic formula
        x1 = x2 = -b / denominator;
        printf("The roots are: x1=x2= %lf", x1);
    }
    // If there are imaginary roots (or in other words there is a negative in the square root)
    else
    {
        double xReal, xImag;
        // Compute quadratic formula and flipping sign of the radicand to avoid error
        xReal = -b / denominator;
        xImag = sqrt(abs(radicand)) / denominator;
        printf("x1: %lf+%lfi, x2: %lf-%lfi", xReal, xImag, xReal, xImag);
    }

    return 0;
}