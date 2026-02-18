#include <stdio.h>

int linearSearch(int *arr, int n, int key) {
    int *ptr;
    // Iterate using a pointer from the start to the end of the array
    for (ptr = arr; ptr < arr + n; ptr++) {
        if (*ptr == key) {
            // Return the index (current address - base address)
            return (ptr - arr); 
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 50, 30, 70, 80, 20};
    int n = 6;
    int key = 30;
    
    int index = linearSearch(arr, n, key);
    
    if (index != -1)
        printf("Element found at index: %d\n", index);
    else
        printf("Element not found\n");
        
    return 0;
}