#include "graph.h"

//Initalize a graph
void init_Graph(Graph* g, int v){
    g->vertices = v;
    g->adjMatrix = (int**)malloc(v * sizeof(int*));
    if (g->adjMatrix == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for(int i=0; i<v; i++){
        g->adjMatrix[i] = (int *)malloc(v * sizeof(int));
    }
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i == j){
                g->adjMatrix[i][j] = 0;
            }
            else{
                g->adjMatrix[i][j] = INT_MAX; // No edge - infinite edge weight
            }
        }
    }
}

//Add edge
void addEdge(Graph* g, int u, int v, int wt){
    g->adjMatrix[u][v] = wt;
    g->adjMatrix[v][u] = wt;
}

//Remove edge
void removeEdge(Graph* g, int u, int v) {
    g->adjMatrix[u][v] = INT_MAX;
    g->adjMatrix[v][u] = INT_MAX;  
}

//Checks if nodes are adjacent
int isAdjacent(Graph* g, int u, int v){
    return g->adjMatrix[u][v] != INT_MAX;
}

// Display the graph's adjacency matrix
void displayGraph(Graph* g) {
    printf("Graph Adjacency Matrix:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            if(g->adjMatrix[i][j] != INT_MAX) printf("%d\t", g->adjMatrix[i][j]);
            else printf("#\t");
        }
        printf("\n");
    }
}