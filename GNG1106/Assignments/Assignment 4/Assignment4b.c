#include <stdio.h>

int main()

{

    int a, b=1, c, d, e=0, N;
    scanf("%d%d", &a, &N);
    c=a+b;
    d=a-b;
    while (e<N)
    {
        if (e%2==1)
        {
            a=c;
            c=d;
            d=a;
        }
        else
        {
            c++;
            d--;
        }
        e++;
    }
    printf("%d\n", c);
    return 0;
}