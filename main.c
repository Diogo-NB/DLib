#include "graph.h"

int main()
{
    Graph g = create_graph(1.0, 1);

    for (int i = 0; i < 10; i++)
        create_vertex(g, i + 1, NULL);

    print_vertices(g->vertices);

    free_graph(g);
    return 0;
}