#include <stdio.h>

int main()
{

    int integer;

    printf("Please input an integer:\n");
    scanf("%d", &integer);

     if (integer % 6 == 0) {
        printf("The number is divisible by 6.\n");
    } else if (integer % 2 == 0) {
        printf("The number is divisible by 2 but not divisible by 3.\n");
    } else if (integer % 3 == 0) {
        printf("The number is not divisible by 2 but divisible by 3.\n");
    } else {
        printf("The number is neither divisible by 2 nor divisible by 3.\n");
    }

    return 0;
}
