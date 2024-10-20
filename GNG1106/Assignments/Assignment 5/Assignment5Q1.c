#include <stdio.h>

void printStarsA()
{
    printf("**");
}

void printStarsB()
{
    printf("***");
}

int main()
{
    int i, x;
    scanf("%d", &x);
    for (i=0; i<x; i++)
    {
        printStarsA();
        printStarsB();
        printStarsA();
    }
    printf("\n");
    return 0;
}