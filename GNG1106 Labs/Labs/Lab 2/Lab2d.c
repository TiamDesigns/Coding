#include <stdio.h>

//int width; //initialize variable for rectangle width
//int length; //initialize variable for rectangle length
//float width, length; //float variables for length and width
double width, length; //double type variables for length and width

int main()
{
    printf("Please enter the length then width of the rectangle in centimeters. (Integer only)\n"); //prompt user to enter data for variable length
    scanf("%lf, %lf", &length, &width); //scan for user input for variable length and width
    //scanf("%lf", &length); //scan for user input for variable length 
    //scanf("%lf", &width); //scan for user input for variable length 

    printf("Ah, the length and width of the rectangle are %.1lf and %.1lf respectively.\n", length, width);
    //printf("and %.1lf respectively.\n", width);

    //double perimeter = 2*(length+width); 
    //printf("The perimeter of the rectangle is %.1lf centimeters.\n", perimeter);

    return 0;
}