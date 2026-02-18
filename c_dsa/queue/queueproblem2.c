#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
} *front = NULL, *rear = NULL;

void insertFront(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = front; n->prev = NULL;
    
    if (front == NULL) rear = n;  // If list was empty
    else front->prev = n;
    front = n;
}

void insertRear(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL; n->prev = rear;
    
    if (rear == NULL) front = n;  // If list was empty
    else rear->next = n;
    rear = n;
}

void deleteFront() {
    if (front == NULL) return;
    struct Node* temp = front;
    printf("Deleted Front: %d\n", front->data);
    
    front = front->next;
    if (front == NULL) rear = NULL; // List became empty
    else front->prev = NULL;
    free(temp);
}

void deleteRear() {
    if (rear == NULL) return;
    struct Node* temp = rear;
    printf("Deleted Rear: %d\n", rear->data);
    
    rear = rear->prev;
    if (rear == NULL) front = NULL; // List became empty
    else rear->next = NULL;
    free(temp);
}

int main() {
    insertRear(10);
    insertFront(5);
    deleteFront();
    deleteRear();
    return 0;
}