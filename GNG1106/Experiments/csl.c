void cyclicShift(int *arr, int length) {
    if (length <= 1) {
        return;
    }

    int last = arr[length - 1];


    for (int i = length - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = last; 
}