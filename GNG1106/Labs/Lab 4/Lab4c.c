#include <stdio.h>

int main()
{
    
    float a, b;
    char op;

    printf("Enter an integer arithmetic expression involving a single operation (leave no space)\n");
    scanf("%f%c%f", &a, &op, &b);
    switch(op)
    {

        case '+':
            printf("Result: %f\n", a + b);
            break;
        case '-':
            printf("Result: %f\n", a - b);
            break;
        case '*':
            printf("Result: %f\n", a * b);
            break;
        case '/':
            if (b != 0)
                printf("Result: %f\n", a / b);  // Integer division
            else
                printf("Error: a is not divisible by b.\n");
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;

    }

    return 0;
    
}