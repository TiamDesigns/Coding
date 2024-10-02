#include <stdio.h>

int main()
{

    int a=0;
    int b;

    int i;
    for (i=0; i<10; i++)
    {
        
        printf("Enter a positive integer\n");
        scanf("%d", &b);
        
        if (b%2==0)
            a++;
    }

    printf("The number of even integers is %d", a);
    return 0;

}