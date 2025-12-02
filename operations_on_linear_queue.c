//7.1
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1, size;
int isEmpty() {
    return (front == -1 || front > rear);
}
int isFull() {
    return (rear == size - 1);
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = value;
    printf("%d inserted into the queue.\n", value);
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No element to delete.\n");
        return;
    }
    printf("Element deleted: %d\n", queue[front]);
    front++;
    if (front > rear) { 
        front = rear = -1;
    }
}
void traverse() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int choice, value;

    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    if (size > MAX) {
        printf("Size exceeds maximum limit (%d).\n", MAX);
        return 0;
    }

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                if (isEmpty())
                    printf("Queue is Empty.\n");
                else
                    printf("Queue is not Empty.\n");
                break;

            case 4:
                if (isFull())
                    printf("Queue is Full.\n");
                else
                    printf("Queue is not Full.\n");
                break;

            case 5:
                traverse();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
