#include <stdio.h>

float num1, num2;

int main()
{

    printf("Enter an interger:\n");
    scanf("%f", &num1);

    printf("Enter a second integer:\n");
    scanf("%f", &num2);

    float product = num1 * num2;
    printf("The product of the two integers is %.2f.\n", product);
}