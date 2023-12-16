#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>

#define MAX_NODES 1000

typedef struct {
    int to;
    double weight;
} Edge;

typedef struct {
    int label;
    Edge* edges;
    int num_edges;
} Node;

typedef struct {
    Node* nodes;
    int num_nodes;
} Graph;

 {
        graph->nodes[i].label = i;
        graph->nodes[i].edges = NULL;
        graph->nodes[i].num_edges = 0;  
        graph->nodes 
        ; 

     

    }
    return graph;
}

void add_edge(Graph* graph, int from, int to, double weight) {
    Edge edge = {to, weight};
    Node* node = &graph->nodes[from];

    node->num_edges++;
    node->edges = realloc(node->edges, node->num_edges * sizeof(Edge));
    node->edges[node->num_edges - 1] = edge;
}

double* dijkstra(Graph* graph, int source) {
    double* dist = malloc(graph->num_nodes * sizeof(double));
    bool* visited = calloc(graph->num_nodes, sizeof(bool));
    for (int i = 0; i < graph->num_nodes; i++) {
        dist[i] = DBL_MAX;
    }
    double* dijkstra(Graph* graph, int source) {
    double* dist = malloc(graph->num_nodes * sizeof(double));
    bool* visited = calloc(graph->num_nodes, sizeof(bool));
    for (int i = 0; i < graph->num_nodes; i++) {
        dist[i] = DBL_MAX;


        Graph* create_graph(int num_nodes) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = malloc(num_nodes * sizeof(Node));
    for (int i = 0; i < num_nodes; i++)
