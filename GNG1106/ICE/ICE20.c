#include <stdio.h>

double f(double x);

double integrate(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    integral += f(a) / 2.0;
    integral += f(b) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += f(x);
    }

    integral *= h; 
    return integral;
}

double f(double x) {
    return x * x;
}

int main() {
    double a, b;
    int n = 1000;

    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);

    double result = integrate(a, b, n);
    printf("The integral of f(x) from %.2f to %.2f is %.6f\n", a, b, result);

    return 0;
}
