#include <stdio.h>

typedef struct {
    int width;
    int length;
} RECTANGLE;


int absolute(int value) {
    return (value < 0) ? -value : value;
}

int checkAreas(RECTANGLE rects[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int area1 = rects[i].width * rects[i].length;
        int area2 = rects[i + 1].width * rects[i + 1].length;
        if (absolute(area1 - area2) < 10) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    int n;

    printf("Enter the number of rectangles: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Need more rectangles.\n");
        return 0;
    }

    RECTANGLE rects[n];

    for (int i = 0; i < n; i++) {
        printf("Enter width and length %d: ", i + 1);
        scanf("%d %d", &rects[i].width, &rects[i].length);
    }

    if (checkAreas(rects, n)) {
        printf("There are two consecutive rectangles with a difference in area less than 10.\n");
    } else {
        printf("No such rectangles found.\n");
    }

    return 0;
}
