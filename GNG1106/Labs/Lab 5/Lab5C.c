#include <stdio.h>

#define tolerance 0.0000001

//Function to convert input degrees to radians. 
double degtorad(double degrees) 
{
    return degrees * 3.1415926535 / 180.0;
}

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

    if (cosx > -tolerance && cosx < tolerance) {
            printf("tan(%.2lf) = infinity\n", xdeg);
        } else {
            double tanx = sinx / cosx;
            printf("tan(%.2lf) = %.15lf\n", xdeg, tanx);
        }

    return 0;
}