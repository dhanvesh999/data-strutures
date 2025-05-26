#include <stdio.h>

#define MAX 100

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int unionSet(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, e, u, v, w, i, j = 0;
    int edges[MAX][3], t, a, b, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Enter edge (u v w): ");
        scanf("%d%d%d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                t = edges[j][2];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][2] = t;

                t = edges[j][0];
                edges[j][0] = edges[j + 1][0];
                edges[j + 1][0] = t;

                t = edges[j][1];
                edges[j][1] = edges[j + 1][1];
                edges[j + 1][1] = t;
            }
        }
    }

    for (i = 0; i < e; i++) {
        a = find(edges[i][0]);
        b = find(edges[i][1]);

        if (unionSet(a, b)) {
            printf("Edge: (%d, %d) cost = %d\n", edges[i][0], edges[i][1], edges[i][2]);
            mincost += edges[i][2];
        }
    }

    printf("Total cost of MST: %d\n", mincost);

    return 0;
}
