#include <stdio.h>

float CAD;

int main()
{

    printf("Enter the amount of dollars in CAD that you want converted to USD:\n");
    scanf("%f",&CAD);
    
    float USD=CAD*0.74;
    printf("%.2f CAD is %.2f in USD.",CAD, USD);
}