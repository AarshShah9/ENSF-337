/*
 *  lab2exe_A.c
 *  Created by Mahmood Moussavi
 *  Completed by: Aarsh Shah
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 9.8; /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

void create_table(double v)
{
    double i, rad_angle;
    printf("Angle\t\tt\t\td\n");
    printf("(deg)\t\t(sec)\t\t(m)\n");
    for (i = 0.0; i <= 90.0; i += 5.0)
    {
        rad_angle = degree_to_radian(i);
        printf("%lf\t%lf\t%lf\n", i, Projectile_travel_time(rad_angle, v), Projectile_travel_distance(rad_angle, v));
    }
}

double Projectile_travel_time(double a, double v)
{
    return ((2 * v * sin(a)) / G);
}

double Projectile_travel_distance(double a, double v)
{

    return ((pow(v, 2)) / G) * fabs(sin(2 * a));
}

double degree_to_radian(double d)
{
    return d * (PI / 180);
}

int main(void)
{
    int n;
    double velocity;

    printf("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf", &velocity);

    if (n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }

    while (velocity < 0)
    {
        printf("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if (n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }

    create_table(velocity);
    return 0;
}

/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */
