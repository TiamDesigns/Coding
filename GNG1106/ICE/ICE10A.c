#include <stdio.h>

void dec(int x)
{
    x--;
}

int main()
{

   int x;
   scanf("%d", &x);
   x=x%8;
   dec(x);
   printf("%d\n", x);
   return 0;

}