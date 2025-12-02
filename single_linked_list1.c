//4.1
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void createList(int n) 
{
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) return;

    for (i = 0; i < n; i++) 
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) 
        {
            head = newNode;
        } 
        else 
        {
            temp = head;
            while (temp->next != NULL) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}
void traverse() 
{
    struct Node *temp = head;
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    printf("The list is: ");
    while (temp != NULL) 
    {
        printf("%d", temp->data);
        if (temp->next != NULL) printf("-> ");
        temp = temp->next;
    }
    printf("\n");
}
void countNodes() 
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    printf("The total number of nodes: %d\n", count);
}
void insertAtPosition(int data, int position) 
{
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) 
    {
        newNode->next = head;
        head = newNode;
        printf("Node inserted\n");
        return;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Invalid position!\n");
        free(newNode);
    } 
    else 
    {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted\n");
    }
}
void deleteFromPosition(int position) 
{
    struct Node *temp = head, *prev;
    int i;

    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }

    if (position == 1) 
    {
        head = head->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }

    for (i = 1; i < position && temp != NULL; i++) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Invalid position!\n");
    } 
    else 
    {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted\n");
    }
}

int main() 
{
    int n, choice, data, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);

    do {
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traversal\n");
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
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteFromPosition(pos);
            break;
        case 3:
            countNodes();
            break;
        case 4:
            traverse();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } 
    while (choice != 5);
    return 0;
}
