#include <stdio.h>

//Function to convert input degrees to radians. 
double degtorad(double degrees) 
{
    return degrees * 3.1415926535897 / 180.0;
}

//Function for cos(x) operation
double funccosx(double x) 
{
    double term = 1;
    double cosx = 1; 
    int n=0;

    while(term<-0.0000000000001 || term>0.0000000000001) 
    {
        n++;
        term *= (-x * x / (2*n * (2*n-1)));
        cosx += term;
    }

    return cosx;
}

double funcsinx(double x) 
{
    double term = x;
    double sinx = x; 
    int n=0;

    while(term<-0.0000000000001 || term>0.0000000000001) 
    {
        n++;
        term *= (-x * x) / (2 * n * (2*n+1));
        sinx += term;
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
        printf("The tangent of %.2lf degrees is approximately: %.14lf\n", xdeg, tanx);
    } else {
        printf("Tangent of %.2lf degrees is undefined (division by zero).\n", xdeg);
    }

    return 0;
}