#include "graph.h"

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
    //printf("\n{ Value: %d, Open: %d, Estimate: %.1f, Predecessor: ", V->value, V->_open, V->_estimate);
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
