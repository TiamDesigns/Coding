#include <stdio.h>

int binarySearch(int array[], int size, int key) 
{
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (array[mid] == key)
            return mid; 
        else if (array[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; 

}

int main() 
{
    int array[9], key, result;

    printf("Enter 9 integers in ascending order:\n");
    for (int i = 0; i < 9; i++) {
        scanf("%d", &array[i]);
    }

  
    printf("Enter the number to search for: ");
    scanf("%d", &key);

 
    result = binarySearch(array, 9, key);

   
    if (result != -1)
        printf("Key found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}