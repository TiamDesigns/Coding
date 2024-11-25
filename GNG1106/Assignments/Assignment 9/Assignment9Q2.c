#include <stdio.h>

typedef struct
{
    char string1[6];
    char *string2;
} STRING_PAIR;

void printStringPair(STRING_PAIR x)
{
    printf("(%s, %s)\n", x.string1, x.string2);
}

void foo(STRING_PAIR A)
{
    A.string1[0] = 'R';
    A.string2[1] = 'i';
}

void boo(STRING_PAIR *A)
{
    A->string1[0] = 'R';
    A->string2[1] = 'i';
}

int main()
{
    char x[6] = "hot";
    STRING_PAIR A = {"Bob", x};
    boo(&A);
    printStringPair(A);
    return 0;
}
