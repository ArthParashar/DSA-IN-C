//6.2
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
int isEmpty() {
    return top == NULL;
}
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow! Cannot insert.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into the stack.\n", value);
}
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! No element to delete.\n");
        return;
    }
    struct Node* temp = top;
    printf("%d deleted from Stack\n", top->data);
    top = top->next;
    free(temp);
}
void traverse() {
    if (isEmpty()) {
        printf("Stack is Empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, value;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                if (isEmpty())
                    printf("Stack is Empty.\n");
                else
                    printf("Stack is not Empty.\n");
                break;

            case 4:
                traverse();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
