//3.2
#include <stdio.h>
#define MAX 100
int main() 
{
    int a[MAX][3], b[MAX][3], result[MAX][3];
    int i = 1, j = 1, k = 1;
    int n1, n2;
    printf("Enter sparse matrix-1 in 3-tuple format\n");
    scanf("%d %d %d", &a[0][0], &a[0][1], &a[0][2]);
    n1 = a[0][2];
    for (i = 1; i <= n1; i++) 
    {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }
    printf("Enter sparse matrix-2 in 3-tuple format\n");
    scanf("%d %d %d", &b[0][0], &b[0][1], &b[0][2]);
    n2 = b[0][2];
    for (j = 1; j <= n2; j++) 
    {
        scanf("%d %d %d", &b[j][0], &b[j][1], &b[j][2]);
    }
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) 
    {
        printf("Matrix dimensions do not match. Addition not possible.\n");
        return 0;
    }
    i = j = 1;
    k = 1;
    while (i <= n1 && j <= n2) 
    {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) 
        {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++;
        } 
        else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) 
        {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++;
        } 
        else 
        {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) 
            {
                result[k][0] = a[i][0];
                result[k][1] = a[i][1];
                result[k][2] = sum;
            }
            i++;
            j++;
        }
        k++;
    }
    while (i <= n1) 
    {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++;
        k++;
    }
    while (j <= n2) 
    {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++;
        k++;
    }
    result[0][0] = a[0][0];
    result[0][1] = a[0][1]; 
    result[0][2] = k - 1;
    printf("Resultant Matrix in 3-tuple format\n");
    for (i = 0; i < k; i++) 
    {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }
    return 0;
}