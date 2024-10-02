#include <stdio.h>

int main()
{

    int a=0;
    int b;

    int i;
    for (i=0; i<10; i++)
    {
        
        printf("Enter a 1 or 0\n");
        scanf("%d", &b);
        
        if (b==1)
            a++;
    }

    printf("The number of 1's is %d", a);
    return 0;

}