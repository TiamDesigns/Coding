#include <stdio.h>

//int width; //initialize variable for rectangle width
//int length; //initialize variable for rectangle length
float width, length; //float variables for length and width

int main()
{
    printf("Please enter the length then width of the rectangle in centimeters. (Integer only)\n"); //prompt user to enter data for variable length
    scanf("%f, %f", &length, &width); //scan for user input for variable length and width
    //scanf("%f", &length); //scan for user input for variable length 
    //scanf("%f", &width); //scan for user input for variable length 

    printf("Ah, the length and width of the rectangle are %.1f ", length);
    printf("and %.1f respectively.\n", width);
    
    return 0;
}