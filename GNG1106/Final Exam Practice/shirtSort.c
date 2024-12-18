#include <stdio.h>

// Define the structure SHIRT
typedef struct {
    char brand[256];
    float size;
    float price;
    float customerRating;
} SHIRT;

// Function to compare the prices of two shirts
int isACheaperThanB(SHIRT A, SHIRT B) {
    return A.price < B.price ? 1 : 0; // Returns 1 if A is cheaper, otherwise 0
}

// Function to perform replacement sort on the array of SHIRT structures
void replacementSortShirts(SHIRT *pointer2shirts, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the current element is the smallest
        int minIndex = i;

        // Find the smallest price in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (isACheaperThanB(pointer2shirts[j], pointer2shirts[minIndex])) {
                minIndex = j;
            }
        }

        // Swap the current element with the smallest element found
        if (minIndex != i) {
            SHIRT temp = pointer2shirts[i];
            pointer2shirts[i] = pointer2shirts[minIndex];
            pointer2shirts[minIndex] = temp;
        }
    }
}

// Example usage
int main() {
    // Example array of SHIRT structures
    SHIRT shirts[] = {
        {"BrandA", 40.0, 19.99, 4.5},
        {"BrandB", 38.0, 29.99, 4.0},
        {"BrandC", 42.0, 9.99, 3.8},
        {"BrandD", 41.0, 14.99, 4.2},
        {"BrandE", 39.0, 24.99, 4.6}
    };
    int n = sizeof(shirts) / sizeof(shirts[0]);

    // Sort the shirts array
    replacementSortShirts(shirts, n);

    // Print sorted shirts
    printf("Sorted shirts by price:\n");
    for (int i = 0; i < n; i++) {
        printf("Brand: %s, Size: %.2f, Price: %.2f, Rating: %.1f\n",
               shirts[i].brand, shirts[i].size, shirts[i].price, shirts[i].customerRating);
    }

    return 0;
}
