#include <stdio.h>

int main() {
    int i;
    printf("Starting the loop...\n");

    for (i = 1; i <= 10; i++) {
        // If 'i' is 3, skip this iteration and continue to the next
        if (i == 3) {
            printf("Skipping number 3 with continue.\n");
            continue; // Jumps to the next iteration (i=4)
        }

        // If 'i' is 8, terminate the loop entirely
        if (i == 8) {
            printf("Terminating loop with break because i is 8.\n");
            break; // Exits the for loop completely
        }

        printf("Processing number: %d\n", i);
    }

    printf("Loop has finished.\n");
    return 0;
}