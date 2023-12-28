#include "graph.h"

void test()
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

    printf("\n");
    for_each_element(depth_first(g, vs[1]), print_vertex);

    printf("\n");
    for_each_element(breadth_first(g, vs[1]), print_vertex);

    free_graph(g);
}

int main(void)
{
    int input, option, from, to;
    Graph g;

    do
    {
        printf("1 - Create directional graph\n2 - Create non-directional graph\n--> ");
        scanf("%d", &input);
        g = create_graph(input - 1);
    } while (g == NULL);

    do
    {
        printf("\n------ MENU ------\n1 - Create vertex \n2 - Add edge\n3 - Print graph\n4 - Exit\n--> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nCreated vertex #%d", create_vertex(g, g->order + 1, NULL)->value);
            break;
        case 2:
            printf("\nFrom --> ");
            scanf("%d", &from);

            printf("\nTo --> ");
            scanf("%d", &to);

            printf("\nWeight --> ");
            scanf("%d", &input);

            create_edge_values(g, from, to, input * 1.0f);
            break;
        case 3:
            print_graph(g);
            break;
        case 4:
            break;
        default:
            printf("Enter a valid option!\n");
            break;
        }
    } while (option != 4);

    free_graph(g);

    return 0;
}