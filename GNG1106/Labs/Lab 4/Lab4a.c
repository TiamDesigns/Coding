#include <stdio.h>

int main()
{
    
    int a, b;
    char op;

    printf("Enter an integer arithmetic expression involving a single operation (leave no space)\n");
    scanf("%d%c%d", &a, &op, &b);
    switch(op)
    {

        case '+':
            printf("Result: %d\n", a + b);
            break;
        case '-':
            printf("Result: %d\n", a - b);
            break;
        case '*':
            printf("Result: %d\n", a * b);
            break;
        case '/':
            if (b != 0)
                printf("Result: %d\n", a / b);  
            else
                printf("Error: Division by zero is not allowed.\n");
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;

    }

    return 0;
    
}