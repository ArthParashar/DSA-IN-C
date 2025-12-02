//8.2
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    int priority;
    struct Node *next;
};
struct Node *front = NULL;
struct Node* createNode(int data, int priority) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}
void enqueue(int data, int priority) {
    struct Node *newNode = createNode(data, priority);
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node *temp = front;
        while (temp->next != NULL && temp->next->priority <= priority)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Element %d with priority %d inserted.\n", data, priority);
}
void dequeue() {
    if (front == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }
    struct Node *temp = front;
    printf("Deleted element: %d with priority %d\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}
void display() {
    if (front == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }
    struct Node *temp = front;
    printf("Priority Queue:\n");
    printf("Priority\tItem\n");
    while (temp != NULL) {
        printf("%d\t\t%d\n", temp->priority, temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, data, priority;

    do {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
