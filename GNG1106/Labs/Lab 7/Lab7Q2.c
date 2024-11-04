#include <stdio.h>

#define N 100

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 20 == 0) {
            printf("\n");
        }
    }
}

void circularShiftLeft(int arr[], int n, int s) {
    int shift = s % n; 
    int temp[shift];

    for (int i = 0; i < shift; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < n - shift; i++) {
        arr[i] = arr[i + shift];
    }

    for (int i = 0; i < shift; i++) {
        arr[n - shift + i] = temp[i];
    }
}

int main() {
    int array[N];
    int s;

    for (int i = 0; i < N; i++) {
        array[i] = i + 1;
    }

    printf("Enter the number of circular left shifts: ");
    scanf("%d", &s);

    circularShiftLeft(array, N, s);

    printArray(array, N);

    return 0;
}
