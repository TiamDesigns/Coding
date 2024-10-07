#include <stdio.h>

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

    if (cosx != 0) {
        double tanx = sinx / cosx;
        printf("The tangent of %.2lf degrees is approximately: %.16lf\n", xdeg, tanx);
    } else {
        printf("Tangent of %.2lf degrees is undefined (division by zero).\n", xdeg);
    }

    return 0;
}