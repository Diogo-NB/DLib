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
    int *input = (int *)malloc(sizeof(int));
    printf("Adding values to the tree (insert -1 to stop) --> ");
    scanf("%d", input);

    while (*input != -1)
    {
        avl_insert(T, input);
        input = (int *)malloc(sizeof(int));
        scanf("%d", input);
    }

    printf("\n In order print --> [ ");
    avl_in_order(T, print_int);
    printf("]");

    printf("\n Pre order print --> [ ");
    avl_pre_order(T, print_int);
    printf("]");

    printf("\n Post order print --> [ ");
    avl_post_order(T, print_int);
    printf("]");

    printf("\n Level order print --> [ ");
    avl_level_order(T, print_int);
    printf("]");

    scanf("%d", input);
    printf("\nFinding %d --> ", *input);
    void *d = avl_search(T, input);
    if (d != NULL)
        print_int(d);
    else
        printf("Not Found!");

    free_avl_tree_func(T, free);

    return 0;
}
