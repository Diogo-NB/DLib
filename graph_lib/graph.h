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

Graph create_graph(int is_directional);

void free_graph(Graph g);

void print_graph(Graph g);

// Vertices
Vertex create_vertex(Graph g, int value);

Vertex get_vertex(Node node);

Vertex find_vertex(List vertices, int value);

int _compare_vertex(void *v1, void *v2);

int _compare_vertex_value(void *v1, void *value);

void _close_vertex(void *v);

void _open_vertex(void *v);

void print_vertex(void *v);

void print_vertices(List vertices);

void remove_vertex(Graph g, Vertex v);

void free_vertex(void *v);

// Edges
void create_edge_values(Graph g, int fromValue, int toValue, float weight);

void create_edge(Graph g, Vertex from, Vertex to, float weight);

int _compare_edge_vertices(void *e, void *v);

int _compare_edge_weights(void *e1, void *e2);

Edge get_edge(Node node);

Edge find_edge_values(Graph g, int fromValue, int toValue);

Edge find_edge(Vertex from, Vertex to);

void remove_edge_values(Graph g, int fromValue, int toValue);

void remove_edge(Graph g, Vertex from, Vertex to);

void print_edge(void *v);

void print_vertex_edges(void *v);

#endif