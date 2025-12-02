//4.2
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
        if (temp->next != NULL) printf("->");
        temp = temp->next;
    }
    printf("\n");
}
void searchElement(int key) 
{
    struct Node *temp = head;
    int pos = 1, found = 0;

    while (temp != NULL) 
    {
        if (temp->data == key) 
        {
            printf("Element found at node-%d\n", pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) 
    {
        printf("Element not found in the list.\n");
    }
}

void sortList() 
{
    struct Node *i, *j;
    int temp;

    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) 
    {
        for (j = i->next; j != NULL; j = j->next) 
        {
            if (i->data > j->data) 
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
    traverse();
}
void reverseList() 
{
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) 
    {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;        
    }
    head = prev;

    printf("Reverse list: ");
    traverse();
}
int main() 
{
    int n, choice, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    createList(n);

    do {
        printf("\nMENU:\n");
        printf("1. Traverse\n");
        printf("2. Search\n");
        printf("3. Sort\n");
        printf("4. Reverse\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            traverse();
            break;
        case 2:
            printf("Enter element to be searched: ");
            scanf("%d", &key);
            searchElement(key);
            break;
        case 3:
            sortList();
            break;
        case 4:
            reverseList();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
