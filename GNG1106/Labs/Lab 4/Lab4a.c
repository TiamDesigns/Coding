#include <stdio.h>

int main()
{
    
    int x;
    printf("... x:\n");
    scanf("%d", &x);
    if (x<5)
    {
        x=x+5;
        printf("A");
    }
    else if (x<8)
    {
        x=x-2;
        printf("B");
    }
    else 
        printf("C");
    
    if(x>6)
        printf("D");
    printf("\n");
    return 0;


}