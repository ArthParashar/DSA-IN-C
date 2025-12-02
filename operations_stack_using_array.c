//6.1
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX]; 
int top = -1;
void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", element);
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed into stack.\n", element);
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("%d deleted from Stack\n", stack[top]);
        top--;
    }
}
void isEmpty() {
    if (top == -1)
        printf("Stack empty: True\n");
    else
        printf("Stack empty: False\n");
}
void isFull() {
    if (top == MAX - 1)
        printf("Stack full: True\n");
    else
        printf("Stack full: False\n");
}
void traverse() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice, element;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to be pushed into the stack: ");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            pop();
            break;

        case 3:
            isEmpty();
            break;

        case 4:
            isFull();
            break;

        case 5:
            traverse();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}