#include <stdio.h>

typedef struct {
    double width;
    double length;
} RECTANGLE;

void swapLargestRectangleToArrayEnd(RECTANGLE *pRectangles, int numRectangles) {
    if (numRectangles <= 1) {
        return; 
    }

    int maxIndex = 0;
    double maxArea = pRectangles[0].width * pRectangles[0].length;

    for (int i = 1; i < numRectangles; i++) {
        double currentArea = pRectangles[i].width * pRectangles[i].length;
        if (currentArea > maxArea) {
            maxArea = currentArea;
            maxIndex = i;
        }
    }

    if (maxIndex != numRectangles - 1) {
        RECTANGLE temp = pRectangles[maxIndex];
        pRectangles[maxIndex] = pRectangles[numRectangles - 1];
        pRectangles[numRectangles - 1] = temp;
    }
}

int main() {
    RECTANGLE rectangles[5];
    int numRectangles = 5;

    for (int i = 0; i < numRectangles; i++) {
        printf("Enter width and length for rectangle %d: ", i + 1);
        scanf("%lf %lf", &rectangles[i].width, &rectangles[i].length);
    }

    swapLargestRectangleToArrayEnd(rectangles, numRectangles);

    printf("\nRectangles after swapping the largest to the end:\n");
    for (int i = 0; i < numRectangles; i++) {
        printf("Rectangle %d: Width = %.2f, Length = %.2f\n", i + 1, rectangles[i].width, rectangles[i].length);
    }

    return 0;
}
