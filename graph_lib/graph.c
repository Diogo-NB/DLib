#include <stdlib.h>
#include <stdio.h>
#include <float.h>

#include "graph.h"

Graph create_graph(int is_directional)
{
    if (is_directional < 0 || is_directional > 1)
        return NULL;

    Graph g = (Graph)malloc(sizeof(struct graph));
    g->order = 0;
    g->is_directional = is_directional;
    g->vertices = create_list();
    return g;
}

void free_graph(Graph g)
{
    free_list_func(g->vertices, free_vertex);
    free(g);
}

void print_graph(Graph g)
{
    if (g->order == 0)
    {
        printf("\nGraph { }");
    }
    else
    {
        printf("\nGraph { Order = %d, isDirectional = %d, Vertices = ", g->order, g->is_directional);
        for_each_element(g->vertices, print_vertex_edges);
        printf("\n}");
    }
}
