#include <stdio.h>

#define INF 9999
#define MAX 100

int main() {
    int graph[MAX][MAX], dist[MAX], visited[MAX];
    int n, i, j, min, u, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
        }
    }

    printf("Shortest distances from vertex %d:\n", start);
    for (i = 0; i < n; i++)
        printf("To %d: %d\n", i, dist[i]);

    return 0;
}
