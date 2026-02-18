#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int len1, len2, i, j, found = 0;

    // 1. Input: We use gets() or scanf to read the strings
    // Note: checking for [^\n] allows us to read strings with spaces
    printf("Enter the main string (S1): ");
    scanf(" %[^\n]", s1); 

    printf("Enter the substring to find (S2): ");
    scanf(" %[^\n]", s2);

    len1 = strlen(s1);
    len2 = strlen(s2);

    printf("\nResults:\n");

    // 2. The Outer Loop (i): slides the starting window across S1
    for (i = 0; i <= len1; i++) {
        
        // 3. The Inner Loop (j): compares character by character
        for (j = 0; j < len2; j++) {
            if (s1[i + j] != s2[j]) {
                break; // Mismatch found, stop checking this spot
            }
        }

        // 4. If the inner loop finished completely, we found a match
        if (j == len2) {
            printf("Found occurrence! Start: %d, End: %d\n", i, i + len2 - 1);
            found = 1; // Mark that we found at least one
        }
    }

    if (found == 0) {
        printf("Substring not found.\n");
    }

    return 0;
}