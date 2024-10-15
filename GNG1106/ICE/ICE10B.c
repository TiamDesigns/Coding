#include <stdio.h>

int joe(int x)
{
    int y;
    y=2*x;
    return y;
}

int main()
{

   int x;
   scanf("%d", &x);
   x=x%7;
   printf("%d\n", joe(x));
   return 0;

}