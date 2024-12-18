#include <stdio.h>

double evaluate(double x) {
    return -2 + x - 0.5 * x * x + 0.02 * x * x * x + 4 * x * x * x * x + 0.1 * x * x * x * x * x;
}

double absolute(double value) {
    return value < 0 ? -value : value;
}

double bisection(double a, double b, double tol, int iterations) {
    double mid;
    int iter = 0;

    if (evaluate(a) * evaluate(b) >= 0) {
        printf("Invalid interval: f(a) and f(b) must have opposite signs.\n");
        return -1;
    }

    do {
        mid = (a + b) / 2.0;
        double f_mid = evaluate(mid);

        if (absolute(f_mid) < tol) {
            return mid;
        }

        if (evaluate(a) * f_mid < 0) {
            b = mid;
        } else {
            a = mid;
        }

        iter++;
    } while (absolute(b - a) > tol && iter < iterations);

    if (iter == iterations) {
        printf("Warning: Maximum iterations reached.\n");
    }

    return mid;
}

int main() {
    double a = 0;
    double b = 1;
    double tolerance = 1e-6;
    int max_iterations = 50;

    double root = bisection(a, b, tolerance, max_iterations);

    if (root != -1) {
        printf("The root is approximately: %.6f\n", root);
    }

    return 0;
}