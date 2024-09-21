#include <stdio.h>

int main()
{

    int integer;

    printf("Please input an integer:\n");
    scanf("%d", &integer);

    if (integer % 2 == 0)
        printf("Even");

    else
        printf("Odd");
    
    return 0;
}