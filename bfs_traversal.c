//10.3
#include <stdio.h>
#define MAX 10
int n;
int adj[MAX][MAX];
int visited[MAX];
void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("Breadth First Search: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
int main() {
    printf("Enter number of vertex: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    int start;
    printf("Enter start vertex: ");
    scanf("%d", &start);
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    BFS(start);
    return 0;
}
