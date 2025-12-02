//9.3
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int findLargest(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty!\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}
int findSmallest(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty!\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}
int height(struct Node* root) {
    if (root == NULL)
        return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Largest\n");
        printf("4. Smallest\n");
        printf("5. Height\n");
        printf("6. Count leaf nodes\n");
        printf("7. Exit\n");

        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert in BST: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("BST after deletion (Inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                value = findLargest(root);
                if (value != -1)
                    printf("Largest element in BST: %d\n", value);
                break;

            case 4:
                value = findSmallest(root);
                if (value != -1)
                    printf("Smallest element in BST: %d\n", value);
                break;

            case 5:
                printf("Height of BST: %d\n", height(root));
                break;

            case 6:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}
