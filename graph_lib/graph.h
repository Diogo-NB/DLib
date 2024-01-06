#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "list_lib.h"
#include <stdio.h>
#include <float.h>

struct graph
{
    int order;
    int is_directional;
    List vertices;
};

typedef struct graph *Graph;

struct vertex
{
    int value;
    List edges;

    // Dijkstra
    int _open;
    float _estimate;
    struct vertex *_predecessor;
};

typedef struct vertex *Vertex;

struct edge
{
    float weight;
    Vertex vertex;
};

typedef struct edge *Edge;

// Allocates memory for a new graph
Graph create_graph(int is_directional);

// Deallocates graph
void free_graph(Graph g);

// Prints a representation of the graph
void print_graph(Graph g);

// Vertices
// Creates a new vertex for the graph
Vertex create_vertex(Graph g, int value);

// Returns a vertex from a list's node
Vertex get_vertex(Node node);

// Finds and returns a vertex with a specific value from a list of vertices
Vertex find_vertex(List vertices, int value);

// Compare function for sorting vertices
int _compare_vertex(void *v1, void *v2);

// Compare function for finding vertices
int _compare_vertex_value(void *v1, void *value);

// Sets a vertex as closed (_open = 0)
void _close_vertex(void *v);

// Sets a vertex as open (_open = 1)
void _open_vertex(void *v);

// Prints a individual vertex value
void print_vertex(void *v);

// Prints all vertices value
void print_vertices(List vertices);

// Remove and dealoccates a vertex from a graph
void remove_vertex(Graph g, Vertex v);

// Free a vertex
void free_vertex(void *v);

// Edges
// create_edge using values
void create_edge_values(Graph g, int fromValue, int toValue, float weight);

// Creates a new edge between two vertices
void create_edge(Graph g, Vertex from, Vertex to, float weight);

// Compare the edge destination to an vertex
int _compare_edge_vertices(void *e, void *v);

// Compare function for sorting edges by weight
int _compare_edge_weights(void *e1, void *e2);

// Returns an edge from a list's node
Edge get_edge(Node node);

// find_edge with values
Edge find_edge_values(Graph g, int fromValue, int toValue);

// Finds and returns an edge based on it's start and end vertices
Edge find_edge(Vertex from, Vertex to);

// remove_edge with values
void remove_edge_values(Graph g, int fromValue, int toValue);

// Finds and removes a edge
void remove_edge(Graph g, Vertex from, Vertex to);

// Prints an individual edge
void print_edge(void *v);

// Prints a vertex and it's edges
void print_vertex_edges(void *v);

#endif