#include <stdio.h>

int main()
{

    int integer;

    printf("Please input an integer:\n");
    scanf("%d", &integer);

    if (integer % 2 == 0){
        printf("Even");
        if (integer %4 == 0)
            printf(" and is divisble by 4.\n");
        else 
            printf(" and is not divisible by 4.\n");
    }
    else{
        printf("Odd");
    }
    return 0;
}