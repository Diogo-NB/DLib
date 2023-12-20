#include "stack.h"

Stack create_stack()
{
    Stack S = (Stack)malloc(sizeof(struct stack));
    S->top = NULL;

    return S;
}

int push(Stack S, void *data)
{
    if (S == NULL)
        return -1;

    if (data == NULL)
        return 0;

    SNode *node = (SNode *)malloc(sizeof(SNode));
    node->data = data;
    node->prev = S->top;

    S->top = node;
    return 1;
}

void *pop(Stack S)
{
    if (is_stack_empty(S))
        return NULL;

    SNode *top = S->top;    // Current top node
    void *data = top->data; // Data to be returned
    S->top = top->prev;     // Setting new top node
    free(top);              // Deallocate the old top node
    
    return data;
}

int is_stack_empty(Stack S)
{
    if (S == NULL)
        return -1;

    return S->top == NULL;
}

void free_stack(Stack S)
{
    if (!is_stack_empty(S))
    {
        while (pop(S) != NULL)
            ;
    }
    free(S);
}