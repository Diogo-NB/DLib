#include "graph.h"

Graph create_graph(int defaultWeight, int is_directional)
{
    Graph g = (Graph)malloc(sizeof(struct graph));
    g->order = 0;
    g->defaultWeight = defaultWeight;
    g->is_directional = is_directional;
    g->vertices = create_list();
    return g;
}

void free_graph(Graph g)
{
    free_list_func(g->vertices, free_vertex);
    free(g);
}