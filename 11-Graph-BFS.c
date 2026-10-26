
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

// Breadth First Search
void BFS(int start) {
    int front = 0, rear = 0;
    int vertex, i;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        vertex = queue[front++];
        printf("%d ", vertex);

        for (i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int i, j, edges;
    int u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph and visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v), vertices numbered 0 to %d:\n", n - 1);

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    printf("\n");
    return 0;
}
