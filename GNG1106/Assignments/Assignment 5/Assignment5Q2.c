#include <stdio.h>

void inc(int x)
{
    x++;
}

int main()
{
    int x;
    scanf("%d", &x);
    inc(x);
    printf("%d\n", x);
    return 0;
}