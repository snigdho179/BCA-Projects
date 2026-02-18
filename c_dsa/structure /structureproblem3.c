#include <stdio.h>
#include <string.h>

struct WordStat {
    char word[50];
    int count;
};

int main() {
    char paragraph[1000];
    char currentWord[50];
    struct WordStat list[100];
    int unique_count = 0;
    int i, j, k = 0;
    int found;

    // 1. Input
    printf("Enter a paragraph: ");
    scanf("%[^\n]", paragraph); // Reads the whole line

    // 2. We add a space at the end to force the last word to be processed
    strcat(paragraph, " "); 

    // 3. Loop through the paragraph character by character
    for (i = 0; paragraph[i] != '\0'; i++) {
        
        // If the character is NOT a space, comma, or dot, we build the word
        if (paragraph[i] != ' ' && paragraph[i] != ',' && paragraph[i] != '.') {
            currentWord[k] = paragraph[i]; // Add letter to current word
            k++;                           // Move to next slot
        } 
        else {
            // We hit a separator (space/comma/dot). The word is finished!
            if (k > 0) { // Only process if we actually have a word
                currentWord[k] = '\0'; // End the string properly

                // Check if this word is already in our list
                found = 0;
                for (j = 0; j < unique_count; j++) {
                    if (strcmp(list[j].word, currentWord) == 0) {
                        list[j].count++; // Found it! Increase count
                        found = 1;
                        break;
                    }
                }

                // If it's a new word, add it to the list
                if (found == 0) {
                    strcpy(list[unique_count].word, currentWord);
                    list[unique_count].count = 1;
                    unique_count++;
                }

                // Reset 'k' to start building the next word
                k = 0; 
            }
        }
    }

    // 4. Output
    printf("\nWord Frequency:\n");
    for (i = 0; i < unique_count; i++) {
        printf("%s: %d\n", list[i].word, list[i].count);
    }

    return 0;
}