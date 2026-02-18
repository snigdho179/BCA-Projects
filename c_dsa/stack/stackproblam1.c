#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Simple Stack for Strings
char stack[20][20];
int top = -1;

void push(char *str) {
    top++;
    strcpy(stack[top], str);
}

char* pop() {
    return stack[top--];
}

int main() {
    char prefix[20], op1[20], op2[20], temp[40];
    int len, i;

    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    len = strlen(prefix);

    // Scan from Right to Left using a pointer
    for (i = len - 1; i >= 0; i--) {
        char symbol = prefix[i];
        char strSymbol[2] = {symbol, '\0'}; // Convert char to string

        // If operand, push to stack
        if (isalnum(symbol)) {
            push(strSymbol);
        }
        // If operator, pop two, combine, and push
        else {
            strcpy(op1, pop());
            strcpy(op2, pop());
            
            // Format: op1 + op2 + operator
            strcpy(temp, op1);
            strcat(temp, op2);
            strcat(temp, strSymbol);
            
            push(temp);
        }
    }

    printf("Postfix Expression: %s\n", pop());
    return 0;
}