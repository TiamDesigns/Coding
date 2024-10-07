#include <stdio.h>

int main()
{
    
    int x;
    int i=0;
    scanf("%d", &x);
    while (i<4)
    {
        switch(x%5)
        {
            case 0:
                x=x+6;
                break;
            case 1:
                x=x+7;
                break;
            case 2:
                x=x+8;
                break;
            default:
                x=x%3;
        }
        i++;
    }
    printf("%d\n", x);
    return 0;

}