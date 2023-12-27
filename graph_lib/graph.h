#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "list.h"

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
    void *data;

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

// vertices
Vertex create_vertex(Graph g, int value, void *data);

Vertex get_vertex(Node node);

Vertex find_vertex(List vertices, int value);

int _compare_vertex(void *v1, void *v2);

int _compare_vertex_value(void *v1, void *value);

void print_vertex(void *v);

void print_vertices(List vertices);

void free_vertex(void *v);

// edges
void create_edge_values(Graph g, int fromValue, int toValue, float weight);

void create_edge(Vertex from, Vertex to, float weight);

int _compare_edge_vertices(void *e, void *v);

int _compare_edge_weights(void *e1, void *e2);

Edge get_edge(Node node);

Edge find_edge_values(Graph g, int fromValue, int toValue);

Edge find_edge(Vertex from, Vertex to);

void remove_edge_values(Graph g, int fromValue, int toValue);

void remove_edge(Vertex from, Vertex to);

void print_edge(void *v);

void print_vertex_edges(void* v);

#endif