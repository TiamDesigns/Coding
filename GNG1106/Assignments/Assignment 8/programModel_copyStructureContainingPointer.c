#include <stdio.h>

typedef struct
{
	int a;
	int *b;
}widget;

void printWidget(widget w)
{
	printf("%d, %d\n", w.a, *w.b);
}

int main()
{
	widget A, B;
	int c=2;
	A.a=1;
	A.b=&c;
	B=A;
	B.a=3;
	*B.b=4;
	printWidget(A);
	return 0;
}
