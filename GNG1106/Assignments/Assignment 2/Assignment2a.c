#include <stdio.h>

int main()
{

    int grade;
    printf("Input a percentage grade:\n");
    scanf("%d", &grade);
    printf("The percentage %d is the letter grade: ", grade);

    if (grade >= 90 && grade <= 100) {
        printf("A+\n");
    } else if (grade >= 85 && grade < 90) {
        printf("A\n");
    } else if (grade >= 80 && grade < 85) {
        printf("A-\n");
    } else if (grade >= 75 && grade < 80) {
        printf("B+\n");
    } else if (grade >= 70 && grade < 75) {
        printf("B\n");
    } else if (grade >= 65 && grade < 70) {
        printf("C+\n");
    } else if (grade >= 60 && grade < 65) {
        printf("C\n");
    } else if (grade >= 55 && grade < 60) {
        printf("D+\n");
    } else if (grade >= 50 && grade < 55) {
        printf("D\n");
    } else if (grade >= 40 && grade < 50) {
        printf("E\n");
    } else if (grade >= 0 && grade < 40) {
        printf("F\n");
    } else {
        printf("Invalid percentage.");
    }


}