#include "graph.h"

// vertices
Vertex create_vertex(Graph g, int value, void *data)
{
    Vertex v = (Vertex)malloc(sizeof(struct vertex));
    v->value = value;
    v->edges = create_list();
    v->_open = 1;
    v->data = data;

    append(g->vertices, v);
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

    Node node = find_node(vertices, _compare_vertex, &value);

    if (node == NULL)
        return NULL;

    return get_vertex(node);
}

int _compare_vertex(void *v1, void *value)
{
    return ((Vertex)v1)->value == *(int *)value;
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

void free_vertex(void *v)
{
    free_list(((Vertex)v)->edges); // TODO Free edges
    free(v);
}