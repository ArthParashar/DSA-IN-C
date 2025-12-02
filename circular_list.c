//7.3
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int size;
int isEmpty() {
    return (front == -1);
}
int isFull() {
    return ((rear + 1) % size == front);
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Insertion not possible.\n");
        return;
    }

    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    queue[rear] = value;

    printf("Element %d inserted successfully.\n", value);
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Deletion not possible.\n");
        return;
    }

    int deleted = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    printf("Element %d deleted.\n", deleted);
}
void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("CQueue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}
int main() {
    int choice, value;

    printf("Enter Queue size: ");
    scanf("%d", &size);

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
                    printf("Queue Empty: True\n");
                else
                    printf("Queue Empty: False\n");
                break;

            case 4:
                if (isFull())
                    printf("Queue Full: True\n");
                else
                    printf("Queue Full: False\n");
                break;

            case 5:
                traverse();
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
