#include "stack.h"
#include "list.h"

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

int main(void)
{
    list_example();
    return 0;
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

    printf("[");
    for_each_element(L, integer_print);
    printf(" ]\n");

    printf("[");
    for_each_element_reversed(L, integer_print);
    printf(" ]\n");

    printf("[");
    for_each_element(clone_list_reversed(L), integer_print);
    printf(" ]");

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