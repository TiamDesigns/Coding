#include <stdio.h>

int main()
{
    int number, digits[5];
    printf("Enter a five-digit integer: ");
    scanf("%d", &number);

    if (number < 10000 || number > 99999)
    {
        printf("Please enter a valid five-digit integer.\n");
        return 1;
    }

    digits[0] = number / 10000;
    digits[1] = (number / 1000) % 10;
    digits[2] = (number / 100) % 10;
    digits[3] = (number / 10) % 10;
    digits[4] = number % 10;    

    if (digits[0] == digits[4] && digits[1] == digits[3])
    {
        printf("The number %d is a palindrome.\n", number);
    }
    else
    {
        printf("The number %d is not a palindrome.\n", number);
    }

    return 0;
}