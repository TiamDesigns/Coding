#include <stdio.h>

typedef struct {
    double x; 
    double y; 
    double radius;
} CIRCLE;

CIRCLE getNewCircleFromUser(CIRCLE *arrayOfCircles, int arrayLength) {
    CIRCLE newCircle;
    int valid = 0;

    while (valid == 0) {
        printf("Enter x coordinate of the center: ");
        scanf("%lf", &newCircle.x);
        printf("Enter y coordinate of the center: ");
        scanf("%lf", &newCircle.y);
        printf("Enter radius: ");
        scanf("%lf", &newCircle.radius);

        valid = 1;

        for (int i = 0; i < arrayLength; i++) {
            double dx = newCircle.x - arrayOfCircles[i].x;
            double dy = newCircle.y - arrayOfCircles[i].y;
            double distanceSquared = dx * dx + dy * dy;
            double radiusSum = newCircle.radius + arrayOfCircles[i].radius;

            if (distanceSquared <= radiusSum * radiusSum) {
                printf("The new circle intersects with an existing circle. Please enter a different circle.\n");
                valid = 0; 
                break;
            }
        }
    }

    return newCircle; 
}

int main() {
    CIRCLE existingCircles[3] = {
        {0.0, 0.0, 1.0},
        {3.0, 3.0, 2.0},
        {5.0, 5.0, 1.5}
    };
    int arrayLength = sizeof(existingCircles) / sizeof(existingCircles[0]);

    CIRCLE newCircle = getNewCircleFromUser(existingCircles, arrayLength);
    printf("New circle: Center(%.2f, %.2f), Radius %.2f\n", newCircle.x, newCircle.y, newCircle.radius);

    return 0;
}
