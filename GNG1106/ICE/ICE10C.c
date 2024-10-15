#include <stdio.h>

void factors(int n) {
    int divisor = 2;
    printf("Prime factors:\n");
    while (n > 1) {
        while (n % divisor == 0) {
            printf("%d    ", divisor);
            n /= divisor;
        }
        divisor++;
    }
    printf("\n");
}

int integer() {
    int num;
    do {
        printf("Enter an integer greater than 1: ");
        scanf("%d", &num);
        if (num <= 1) {
            printf("The number must be greater than 1. Please try again.\n");
        }
    } while (num <= 1);
    
    return num;
}

int main() {
    int num = integer();
    factors(num);
    return 0;
}