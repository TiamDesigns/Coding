#include <stdio.h>

int main()
{
    int i;

    printf("Enter a positive integer:");
    scanf("%d", &i);

    for (; i>0; i--)
    {
        for (int x=0; x<i; x++)
        {
            printf("o");
        }
        printf("\n");
    }

    return 0;

}