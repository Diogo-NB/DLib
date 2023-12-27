#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "list.h"

struct graph
{
    float defaultWeight;
    int order;
    int is_directional;
    List vertices;
};

typedef struct graph *Graph;

struct vertex
{
    float defaultWeight;
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

Graph create_graph(int defaultWeight, int is_directional);

void free_graph(Graph g);

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
void create_edge(Graph g, int fromValue, int toValue, float weight);

void create_edgeD(Vertex from, Vertex to, float weight);

Edge get_edge(Node *node);

Edge find_edge(Graph g, int fromValue, int toValue);

Edge find_edgeD(Vertex fromVertice, Vertex toVertice);

void remove_edge(Graph g, int fromValue, int toValue);

void remove_edgeD(Vertex fromVertice, Vertex toVertice);

void print_edges(Vertex v);

#endif