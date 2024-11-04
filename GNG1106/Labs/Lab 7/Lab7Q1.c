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

void circularShiftLeft(int arr[], int n) {
    int first = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = first;
}

int main() {
    int array[N];
    
    for (int i = 0; i < N; i++) {
        array[i] = i + 1;
    }

    circularShiftLeft(array, N);
    
    printArray(array, N);

    return 0;
}
