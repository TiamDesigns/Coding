#include <stdio.h>
#include <math.h>

#define STEP_SIZE 0.01 
#define NUM_STEPS 300  


double dx_dt(double t, double x, double y) {
    return x + exp(-t / 2.0) * cos(5 * t);
}

double dy_dt(double t, double x, double y) {
    return (1.0 / 2.0) * y + exp(-t / 2.0) * sin(5 * t);
}

int main() {
    double t = 0.0, x = 0.0, y = 0.0; 
    double x_next, y_next;
    FILE *file;

    file = fopen("trajectory.csv", "w");
    if (file == NULL) {
        printf("Error\n");
        return 1;
    }

    fprintf(file, "t,x,y\n");

    for (int i = 0; i < NUM_STEPS; i++) {
        fprintf(file, "%.2f,%.6f,%.6f\n", t, x, y);

        x_next = x + STEP_SIZE * dx_dt(t, x, y);
        y_next = y + STEP_SIZE * dy_dt(t, x, y);

        x = x_next;
        y = y_next;
        t += STEP_SIZE;
    }

    fclose(file);

    printf("Data saved to 'trajectory.csv'.\n");
    return 0;
}
