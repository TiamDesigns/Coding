#include <stdio.h>

int main()
{
    int k, i, x=1, y=1, n;

    printf("Enter a whole number value:");
    scanf("%d", &k);
    
    if (k <= 2) 
    {
        printf("Please enter a value greater than 2.\n");
        return 1;
    }

    printf("F1 = %d\n", x);
    printf("F2 = %d\n", y);

    for (i = 3; i<=k; i++)
    {
        n=x+y;
        printf("F%d = %d\n", i, n);
        x = y;
        y = n;
    }

    return 0;
}