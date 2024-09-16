#include <stdio.h>

int width; //initialize variable for rectangle width
int length; //initialize variable for rectangle length

int main()
{
    printf("Please enter the length then width of the rectangle in centimeters. (Integer only)\n"); //prompt user to enter data for variable length
    //scanf("%d, %d", &length, &width); //scan for user input for variable length and width
    scanf("%d", &length); //scan for user input for variable length 
    scanf("%d", &width); //scan for user input for variable length 

    printf("Ah, the length and width of the rectangle are %d ", length);
    printf("and %d respectively.\n", width);
    
    return 0;
}