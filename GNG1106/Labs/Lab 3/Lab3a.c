#include <stdio.h>

int x;

int main()
{

    printf("Please input an integer:\n");
    scanf("%d", &x);
    
    int v = x % 2;

    if (v == 0){
        printf("Even");
    }

    else {
        printf("Odd");
    }
}