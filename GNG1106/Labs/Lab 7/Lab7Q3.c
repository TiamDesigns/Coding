#include <stdio.h>

#define N 100

void get_s(int *s) {
    printf("Enter the number of circular left shifts: ");
    scanf("%d", s);
}

void CSL(int *a, int *s) {
    int shift = *s % N; 
    int temp[shift];

    for (int i = 0; i < shift; i++) {
        temp[i] = a[i];
    }

    for (int i = 0; i < N - shift; i++) {
        a[i] = a[i + shift];
    }

    for (int i = 0; i < shift; i++) {
        a[N - shift + i] = temp[i];
    }
}

void prtArray(int *a) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 20 == 0) {
            printf("\n");
        }
    }
}

int main() {
    int array[N];
    int s;

    for (int i = 0; i < N; i++) {
        array[i] = i + 1;
    }

    get_s(&s);
    CSL(array, &s);
    prtArray(array);

    return 0;
}
