#include "stack.h"

// int wrapper for testing purpose
struct integer
{
    int value;
};

typedef struct integer *Integer;

Integer create_integer(int value);

int main()
{
    Stack S = create_stack();
    Integer integers[5];

    printf("\nVazio: %d\n", is_stack_empty(S));

    for (int i = 0; i < 5; i++)
    {
        integers[i] = create_integer(i + 1);
        printf("%d ", integers[i]->value);
        push(S, integers[i]);
    }

    printf("\nVazio: %d", is_stack_empty(S));
    printf("\nSize: %d\n", stack_size(S));

    for (; !is_stack_empty(S); printf("%d ", *(Integer)pop(S)));

    free_stack_func(S, free);
    return 0;
}

Integer create_integer(int value)
{
    Integer I = (Integer)malloc(sizeof(struct integer));
    I->value = value;
    return I;
}