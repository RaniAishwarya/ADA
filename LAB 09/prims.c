#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

void prim(int n, int cost[MAX_VERTICES][MAX_VERTICES]) {
    int s[MAX_VERTICES];    // To track which vertices are included in MST
    int d[MAX_VERTICES];    // Shortest distance from source to each vertex
    int p[MAX_VERTICES];    // Parent array to store MST

    int min = INT_MAX;
    int source = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] < min) {
                min = cost[i][j];
                source = i;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        s[i] = 0;  // Not yet included in MST
        d[i] = cost[source][i];
        p[i] = source;
    }

    s[source] = 1;

    int sum = 0;
    int k = 0;
    int T[MAX_VERTICES - 1][2];  // To store MST edges

    for (int i = 1; i < n; i++) {
        int min = INT_MAX;
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (s[j] == 0 && d[j] <= min) {
                min = d[j];
                u = j;
            }
        }

        s[u] = 1;

        T[k][0] = u;
        T[k][1] = p[u];
        k++;

        sum += cost[u][p[u]];

        for (int v = 0; v < n; v++) {
            if (s[v] == 0 && cost[u][v] < d[v]) {
                d[v] = cost[u][v];
                p[v] = u;
            }
        }
    }

    if (sum >= INT_MAX) {
        printf("Spanning tree does not exist\n");
    } else {
        printf("Spanning tree exists and MST is:\n");
        for (int i = 0; i < n - 1; i++) {
            printf("(%d, %d)\n", T[i][0], T[i][1]);
        }
        printf("The cost of the spanning tree (MST) is: %d\n", sum);
    }
}

int main() {
    int n;  // Number of vertices
    int cost[MAX_VERTICES][MAX_VERTICES];  // Cost adjacency matrix

    printf("Enter number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prim(n, cost);

    return 0;
}
