//9.2
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
int findLargest(struct Node *root) {
    if (root == NULL) {
        printf("BST is empty!\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}
int findSmallest(struct Node *root) {
    if (root == NULL) {
        printf("BST is empty!\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}
int height(struct Node *root) {
    if (root == NULL)
        return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int countLeafNodes(struct Node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, value;

    printf("MAIN MENU\n");
    printf("1. Insert\n");
    printf("2. Largest\n");
    printf("3. Smallest\n");
    printf("4. Height\n");
    printf("5. Count leaf nodes\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert in BST: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("BST after insertion (Inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                value = findLargest(root);
                if (value != -1)
                    printf("Largest element in BST: %d\n", value);
                break;

            case 3:
                value = findSmallest(root);
                if (value != -1)
                    printf("Smallest element in BST: %d\n", value);
                break;

            case 4:
                printf("Height of BST: %d\n", height(root));
                break;

            case 5:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}
