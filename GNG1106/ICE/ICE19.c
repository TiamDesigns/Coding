#include <stdio.h>

double computeFunction(double x) {
    return 2 * x + 2 / x;
}

int main() {
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    double x = 0.01;
    while (x <= 10.0) {
        double fx = computeFunction(x);
        fprintf(file, "%.2f %.2f\n", x, fx);
        x += 0.01;
    }

    fclose(file);
    printf("Results saved to output.txt\n");
    return 0;
}
