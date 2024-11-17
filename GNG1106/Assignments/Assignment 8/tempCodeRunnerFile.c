#include <stdio.h>
#define SORT_BY_RADIUS 1
#define SORT_BY_CENTER 2

// structure representing a point on a plane
typedef struct
{
	double x;
	double y;
}COORDINATE;

// structure representing a circle on a plane
typedef struct
{
	COORDINATE center; 
	double radius;
}CIRCLE;

void swapCircles(CIRCLE *pCircleA, CIRCLE *pCircleB);
int shouldCirleAPrecedeCircleB(CIRCLE A, CIRCLE B, int sortingMethod);
void sortCircles(CIRCLE *pCircles, int numCircles, int sortingMethod);
void printCircles(CIRCLE *pCircles, int numCircles);
void getCirclesFromUser(CIRCLE *pCircles, int numCircles);

int main()
{
	CIRCLE A[4];
	int sortingMethod;
	getCirclesFromUser(A, 4);
        printCircles(A, 4);
	printf("Do you want sort the circles by radius or by center?\n");
	printf("\t %d for by radius\n", SORT_BY_RADIUS);
        printf("\t %d for by center\n", SORT_BY_CENTER);
	scanf("%d", &sortingMethod);
	sortCircles(A, 4, sortingMethod);
	printCircles(A, 4);
	return 0;
}


void swapCircles(CIRCLE *pCircleA, CIRCLE *pCircleB)
{
    CIRCLE temp = *pCircleA;
    *pCircleA = *pCircleB;
    *pCircleB = temp;
}

/*******

The function below specifies the rule of sorting via the input parameter "sortingMethod", 
which  takes value SORT_BY_RADIUS or SORT_BY_CENTER  

*******/
int shouldCircleAPrecedeCircleB(CIRCLE A, CIRCLE B, int sortingMethod) {
    if (sortingMethod == SORT_BY_RADIUS) {
        return A.radius < B.radius;
    } else if (sortingMethod == SORT_BY_CENTER) {
        double distanceASquared = A.center.x * A.center.x + A.center.y * A.center.y;
        double distanceBSquared = B.center.x * B.center.x + B.center.y * B.center.y;
        return distanceASquared < distanceBSquared;
    }
    return 0;
}



void sortCircles(CIRCLE *pCircles, int numCircles, int sortingMethod) {
    for (int i = 0; i < numCircles - 1; i++) {
        for (int j = i + 1; j < numCircles; j++) {
            if (!shouldCircleAPrecedeCircleB(pCircles[i], pCircles[j], sortingMethod)) {
                swapCircles(&pCircles[i], &pCircles[j]);
            }
        }
    }
}

void printCircles(CIRCLE *pCircles, int numCircles)
{
    printf("Circles:\n");
    for (int i = 0; i < numCircles; i++) {
        printf("Circle %d: Center = (%.2f, %.2f), Radius = %.2f\n", 
               i + 1, pCircles[i].center.x, pCircles[i].center.y, pCircles[i].radius);
    }
}

void getCirclesFromUser(CIRCLE *pCircles, int numCircles)
{
    for (int i = 0; i < numCircles; i++) {
        printf("Enter the x-coordinate, y-coordinate, and radius of circle %d: ", i + 1);
        scanf("%lf %lf %lf", &pCircles[i].center.x, &pCircles[i].center.y, &pCircles[i].radius);
    }
}
