#include "graph.h"

void main()
{
    Graph g = create_graph(0);
    Vertex vs[9];

    for (int i = 0; i < 9; i++)
        vs[i] = create_vertex(g, i, NULL);

    create_edge(g, vs[1], vs[2], 2.0f);
    create_edge(g, vs[1], vs[5], 3.0f);
    create_edge(g, vs[1], vs[3], 1.0f);

    create_edge(g, vs[2], vs[5], 2.0f);
    create_edge(g, vs[2], vs[6], 2.0f);

    create_edge(g, vs[5], vs[4], 3.0f);
    create_edge(g, vs[5], vs[3], 2.0f);

    create_edge(g, vs[3], vs[4], 2.0f);
    create_edge(g, vs[3], vs[7], 4.0f);

    create_edge(g, vs[6], vs[4], 1.0f);
    create_edge(g, vs[6], vs[8], 3.0f);

    create_edge(g, vs[4], vs[8], 2.0f);
    create_edge(g, vs[4], vs[7], 2.0f);

    create_edge(g, vs[7], vs[8], 3.0f);

    print_graph(g);

    remove_vertex(g, vs[3]);

    print_graph(g);

    free_graph(g);
}