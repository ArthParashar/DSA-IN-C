//2.3
#include <stdio.h>
int main() 
{
    int rows, cols;
    int matrix[10][10];
    int tuple[100][3];
    int count = 0;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) 
            {
                tuple[count + 1][0] = i;
                tuple[count + 1][1] = j;
                tuple[count + 1][2] = matrix[i][j];
                count++;
            }
        }
    }
    tuple[0][0] = rows;
    tuple[0][1] = cols;
    tuple[0][2] = count;
    printf("Sparse matrix in 3-tuple format:\n");
    for (int i = 0; i <= count; i++) 
    {
        printf("%d %d %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
    return 0;
}