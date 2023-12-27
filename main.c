#include "graph.h"

void main()
{
    Graph g = create_graph(0);
    Vertex vs[8];

    for (int i = 0; i < 8; i++)
        vs[i] = create_vertex(g, i + 1, NULL);

    for (int i = 0; i < 8; i++)
        print_vertex(vs[i]);

    print_graph(g);

    create_edge(vs[0], vs[1], 2.0f);
    create_edge(vs[0], vs[4], 3.0f);
    create_edge(vs[0], vs[2], 1.0f);

    create_edge(vs[1], vs[4], 2.0f);
    create_edge(vs[1], vs[5], 2.0f);

    create_edge(vs[4], vs[3], 3.0f);
    create_edge(vs[4], vs[2], 2.0f);

    create_edge(vs[2], vs[3], 2.0f);
    create_edge(vs[2], vs[6], 4.0f);

    create_edge(vs[5], vs[3], 1.0f);
    create_edge(vs[5], vs[7], 3.0f);

    create_edge(vs[3], vs[7], 2.0f);
    create_edge(vs[3], vs[6], 2.0f);

    create_edge(vs[6], vs[7], 3.0f);

    print_graph(g);

    free_graph(g);
}