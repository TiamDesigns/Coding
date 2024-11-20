#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int rows, cols;
    int currentNumber, largest;

    inputFile = fopen("myData.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d %d", &rows, &cols);

    outputFile = fopen("foundLargest.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating the output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Process each row
    for (int i = 0; i < rows; i++) {
        fscanf(inputFile, "%d", &largest);

        for (int j = 1; j < cols; j++) {
            fscanf(inputFile, "%d", &currentNumber);
            if (currentNumber > largest) {
                largest = currentNumber;
            }
        }

        fprintf(outputFile, "%d\n", largest);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Largest numbers from each row have been written to 'foundLargest.txt'.\n");

    return 0;
}
