#include <stdio.h>

int deque[100];
int f = -1, r = -1; // f = front, r = rear

void insertFront(int val) {
    if (f == -1) { f = 0; r = 0; } // First element
    else f--;                      // Move front back
    deque[f] = val;
}

void insertRear(int val) {
    if (f == -1) { f = 0; r = 0; } // First element
    else r++;                      // Move rear forward
    deque[r] = val;
}

void deleteFront() {
    if (f == -1) return; // Empty
    printf("Deleted Front: %d\n", deque[f]);
    if (f == r) { f = -1; r = -1; } // Reset if empty
    else f++;
}

void deleteRear() {
    if (f == -1) return; // Empty
    printf("Deleted Rear: %d\n", deque[r]);
    if (f == r) { f = -1; r = -1; } // Reset if empty
    else r--;
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5); // Queue: 5, 10, 20
    
    deleteFront();  // Removes 5
    deleteRear();   // Removes 20
    return 0;
}