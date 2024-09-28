#include <stdio.h>

int main()
{

    int count = 0;
    int last, current;

    printf("Enter integer 1: ");
    scanf("%d", &last);

    for (int i = 2; i <= 15; i++) {
        printf("Enter integer %d: ", i);
        scanf("%d", &current);

        if (last % 2 == 0 && current % 2 != 0)
        {
            count++;
        }

        last = current;
    }

    printf("The number of times an odd number followed an even number is: %d\n", count);

    return 0;
}