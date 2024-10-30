#include <stdio.h>

int main()
{
    int A[7] = {11, 12, 13, 14, 15, 16, 17};
    int x, i;

    // Reverse the array
    for (i = 0; i < 3; i++)
    {
        x = A[i];
        A[i] = A[6 - i];
        A[6 - i] = x;
    }

    // Print the array
    for (i = 0; i < 7; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}