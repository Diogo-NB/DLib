#include "stack.h"
#include "list.h"

#include <stdio.h>

// int wrapper for testing purpose
struct integer
{
    int value;
};

typedef struct integer *Integer;

Integer create_integer(int value);

void integer_print(void *data);

void stack_example();

void list_example();

int find_3(void *data);

int find_2(void *data);

int is_less_than_4(void *data);

void list_sort_example();

int compare_integer(void *i1, void *i2);

int main(void)
{
    list_example();
    return 0;
}

int find_3(void *data)
{
    return ((Integer)data)->value == 3;
}

int find_2(void *data)
{
    return ((Integer)data)->value == 2;
}

int is_less_than_4(void *data)
{
    return ((Integer)data)->value < 4;
}

int compare_integer(void *i1, void *i2)
{
    // When i1 is bigger than i2, they should be swapped
    return ((Integer)i1)->value - ((Integer)i2)->value;
}

void list_sort_example()
{
    List L = create_list();
    int int_array[] = {8, 2, 7, 6, 5, 4, 3, 2, -1};

    for (int i = 0; int_array[i] != -1; i++)
        append(L, create_integer(int_array[i]));

    for_each_element(L, integer_print);

    sort_list(L, compare_integer);

    printf("\n");

    for_each_element(L, integer_print);

    free_list_func(L, free);
}

void list_example()
{
    List L = create_list();
    Integer integers[5];

    printf("\nEmpty: %d\n", is_list_empty(L));

    for (int i = 0; i < 5; i++)
    {
        integers[i] = create_integer(i + 1);
        append(L, integers[i]);
    }

    printf("\nEmpty: %d", is_list_empty(L));
    printf("\nLength: %d\n", list_length(L));

    for_each_element(L, integer_print);

    printf("\n");

    remove_node(L, find_node(L, find_3)); // Removes the node that contains 3

    Node node_4 = find_node(L, find_2)->next;

    prepend_from_node(L, node_4, create_integer(3));

    for_each_element_reversed(L, integer_print);

    remove_nodes_where(L, is_less_than_4);

    printf("\n");

    for_each_element(L, integer_print);

    free_list_func(L, free);
}

void stack_example()
{
    Stack S = create_stack();
    Integer integers[5];

    printf("\nEmpty: %d\n", is_stack_empty(S));

    for (int i = 0; i < 5; i++)
    {
        integers[i] = create_integer(i + 1);
        printf("%d ", integers[i]->value);
        push(S, integers[i]);
    }

    printf("\nEmpty: %d", is_stack_empty(S));
    printf("\nSize: %d\n", stack_size(S));

    for (; !is_stack_empty(S); printf("%d ", *(Integer)pop(S)))
    {
    }

    free_stack_func(S, free);
}

Integer create_integer(int value)
{
    Integer I = (Integer)malloc(sizeof(struct integer));
    I->value = value;
    return I;
}

void integer_print(void *data)
{
    printf(" %d", *(Integer)data);
}