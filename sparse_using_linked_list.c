//5.3
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int row, col, value;
    struct Node* next;
};
struct Node* createNode(int r, int c, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = r;
    newNode->col = c;
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}
void display(struct Node* head, int rows, int cols, int nonZeroCount) {
    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", rows, cols, nonZeroCount);
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d %d %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int rows, cols;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    int mat[rows][cols];
    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                struct Node* newNode = createNode(i, j, mat[i][j]);
                if (head == NULL) {
                    head = tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
                nonZeroCount++;
            }
        }
    }
    display(head, rows, cols, nonZeroCount);

    return 0;
}
