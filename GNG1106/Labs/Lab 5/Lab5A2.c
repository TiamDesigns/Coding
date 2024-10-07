#include <stdio.h>

double degtorad(double degrees) 
{
    return degrees * 3.1415926535 / 180.0;
}

double funccosx(double x) 
{
    double term = 1;
    double cosx = 1; 
    int sign = -1; 
    int n=1;

    while(term<0.0000000000001 || term>0.0000000000001) 
    {
        term *= -1 / (2*n*(2*n-1));
        n++;
    }

    return cosx;
}

int main() 
{
    double xdeg, xrad;

    printf("Enter the angle in degrees: ");
    scanf("%lf", &xdeg);

    xrad = degtorad(xdeg);

    double cosx = funccosx(xrad);
    printf("The cosine of %.2lf degrees is approximately: %.16lf\n", xdeg, cosx);

    return 0;
}