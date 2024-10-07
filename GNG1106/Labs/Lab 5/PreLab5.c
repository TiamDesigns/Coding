#include <stdio.h>

double exp_x(double x) 
{
    double result = 1.0;  
    double term = 1.0;    
    
    for (int i = 1; i < 1000; i++) 
    {
        term = term * (x / i);
        result += term;
    }

    return result;  
}

int main() 
{
    double x;
   
    printf("Enter the value of x: ");
    scanf("%lf", &x);  
  
    double result = exp_x(x);

    printf("e^%.2lf is approximately: %.8lf\n", x, result);
    
    return 0;
}
