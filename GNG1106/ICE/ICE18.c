#include <stdio.h>

int main() {
    FILE *file;
    int number, count = 0;

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &number) != EOF) {
        if (number % 17 == 0) {
            count++;
        }
    }


    fclose(file);

    printf("multiples of 17: %d\n", count);

    return 0;

    //40 multiples of 17
}