#include <stdio.h>

void swapHeadTail(int x, int y)
{
    int z;
    z=x;
    x=y;
    y=z;
}

int main()
{

    int a, b;
    printf("Enter int values a and b\n");
    scanf("%d%d", &a, &b);

    swap(a, b);

    printf("a=%d, b=%d", a, b);


    return 0;

}