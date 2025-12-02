//10.2
#include <stdio.h>
#define MAX 10
int n;
int adj[MAX][MAX];
int visited[MAX];
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v); 
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("\nVertex\tDegree\n");
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                degree++;
        }
        printf("%d\t%d\n", i, degree);
    }
    int start;
    printf("\nEnter start vertex: ");
    scanf("%d", &start);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("Depth First Search: ");
    DFS(start);
    printf("\n");
    return 0;
}
