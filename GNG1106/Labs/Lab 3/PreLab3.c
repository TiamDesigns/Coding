#include <stdio.h>

int x,y; 

int main()
{

    printf("Enter an integer:\n");
    scanf("%d", &x);

    printf("Enter a second integer:\n");
    scanf("%d", &y);

    if (x == y)
        printf("Wrong input.\n");
        else
            if (x < y)
                printf("The smaller number is: %d\n", x);
                else
                    printf("The smaller number is: %d\n", y);  
    
    
    return 0;
}