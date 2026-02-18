#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition using pointers
int* partition(int *low, int *high) {
    int pivot = *high; // Pivot is the last element
    int *i = low - 1;  // Pointer for smaller element
    int *j;

    for (j = low; j < high; j++) {
        if (*j < pivot) {
            i++;
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return (i + 1); // Return pointer to partition index
}

void quickSort(int *low, int *high) {
    if (low < high) {
        int *pi = partition(low, high);

        quickSort(low, pi - 1);  // Sort Left side
        quickSort(pi + 1, high); // Sort Right side
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));

    // Pass address of first and last element
    quickSort(arr, arr + n - 1);

    printf("\nSorted:   ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
    
    return 0;
}