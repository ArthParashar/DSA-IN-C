//3.1
#include <stdio.h>

#define MAX 100

int main() 
{
    int tuple[MAX][3], transpose[MAX][3];
    int i, j, n;
    printf("Enter sparse matrix in 3-tuple format\n");
    scanf("%d %d %d", &tuple[0][0], &tuple[0][1], &tuple[0][2]);
    n = tuple[0][2];
    for (i = 1; i <= n; i++) 
    {
        scanf("%d %d %d", &tuple[i][0], &tuple[i][1], &tuple[i][2]);
    }
    transpose[0][0] = tuple[0][1];
    transpose[0][1] = tuple[0][0];
    transpose[0][2] = tuple[0][2];
    int k = 1;
    for (i = 0; i < tuple[0][1]; i++) 
    {
        for (j = 1; j <= n; j++) 
        {
            if (tuple[j][1] == i) 
            {
                transpose[k][0] = tuple[j][1];
                transpose[k][1] = tuple[j][0];
                transpose[k][2] = tuple[j][2];
                k++;
            }
        }
    }
    printf("Transpose of sparse matrix:\n");
    for (i = 0; i <= n; i++) 
    {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

    return 0;
}