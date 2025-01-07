#include "graph.h"

// Helper function to find the vertex with the minimum distance value
int findMinVertex(int* minDistance, int* visited, int v) {
    int minIndex = -1, minValue = INT_MAX;
    for (int i = 0; i < v; i++) {
        if (!visited[i] && minDistance[i] < minValue) {
            minValue = minDistance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Implementation of Dijkstra's algorithm
void dijkstra(Graph* g, int start, int* minDistance) {
    int v = g->vertices;

    // Array to keep track of visited nodes
    int* visited = (int*)malloc(v * sizeof(int));

    for (int i = 0; i < v; i++) {
        minDistance[i] = INT_MAX; // Set all distances to infinity initially
        visited[i] = 0;          // Mark all nodes as unvisited
    }
    minDistance[start] = 0; // Distance to the start vertex is 0

    for (int i = 0; i < v - 1; i++) {
        // Find the vertex with the minimum distance that hasn't been visited
        int u = findMinVertex(minDistance, visited, v);
        if (u == -1) break; // All reachable nodes have been visited

        visited[u] = 1; // Mark the vertex as visited

        // Update distances for adjacent vertices
        for (int j = 0; j < v; j++) {
            if (!visited[j] && g->adjMatrix[u][j] != INT_MAX && minDistance[u] != INT_MAX && minDistance[u] + g->adjMatrix[u][j] < minDistance[j]) {
                minDistance[j] = minDistance[u] + g->adjMatrix[u][j];
            }
        }
    }

}

// Example usage
int main() {
    Graph g;
    init_Graph(&g, 5);

    addEdge(&g, 0, 1, 10);
    addEdge(&g, 0, 4, 20);
    addEdge(&g, 1, 2, 30);
    addEdge(&g, 1, 3, 40);
    addEdge(&g, 1, 4, 50);
    addEdge(&g, 3, 4, 60);

    int* minDistance = (int*)malloc(g.vertices * sizeof(int));
    dijkstra(&g, 0, minDistance);

    displayGraph(&g);
    
    printf("Shortest distances from vertex 0:\n");
    for (int i = 0; i < g.vertices; i++) {
        if (minDistance[i] != INT_MAX)
            printf("Vertex %d: %d\n", i, minDistance[i]);
        else
            printf("Vertex %d: Unreachable\n", i);
    }

    return 0;
}
