//8.1
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int deque[MAX];
int left = -1, right = -1;
int isFull() {
    return ((left == 0 && right == MAX - 1) || (left == right + 1));
}
int isEmpty() {
    return (left == -1);
}
void insertRight(int item) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }
    if (left == -1) {
        left = 0;
        right = 0;
    } else if (right == MAX - 1) {
        right = 0;
    } else {
        right++;
    }
    deque[right] = item;
}
void insertLeft(int item) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }
    if (left == -1) {
        left = 0;
        right = 0;
    } else if (left == 0) {
        left = MAX - 1;
    } else {
        left--;
    }
    deque[left] = item;
}
void deleteLeft() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("%d deleted\n", deque[left]);
    if (left == right) {
        left = right = -1;
    } else if (left == MAX - 1) {
        left = 0;
    } else {
        left++;
    }
}
void deleteRight() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("%d deleted\n", deque[right]);
    if (left == right) {
        left = right = -1;
    } else if (right == 0) {
        right = MAX - 1;
    } else {
        right--;
    }
}
void display() {
    int i;
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque: ");
    i = left;
    while (1) {
        printf("%d ", deque[i]);
        if (i == right)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, item, type;

    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    printf("Enter your choice: ");
    scanf("%d", &type);

    if (type == 1) {
        do {
            printf("\nInput Restricted Deque Menu\n");
            printf("1. Insert at right\n");
            printf("2. Delete from left\n");
            printf("3. Delete from right\n");
            printf("4. Display\n");
            printf("5. Quit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter element: ");
                    scanf("%d", &item);
                    insertRight(item);
                    break;
                case 2:
                    deleteLeft();
                    break;
                case 3:
                    deleteRight();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    exit(0);
                default:
                    printf("Invalid choice!\n");
            }
        } while (1);
    }

    else if (type == 2) {
        do {
            printf("\nOutput Restricted Deque Menu\n");
            printf("1. Insert at right\n");
            printf("2. Insert at left\n");
            printf("3. Delete from left\n");
            printf("4. Display\n");
            printf("5. Quit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter element: ");
                    scanf("%d", &item);
                    insertRight(item);
                    break;
                case 2:
                    printf("Enter element: ");
                    scanf("%d", &item);
                    insertLeft(item);
                    break;
                case 3:
                    deleteLeft();
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    exit(0);
                default:
                    printf("Invalid choice!\n");
            }
        } while (1);
    }

    else {
        printf("Invalid Deque type selected!\n");
    }

    return 0;
}
