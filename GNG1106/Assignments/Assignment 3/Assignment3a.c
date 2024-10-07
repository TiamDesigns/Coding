#include <stdio.h>

int main()
{

    int a, b;

    printf("Enter an integer\n");
    scanf("%d", &a);

    int i;
    for (i=0; i<10; i++)
    {
        
        printf("Enter an integer\n");
        scanf("%d", &b);
        
        if (b<a)
            a=b;
    }

    printf("The smallest integer is %d", a);
    return 0;

}