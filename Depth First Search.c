#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    int i;
    for (i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, e, u, v, start;
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start, n);
    printf("\n");

    return 0;
}
