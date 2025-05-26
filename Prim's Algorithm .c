#include <stdio.h>

#define INF 9999
#define MAX 100

int main() {
    int graph[MAX][MAX], visited[MAX];
    int n, i, j, min, u, v, cost = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    while (edges < n - 1) {
        min = INF;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        cost += min;
        edges++;
        printf("Edge %d: (%d, %d) cost = %d\n", edges, u, v, min);
    }

    printf("Total cost of MST: %d\n", cost);

    return 0;
}
