#include <stdio.h>

int main()
{

    int x,y;
    scanf("%d,%d", &x, &y);
    if (x>=0)
        if (y>=0)
            if (y>=-x+3)
                printf("1\n");
            else
                printf("2\n");
        else    
            if (y>=x-3)
                printf("3\n");
            else
                printf("4\n");

    else
        if (y>=0)
            if (y>=x+3)
                printf("5\n");
            else
                printf("6\n");
        else
            if (y>=-x-3)
                printf("7\n");
            else
                printf("8\n");

    return 0;

}