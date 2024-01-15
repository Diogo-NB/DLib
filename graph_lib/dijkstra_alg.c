#include <stdlib.h>
#include <float.h>
#include <stdio.h>

#include "graph_traversal.h"

void _run_dijkstra(Graph g, Vertex start)
{
    // Setting up vertices
    List est_vertices = clone_list(g->vertices);
    for_each_element(est_vertices, _reset_vertex);
    start->_estimate = 0.0f;
    sort_list(est_vertices, _compare_est);
    // for_each_element(est_vertices, _debug_print_vertex);

    Node aux = est_vertices->start;
    Node aux_e;
    Vertex current;
    Edge e;
    float f;
    while (aux != NULL)
    {
        current = get_vertex(aux);
        _close_vertex(current);

        aux_e = current->edges->start;
        while (aux_e != NULL)
        {
            e = get_edge(aux_e);
            f = current->_estimate + e->weight;

            if (f < e->vertex->_estimate && e->vertex->_open)
            {
                e->vertex->_estimate = f;
                e->vertex->_predecessor = current;
            }

            aux_e = aux_e->next;
        }

        sort_list(est_vertices, _compare_est);
        remove_node(est_vertices, aux);
        aux = est_vertices->start;
    }

    // for_each_element(est_vertices, _debug_print_vertex);

    free_list(est_vertices);
}

void print_path(List path)
{
    Node aux = path->start;
    printf("\n{ ");
    while (aux != path->end)
    {
        printf("%d --> ", get_vertex(aux)->value);
        aux = aux->next;
    }
    printf("%d } Total path weight = %.1f", get_vertex(aux)->value, get_vertex(aux)->_estimate);
}

int _compare_est(void *v1, void *v2)
{
    return ((Vertex)v1)->_estimate > ((Vertex)v2)->_estimate;
}

void _reset_vertex(void *v)
{
    Vertex V = (Vertex)v;
    V->_estimate = FLT_MAX;
    V->_open = 1;
    V->_predecessor = NULL;
}

void _debug_print_vertex(void *v)
{
    Vertex V = (Vertex)v;
    // printf("\n{ Value: %d, Open: %d, Estimate: %.1f, Predecessor: ", V->value, V->_open, V->_estimate);
    printf("\n{ Value: %d, Open: %d, ", V->value, V->_open);
    if (V->_estimate == FLT_MAX)
        printf("Estimate: MAX, ");
    else
        printf("Estimate: %.1f, ", V->_estimate);

    printf("Predecessor: ");

    if (V->_predecessor != NULL)
        print_vertex(V->_predecessor);

    printf("}");
}
