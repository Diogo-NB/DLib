#include "graph.h"

void main()
{
    Graph g = create_graph(0);
    Vertex vs[8];

    for (int i = 0; i < 8; i++)
        vs[i] = create_vertex(g, i, NULL);

    create_edge(g, vs[0], vs[1], 1.0f);

    print_graph(g);

    free_graph(g);
}