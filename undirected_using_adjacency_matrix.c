//10.1
#include <stdio.h>
int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int adj[n][n];
    char choice;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("Vertices %d & %d are Adjacent ? (Y/N): ", i + 1, j + 1);
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y') {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
    printf("\nVertex\tDegree\n");
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                degree++;
        }
        printf("%d\t%d\n", i + 1, degree);
    }
    return 0;
}
