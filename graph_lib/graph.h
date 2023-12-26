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
    int open;
    float estimate;
    struct vertice *predecessor;
    List edges;
};

typedef struct vertex *Vertex;

struct edge
{
    float weight;
    Vertex vertex;
};

typedef struct edge *Edge;

#endif