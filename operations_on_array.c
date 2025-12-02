//2.2
#include <stdio.h>
int countNonZero(int matrix[][10], int size) 
{
    int count = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] != 0)
                count++;
    return count;
}
void displayUpperTriangular(int matrix[][10], int size) 
{
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void displayAboveBelowDiagonal(int matrix[][10], int size) 
{
    printf("Elements just above and below the main diagonal:\n");
    printf("Above diagonal: ");
    for (int i = 0; i < size - 1; i++) 
    {
        printf("%d ", matrix[i][i + 1]);
    }
    printf("\n");
    printf("Below diagonal: ");
    for (int i = 1; i < size; i++) 
    {
        printf("%d ", matrix[i][i - 1]);
    }
    printf("\n");
}
int main() 
{
    int matrix[10][10];
    int size;
    printf("Enter size of the square matrix: ");
    scanf("%d", &size);
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &matrix[i][j]);
    int nonZeroCount = countNonZero(matrix, size);
    printf("Nonzero elements: %d\n", nonZeroCount);
    displayUpperTriangular(matrix, size);
    displayAboveBelowDiagonal(matrix, size);
    return 0;
}