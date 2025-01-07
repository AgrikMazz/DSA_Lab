#include "graph.h"

void transitiveClosureMatrix(Graph* g, int** transitive_matrix){
    int v = g->vertices;

    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if(g->adjMatrix[i][j] != INT_MAX){
                transitive_matrix[i][j] = 1;
            } 
            else {
                transitive_matrix[i][j] = 0;
            }
        }
    }

    // Warshall's algorithm
    for (int k = 0; k < v; k++){
        for (int i = 0; i < v; i++){
            for (int j = 0; j < v; j++){
                transitive_matrix[i][j] = transitive_matrix[i][j] || (transitive_matrix[i][k] && transitive_matrix[k][j]);
            }
        }
    }
}

void displayMatrix(int** matrix, int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    init_Graph(&g, 4);

    addEdge(&g, 0, 1, 1);
    addEdge(&g, 1, 2, 1);
    addEdge(&g, 2, 3, 1);

    int** transitive_matrix = (int**)malloc(g.vertices * sizeof(int*));
    for (int i = 0; i < g.vertices; i++) {
        transitive_matrix[i] = (int*)malloc(g.vertices * sizeof(int));
    }
    
    transitiveClosureMatrix(&g, transitive_matrix);

    displayGraph(&g);
    
    printf("Transitive Closure Matrix:\n");
    displayMatrix(transitive_matrix, g.vertices);

    return 0;
}
