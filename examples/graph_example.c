#include "graph_lib.h"

int main(void)
{
    int input, option, from, to;
    float f;
    Graph g;

    do
    {
        printf("1 - Create non-directional graph\n2 - Create directional graph\n--> ");
        scanf("%d", &input);
        g = create_graph(input - 1);
    } while (g == NULL);

    do
    {
        printf("\n------ MENU ------\n1 - Create vertex \n2 - Add edge\n3 - Print graph\n4 - DFT\n5 - BFT\n6 - Find shortest path\n7 - Exit\n--> ");
        scanf("%d", &option);

        printf("\n");

        switch (option)
        {
        case 1:
            printf("Created vertex #%d", create_vertex(g, g->order)->value);
            break;
        case 2:
            printf("From --> ");
            scanf("%d", &from);

            printf("To --> ");
            scanf("%d", &to);

            printf("Weight --> ");
            scanf("%f", &f);

            create_edge_values(g, from, to, f);
            break;
        case 3:
            print_graph(g);
            break;
        case 4:
            printf("Start --> ");
            scanf("%d", &input);
            printf("Depth first traversal from the #%d vertex: ", input);
            for_each_element(depth_first(g, find_vertex(g->vertices, input)), print_vertex);
            break;
        case 5:
            printf("Start --> ");
            scanf("%d", &input);
            printf("Breadth first traversal from the #%d vertex: ", input);
            for_each_element(breadth_first(g, find_vertex(g->vertices, input)), print_vertex);
            break;
        case 6:
            printf("From --> ");
            scanf("%d", &from);

            printf("To --> ");
            scanf("%d", &to);

            print_path(shortest_path_values(g, from, to));
            break;
        case 7:
            break;
        default:
            printf("Enter a valid option!\n");
            break;
        }
    } while (option != 7);

    free_graph(g);

    return 0;
}