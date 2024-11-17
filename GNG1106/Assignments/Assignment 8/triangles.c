#include <stdio.h>
#include <math.h>

typedef struct {
    double x1, y1;
    double x2, y2;
    double x3, y3;
} TRIANGLE;

void printTriangle(TRIANGLE triangle);
double getPerimeter(TRIANGLE triangle);
int getIndexOfLargestTriangleInArray(TRIANGLE triangles[], int numTriangles);
TRIANGLE getTriangleFromUser();

int main() {
    TRIANGLE triangles[4];
    int i;

    for (i = 0; i < 4; i++) {
        printf("Enter information for triangle %d:\n", i + 1);
        triangles[i] = getTriangleFromUser();
    }

    int largestIndex = getIndexOfLargestTriangleInArray(triangles, 4);

    printf("\nThe triangle with the largest perimeter is triangle %d:\n", largestIndex + 1);
    printTriangle(triangles[largestIndex]);
    printf("Perimeter: %.2f\n", getPerimeter(triangles[largestIndex]));

    return 0;
}

void printTriangle(TRIANGLE triangle) {
    printf("Triangle vertices:\n");
    printf("  Vertex 1: (%.2f, %.2f)\n", triangle.x1, triangle.y1);
    printf("  Vertex 2: (%.2f, %.2f)\n", triangle.x2, triangle.y2);
    printf("  Vertex 3: (%.2f, %.2f)\n", triangle.x3, triangle.y3);
}

double getPerimeter(TRIANGLE triangle) {
    // Calculate the lengths of the three sides
    double side1 = sqrt((triangle.x2 - triangle.x1) * (triangle.x2 - triangle.x1) +
                        (triangle.y2 - triangle.y1) * (triangle.y2 - triangle.y1));
    double side2 = sqrt((triangle.x3 - triangle.x2) * (triangle.x3 - triangle.x2) +
                        (triangle.y3 - triangle.y2) * (triangle.y3 - triangle.y2));
    double side3 = sqrt((triangle.x3 - triangle.x1) * (triangle.x3 - triangle.x1) +
                        (triangle.y3 - triangle.y1) * (triangle.y3 - triangle.y1));
    // Return the perimeter
    return side1 + side2 + side3;
}

int getIndexOfLargestTriangleInArray(TRIANGLE triangles[], int numTriangles) {
    int largestIndex = 0;
    double largestPerimeter = getPerimeter(triangles[0]);

    for (int i = 1; i < numTriangles; i++) {
        double perimeter = getPerimeter(triangles[i]);
        if (perimeter > largestPerimeter) {
            largestPerimeter = perimeter;
            largestIndex = i;
        }
    }
    return largestIndex;
}

TRIANGLE getTriangleFromUser() {
    TRIANGLE triangle;
    printf("Enter the x and y coordinates of vertex 1: ");
    scanf("%lf %lf", &triangle.x1, &triangle.y1);
    printf("Enter the x and y coordinates of vertex 2: ");
    scanf("%lf %lf", &triangle.x2, &triangle.y2);
    printf("Enter the x and y coordinates of vertex 3: ");
    scanf("%lf %lf", &triangle.x3, &triangle.y3);
    return triangle;
}
