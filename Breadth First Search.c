#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int vertex) {
    queue[++rear] = vertex;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front > rear;
}

void bfs(int start, int n) {
    visited[start] = 1;
    enqueue(start);

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n, e, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(start, n);
    printf("\n");

    return 0;
}
