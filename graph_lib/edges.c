#include "graph.h"

// edges
void create_edge_values(Graph g, int fromValue, int toValue, float weight)
{
    if (g == NULL)
        return;

    Vertex v1 = find_vertex(g->vertices, fromValue);
    if (v1 == NULL)
        return;

    Vertex v2 = find_vertex(g->vertices, toValue);
    if (v2 == NULL)
        return;

    create_edge(g, v1, v2, weight);
}

void create_edge(Graph g, Vertex from, Vertex to, float weight)
{
    if (from == NULL || to == NULL)
        return;

    Edge e = (Edge)malloc(sizeof(struct edge));
    e->vertex = to;
    e->weight = weight;

    insert_sorted(from->edges, e, _compare_edge_weights);

    if (!g->is_directional)
    {
        e = (Edge)malloc(sizeof(struct edge));
        e->vertex = from;
        e->weight = weight;

        insert_sorted(to->edges, e, _compare_edge_weights);
    }
}

int _compare_edge_vertices(void *e, void *v)
{
    return ((Edge)e)->vertex == ((Vertex)v);
}

int _compare_edge_weights(void *e1, void *e2)
{
    return ((Edge)e1)->weight > ((Edge)e2)->weight;
}

Edge get_edge(Node node)
{
    return (Edge)node->data;
}

Edge find_edge_values(Graph g, int fromValue, int toValue)
{
    if (g == NULL)
        return NULL;

    Vertex v1 = find_vertex(g->vertices, fromValue);
    if (v1 == NULL)
        return NULL;

    Vertex v2 = find_vertex(g->vertices, toValue);
    if (v2 == NULL)
        return NULL;

    return find_edge(v1, v2);
}

Edge find_edge(Vertex from, Vertex to)
{
    if (from == NULL || to == NULL)
        return NULL;

    return get_edge(find_node(from->edges, _compare_edge_vertices, to));
}

void remove_edge_values(Graph g, int fromValue, int toValue)
{
    if (g == NULL)
        return;

    Vertex v1 = find_vertex(g->vertices, fromValue);
    if (v1 == NULL)
        return;

    Vertex v2 = find_vertex(g->vertices, toValue);
    if (v2 == NULL)
        return;

    if (g->is_directional)
    {
        remove_edge(v1, v2);
    }
    else
    {
        remove_edge(v1, v2);
        remove_edge(v2, v1);
    }
}

void remove_edge(Vertex from, Vertex to)
{
    if (from == NULL || to == NULL)
        return;

    removes_node_free(from->edges, find_node(from->edges, _compare_edge_vertices, to), free);
}

void print_edge(void *e)
{
    printf("[%d, %.1f] ", ((Edge)e)->vertex->value, ((Edge)e)->weight);
}

void print_vertex_edges(void *v)
{
    printf("\n%d -> { ", ((Vertex)v)->value);
    for_each_element(((Vertex)v)->edges, print_edge);
    printf("}");
}