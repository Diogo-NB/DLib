#include <stdlib.h>

#include "graph_traversal.h"

List depth_first(Graph g, Vertex start)
{
    if (g == NULL || start == NULL)
        return NULL;

    Stack stack = create_stack();
    List L = create_list();
    for_each_element(g->vertices, _open_vertex);

    Vertex current;
    push(stack, start);

    while (!is_stack_empty(stack))
    {
        current = (Vertex)pop(stack);
        if (current->_open) // If hasn't been visited
        {
            _close_vertex(current);

            append(L, current);

            // Visit each adjacente vertice
            Node aux = current->edges->end; // All edges from current

            while (aux != NULL)
            {
                push(stack, get_edge(aux)->vertex); // Push where the edge leads
                aux = aux->prev;
            }
        }
    }

    free_stack(stack);
    return L;
}

List breadth_first(Graph g, Vertex start)
{
    if (g == NULL || start == NULL)
        return NULL;

    Queue queue = create_queue();
    List L = create_list();
    for_each_element(g->vertices, _open_vertex);

    Vertex current;
    enqueue(queue, start);

    while (!is_queue_empty(queue))
    {
        current = (Vertex)qpop(queue);
        if (current->_open) // If hasn't been visited
        {
            _close_vertex(current);

            append(L, current);

            // Visit each adjacente vertice
            Node aux = current->edges->start; // All edges from current

            while (aux != NULL)
            {
                enqueue(queue, get_edge(aux)->vertex); // Push where the edge leads
                aux = aux->next;
            }
        }
    }

    free_queue(queue);
    return L;
}

List shortest_path_values(Graph g, int fromValue, int toValue)
{
    Vertex from = find_vertex(g->vertices, fromValue);
    Vertex to = find_vertex(g->vertices, toValue);

    return shortest_path(g, from, to);
}

List shortest_path(Graph g, Vertex from, Vertex to)
{
    if (g == NULL || from == NULL || to == NULL)
        return NULL;

    _run_dijkstra(g, from);

    List shortest_path = create_list();

    Vertex v = to;
    while (v != NULL)
    {
        prepend(shortest_path, v);
        v = v->_predecessor;
    }

    return shortest_path;
}