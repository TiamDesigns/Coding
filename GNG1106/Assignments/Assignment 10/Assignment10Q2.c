#include <stdio.h>

double exponential(double x) {
    double result = 1.0;
    double term = 1.0;
    for (int i = 1; i <= 10; i++) {
        term *= x / i;
        result += term;
    }
    return result;
}

double function(double x) {
    double pi = 3.141592653589793;
    double normalization = 1.0 / (1.414213562373095 * pi); 
    double exponent = -(x - 1) * (x - 1) / 2.0;
    return normalization * exponential(exponent);
}

double trapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (function(a) + function(b));
    for (int i = 1; i < n; i++) {
        sum += function(a + i * h);
    }
    return sum * h;
}

int main() {
    double a = 0.0;
    double b = 2.0;
    int n = 1000; 
    double result = trapezoid(a, b, n);
    printf("The integral of the function over [%.1f, %.1f] is approximately: %.2f\n", a, b, result);

    return 0;
}