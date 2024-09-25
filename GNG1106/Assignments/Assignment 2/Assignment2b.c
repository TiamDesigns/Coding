#include <stdio.h>

int main()
{
    float x,y,z;
    printf("Enter 3 different integers seperated by colons (x,y,z):");
    scanf("%f,%f,%f", &x, &y, &z);

    if (x <= 0 || y <= 0 || z <= 0){
        printf("Wrong input.\n");
    } 
    
    else {
    if ((x + y > z) && (x + z > y) && (y + z > x)) 
        {
            printf("The values can form a triangle.\n");
        } else {
            printf("The values can't form a triangle.\n");
            }
    }
    return 0;
}