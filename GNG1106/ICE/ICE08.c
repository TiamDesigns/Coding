#include <stdio.h>

int main()
{

    int i=0, N=0;
    scanf("%d%d", &i, &N);
    while (i<N)
    {
       i++;
       N=N-2;
    }
    printf("%d\n",i);
    return 0;

}