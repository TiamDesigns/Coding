#include <stdio.h>

int main() 
{
    int i = 0, num = 0;
    int n1 = 0, n2 = 0, n3 = 0;
    float average = 0.0;

    while (i < 10) {
        printf("Please enter a number: ");
        scanf("%d", &num);
        i++;

        if (i == 1) 
        {
            n1 = num;
        } 

        else if (i == 2) 
        {
            n2 = num;
        } 

        else if (i == 3) 
        {
            n3 = num;
            average = (n1 + n2 + n3) / 3.0;
            printf("The average of the first 3 numbers is: %.2f\n", average);
        }
        
        else 
        {
            n1 = n2;
            n2 = n3;
            n3 = num;

            average = (n1 + n2 + n3) / 3.0;
            printf("The average of the last 3 numbers is: %.2f\n", average);
        }
    }

    return 0;
}