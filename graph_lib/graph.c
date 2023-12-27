#include "graph.h"

Graph create_graph(int is_directional)
{
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
    printf("\nGraph { Order = %d, isDirectional = %d, Vertices = ", g->order, g->is_directional);
    for_each_element(g->vertices, print_vertex_edges);
    printf("\n}");
}