

#include <stdio.h>

int x;

int main()
{

    printf("Please input an integer:\n");
    scanf("%d", &x);
    
    int v = x % 2;

    if (v == 0)
    {
        printf("Even,");
        if (v == 0)
            printf("and divisible by 4.");
    }

    else
        printf("Odd");
    
}