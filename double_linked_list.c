#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* head = NULL;
void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }
    head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter element 1: ");
    scanf("%d", &data);
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    temp = head;
    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
    }
}
void insertAtPosition(int data, int pos) {
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        printf("Node inserted\n");
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;

    printf("Node inserted\n");
}
void deleteAtPosition(int pos) {
    struct Node *temp;
    int i;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (pos == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Node deleted\n");
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Node deleted\n");
}

void traverse() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("The list is: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("-> ");
        temp = temp->next;
    }
    printf("\n");
}
int countNodes() {
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}
int main() {
    int n, choice, data, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("The no of nodes are:%d\n",countNodes());
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
