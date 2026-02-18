#include <stdio.h>

int binarySearch(int *arr, int n, int key) {
    int *low = arr;          // Pointer to start
    int *high = arr + n - 1; // Pointer to end
    int *mid;

    while (low <= high) {
        // Calculate middle address
        mid = low + (high - low) / 2;

        if (*mid == key)
            return (mid - arr); // Found
        else if (*mid < key)
            low = mid + 1;      // Move low pointer
        else
            high = mid - 1;     // Move high pointer
    }
    return -1;
}

int main() {
    // Array must be sorted for Binary Search
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int key = 40;

    int index = binarySearch(arr, n, key);

    if (index != -1)
        printf("Element found at index: %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}