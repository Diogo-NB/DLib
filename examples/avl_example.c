#include <stdio.h>
#include "avl_tree.h"
#include "stack.h"
#include "queue.h"

int compare_int(void *i1, void *i2)
{
    // > 0 quando i1 > i2
    // = 0 quando i1 = i2
    // < 0 quando i1 < i2
    return *(int *)i1 - *(int *)i2;
}

void print_int(void *i)
{
    printf("%d ", *((int *)i));
}

int main(void)
{
    AVL_Tree T = create_avl_tree(compare_int);
    int *input;
    int option;
    do
    {
        printf("\n------ MENU ------\n1 - Insert\n2 - In order print\n3 - Pre order print\n4 - Post order print\n5 - Level order print\n6 - Search\n7 - Exit\n--> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            input = (int *)malloc(sizeof(int));
            printf("--> ");
            scanf("%d", input);
            avl_insert(T, input);
            break;
        case 2:
            printf("\n In order print --> [ ");
            avl_in_order(T, print_int);
            printf("]");
            break;
        case 3:
            printf("\n Pre order print --> [ ");
            avl_pre_order(T, print_int);
            printf("]");
            break;
        case 4:
            printf("\n Post order print --> [ ");
            avl_post_order(T, print_int);
            printf("]");
            break;
        case 5:
            printf("\n Level order print --> [ ");
            avl_level_order(T, print_int);
            printf("]");
            break;
        case 6:
            printf("Search --> ");
            scanf("%d", input);
            void *d = avl_search(T, input);
            if (d != NULL)
                printf("Found %d", *(int *)d);
            else
                printf("Not Found!");
            break;
        case 7:
            break;
        default:
            printf("\nInvalid option!");
            break;
        }
    } while (option != 7);

    free_avl_tree_func(T, free);
    return 0;
}
