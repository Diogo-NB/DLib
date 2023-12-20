#include "stack.h"

struct integer // Int wrapper
{
    int value;
};

typedef struct integer *Integer;

Integer create_integer(int value);

int main()
{
    Stack S = create_stack();

    push(S, create_integer(5));
    printf("%d\n", *((Integer)pop(S)));

    push(S, create_integer(9986));
    printf("%d\n", is_stack_empty(S));

    return 0;
}

Integer create_integer(int value)
{
    Integer I = (Integer)malloc(sizeof(struct integer));
    I->value = value;
    return I;
}