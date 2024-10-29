#include <stdio.h>

void swapHeadTail(int arr[], int length) {
    if (length > 1) { 
        int temp = arr[0];
        arr[0] = arr[length - 1];
        arr[length - 1] = temp;
    }
}

int main() {
    int a[4] = {1, 2, 3, 4};
    int b[5] = {10, 20, 30, 40, 50};

    swapHeadTail(a, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    swapHeadTail(b, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}