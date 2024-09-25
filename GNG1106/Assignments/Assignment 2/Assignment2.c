#include <stdio.h>

int main()
{
    int x,y,z;
    printf("Enter 3 different integers seperated by colons (x,y,z):");
    scanf("%d,%d,%d", &x, &y, &z);

    if (x == y || y == z || x == z)
        {
            printf("Wrong input.\n");
        } 
        
        else {
            if (x>y && x>z){
                printf("The largest number is %d.\n", x);
            } else if (y>x && y>z) {
                printf("The largest number is %d.\n", y);
            } else {
                printf("The largest number is %d.\n", z);
            }
        }
    return 0;
}