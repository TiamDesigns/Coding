#include <stdio.h>

#define tolerance 0.0000001

//Function to convert input degrees to radians. 
double degtorad(double degrees) 
{
    return degrees * 3.1415926535 / 180.0;
}

//Function for cos(x) operation
double funccosx(double x) 
{
    double term = 1;
    double cosx = 1; 
    int sign = -1; 

    for (int i = 2; i <= 2000; i += 2) 
    {
        term *= (x * x) / (i * (i - 1));
        cosx += sign * term;
        sign = -sign;
    }

    return cosx;
}

//Function for sin(x) operation
double funcsinx(double x)
{
    double term = x;
    double sinx = x; 
    int sign = -1; 

    for (int i = 3; i <= 2000; i += 2) 
    {
        term *= (x * x) / (i * (i - 1));
        sinx += sign * term;
        sign = -sign;
    }

    return sinx;
}


int main() 
{
    double xdeg, xrad;

    printf("Enter the angle in degrees: ");
    scanf("%lf", &xdeg);

    xrad = degtorad(xdeg);

    double cosx = funccosx(xrad);
    double sinx = funcsinx(xrad);

    if (cosx > -tolerance && cosx < tolerance) {
            printf("tan(%.2lf) = infinity\n", xdeg);
        } else {
            double tanx = sinx / cosx;
            printf("tan(%.2lf) = %.15lf\n", xdeg, tanx);
        }

    return 0;
}