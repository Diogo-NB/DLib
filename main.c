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
    scanf("%d", input);

    while (*input != -1)
    {
        avl_insert(T, input);
        input = (int *)malloc(sizeof(int));
        scanf("%d", input);
    }

    printf("\n[ ");
    avl_in_order(T, print_int);
    printf("]");

    printf("\n[ ");
    avl_pre_order(T, print_int);
    printf("]");

    printf("\n[ ");
    avl_post_order(T, print_int);
    printf("]");

    printf("\n[ ");
    avl_level_order(T, print_int);
    printf("]");

    return 0;
}
