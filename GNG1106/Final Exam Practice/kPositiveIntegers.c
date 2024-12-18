#include <stdio.h>

int sumKIntegers(int k){
    int sum = 0;
    int num, i;
    for(i=0; i<k; i++){
        printf("Enter integer number %d to be entered: ", i+1);
        scanf("%d", &num);

        while(num<0){
            printf("Invalid input, please enter a positive input:");
            scanf("%d, &num");
        }
        sum += num;
    }
    return sum;
}

int main()
{

    int k;

    printf("Enter number of positive integers to be summed:");
    scanf("%d", &k);
    
    while (k<=0){
        printf("Number entered invalid, please enter positive whole number:");
        scanf("%d", &k);
    }

    int result = sumKIntegers(k);

    printf("The sum of the %d positive integers is: %d\n", k, result);

    return 0;
}

