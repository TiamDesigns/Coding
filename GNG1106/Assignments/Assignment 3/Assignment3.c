#include <stdio.h>

int main()
{

    int a=0, b=0, c=0;
    int i;
    for (i=0; i<5; i++)
    {
        printf("Enter an integer\n");
        scanf("%d", &b);
        c=a+b;
        printf("c=%d\n", c);
        a=b;
    }

    return 0;

}