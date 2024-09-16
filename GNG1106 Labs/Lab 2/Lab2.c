#include <stdio.h>

int width; //initialize variable for rectangle width
int length; //initialize variable for rectangle length

int main()
{
    printf("Please enter the length of the rectangle in centimeter (Integer only)\n"); //prompt user to enter data for variable length
    scanf("%d", &length); //scan for user input for variable length 

    printf("Please enter the width of the rectangle in centimeter (Integer only)\n"); //prompt user to enter data for variable width
    scanf("%d", &width); //scan for user input for variable width

    printf("Ah, the length and width of the rectangle are %d ", length);
    printf("and %d respectively.\n", width);
    
    return 0;
}