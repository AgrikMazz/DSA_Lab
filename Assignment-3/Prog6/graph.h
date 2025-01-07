#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct{
    int vertices;  //No of vertices of graph
    int **adjMatrix; //Adjacency matrix storing the weights between edges
} Graph;

void init_Graph(Graph* g, int v);
void addEdge(Graph* g, int u, int v, int wt);
void removeEdge(Graph* g, int u, int v);
int isAdjacent(Graph* g, int u, int v);
void displayGraph(Graph* g);

#endif