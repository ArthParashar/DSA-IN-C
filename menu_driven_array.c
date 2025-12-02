//2.1
#include <stdio.h>
void insertElement(int arr[], int *n, int element, int pos) 
{
    if (pos < 0 || pos > *n) 
    {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i > pos; i--) 
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*n)++;
    printf("Element inserted successfully.\n");
    traverseArray(arr, *n); 
}
void deleteElement(int arr[], int *n, int pos) 
{
    if (pos < 0 || pos >= *n) 
    {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted successfully.\n");
    traverseArray(arr, *n);
}
void linearSearch(int arr[], int n, int key) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == key) 
        {
            printf("Element %d found at position %d.\n", key, i);
            return;
        }
    }
    printf("Element %d not found in the array.\n", key);
}
void traverseArray(int arr[], int n) 
{
    if (n == 0) 
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Current Array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() 
{
    int arr[100], n, choice, element, pos, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    do 
    {
        printf("\n---- Menu ----\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Linear Search\n");
        printf("4. Traverse Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert at (0-based index): ");
                scanf("%d", &pos);
                insertElement(arr, &n, element, pos);
                break;

            case 2:
                printf("Enter position to delete from (0-based index): ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                linearSearch(arr, n, key);
                break;

            case 4:
                traverseArray(arr, n);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}