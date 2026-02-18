#include <stdio.h>

int q[100], f = 0, r = -1; // Simple Queue Variables

void enqueue(int val) { q[++r] = val; }
int dequeue() { return q[f++]; }

// The Recursive Function
void reverse() {
    if (f > r) return; // Stop if empty

    int val = dequeue(); // 1. Remove front
    reverse();           // 2. Recurse
    enqueue(val);        // 3. Add to back
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    
    reverse(); // 10, 20, 30 becomes 30, 20, 10

    printf("Reversed: ");
    for(int i = f; i <= r; i++) printf("%d ", q[i]);
    
    return 0;
}