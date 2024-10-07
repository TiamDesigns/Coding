#include <stdio.h>

double degtorad(double degrees) 
{
    return degrees * 3.1415926535 / 180.0;
}

double taylorcosx(double x) 
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

int main() 
{
    double xdeg, xrad;

    printf("Enter the angle in degrees: ");
    scanf("%lf", &xdeg);

    xrad = degtorad(xdeg);

    double cosx = taylorcosx(xrad);
    printf("The cosine of %.2lf degrees is approximately: %.4lf\n", xdeg, cosx);

    return 0;
}