#include <stdio.h>

void main()
{
    int i, j;

    for(i=0; i<5; i=i+1)
    {
        for(j=0; j<3; j=j+1)
            printf("%d", i+j);

        printf("\n");
    }
}
