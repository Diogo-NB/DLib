#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

Vertex create_vertex(Graph g, int value)
{
    if (g == NULL)
        return NULL;

    Vertex v = (Vertex)malloc(sizeof(struct vertex));
    v->value = value;
    v->edges = create_list();
    v->_open = 1;

    insert_sorted(g->vertices, v, _compare_vertex);
    g->order++;

    return v;
}

Vertex get_vertex(Node node)
{
    return (Vertex)node->data;
}

Vertex find_vertex(List vertices, int value)
{
    if (vertices == NULL)
        return NULL;

    Node node = find_node(vertices, _compare_vertex_value, &value);

    if (node == NULL)
        return NULL;

    return get_vertex(node);
}

int _compare_vertex(void *v1, void *v2)
{
    return ((Vertex)v1)->value > ((Vertex)v2)->value;
}

int _compare_vertex_value(void *v1, void *value)
{
    return ((Vertex)v1)->value == *(int *)value;
}

void _close_vertex(void *v)
{
    ((Vertex)v)->_open = 0;
}

void _open_vertex(void *v)
{
    ((Vertex)v)->_open = 1;
}

void print_vertex(void *v)
{
    printf("%d ", ((Vertex)v)->value);
}

void print_vertices(List vertices)
{
    printf("\nVertices -> { ");
    for_each_element(vertices, print_vertex);
    printf("}\n");
}

void remove_vertex(Graph g, Vertex v)
{
    Node aux = g->vertices->start;
    Vertex v_aux;
    Node v_node;
    while (aux != NULL)
    {
        v_aux = get_vertex(aux);
        if (v_aux != v)
            removes_node_free(v_aux->edges, find_node(v_aux->edges, _compare_edge_vertices, v), free);
        else
            v_node = aux;
        aux = aux->next;
    }

    free_list_func(v->edges, free);
    remove_node(g->vertices, v_node);
    g->order--;
}

void free_vertex(void *v)
{
    free_list_func(((Vertex)v)->edges, free);
    free(v);
}