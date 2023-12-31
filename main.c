#include "graph.h"

int main(void)
{
    int input, option, from, to;
    Graph g;

    do
    {
        printf("1 - Create non-directional graph\n2 - Create directional graph\n--> ");
        scanf("%d", &input);
        g = create_graph(input - 1);
    } while (g == NULL);

    do
    {
        // printf("\n------ MENU ------\n1 - Create vertex \n2 - Add edge\n3 - Print graph\n4 - Exit\n--> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nCreated vertex #%d", create_vertex(g, g->order, NULL)->value);
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
            printf("\nStart --> ");
            scanf("%d", &input);
            printf("\nDepth first traversal from the #%d vertex: ", input);
            for_each_element(depth_first(g, find_vertex(g->vertices, input)), print_vertex);
            break;
        case 5:
            printf("\nStart --> ");
            scanf("%d", &input);
            printf("\nBreadth first traversal from the #%d vertex: ", input);
            for_each_element(breadth_first(g, find_vertex(g->vertices, input)), print_vertex);
            break;
        case 6:
            shortest_path(g, get_vertex(g->vertices->start), get_vertex(g->vertices->end));
            break;
        default:
            printf("Enter a valid option!\n");
            break;
        }
    } while (option != 6);

    free_graph(g);

    return 0;
}