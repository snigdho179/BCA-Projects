#include<stdio.h>

struct matrix {
    int row;
    int col;
    int val;
};

int main() {
    struct matrix a[20], b[20], result[100];
    int r1, c1, r2, c2, i, j, n1, n2;
    int k = 0; // Counter for result array
    int tempGrid[20][20] = {0}; // Helper grid initialized to 0

    // --- Inputs are fine, keep them same ---
    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter number of non-zero elements in Matrix 1: ");
    scanf("%d", &n1);
    printf("Enter elements (Row Col Value):\n");
    for (i = 0; i < n1; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
    }

    printf("\nEnter rows and columns for Matrix 2: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter number of non-zero elements in Matrix 2: ");
    scanf("%d", &n2);
    printf("Enter elements (Row Col Value):\n");
    for (i = 0; i < n2; i++) {
        scanf("%d %d %d", &b[i].row, &b[i].col, &b[i].val);
    }

    if (c1 != r2) {
        printf("Multiplication not possible (Cols of A != Rows of B)\n");
        return 0;
    }

    // --- 4. CORRECTED LOGIC ---
    
    // Step A: Do the math using a simple grid
    // We loop through the LIST of items (0 to n1, 0 to n2)
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            
            // Check if Column of A == Row of B
            if (a[i].col == b[j].row) {
                // Determine the position in the final matrix
                int r = a[i].row;
                int c = b[j].col;
                
                // Add to the grid accumulator
                tempGrid[r][c] += a[i].val * b[j].val;
            }
        }
    }

    // Step B: Convert the grid back to your 'result' structure
    // We scan the grid to find non-zero answers
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            if (tempGrid[i][j] != 0) {
                result[k].row = i;
                result[k].col = j;
                result[k].val = tempGrid[i][j];
                k++; // Move to next slot in result array
            }
        }
    }

    // --- 5. Output ---
    printf("\nResult of Matrix Multiplication (Row Col Value):\n");
    for (i = 0; i < k; i++) { // Loop up to k (the number of results found)
        printf("%d %d %d\n", result[i].row, result[i].col, result[i].val);
    }

    return 0;
}