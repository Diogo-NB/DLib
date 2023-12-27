#include "graph.h"

// edges
void create_edge(Graph g, int fromValue, int toValue, float weight);

void create_edgeD(Vertex from, Vertex to, float weight);

Edge get_edge(Node *node);

Edge find_edge(Graph g, int fromValue, int toValue);

Edge find_edgeD(Vertex fromVertice, Vertex toVertice);

void remove_edge(Graph g, int fromValue, int toValue);

void remove_edgeD(Vertex fromVertice, Vertex toVertice);

void print_edges(Vertex v);
