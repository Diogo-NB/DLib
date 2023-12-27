#include "graph.h"

int main()
{
    Graph g = create_graph(1.0, 1);

    int vs[10] = {9, 3, 1, 6, 7, 2, 8, 5, 10, 4};

    for (int i = 0; i < 10; i++)
        create_vertex(g, vs[i], NULL);

    print_vertices(g->vertices);

    free_graph(g);
    return 0;
}