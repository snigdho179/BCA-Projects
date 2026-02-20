#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n) {
    int i;
    int *ptr; 

    for (i = 0; i < n - 1; i++) {
        // Pointer 'ptr' points to the start of the array
        // We stop at (arr + n - 1 - i) because the last 'i' elements are already sorted
        for (ptr = arr; ptr < arr + n; ptr++) {
            
            // Compare value at ptr with value at next address (ptr+1)
            if (*ptr > *(ptr + 1)) {
                swap(ptr, ptr + 1);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    bubbleSort(arr, n);

    printf("Bubble Sorted: ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
    
    return 0;
}