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

    SNode new_node = (SNode)malloc(sizeof(struct sNode));
    new_node->data = data;
    new_node->prev = S->top;

    S->top = new_node;
    return 1;
}

void *pop(Stack S)
{
    if (is_stack_empty(S))
        return NULL;

    SNode top = S->top;     // Current top node
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
    if (S == NULL)
        return;

    SNode aux = S->top;
    while (aux != NULL)
    {
        S->top = aux->prev;
        free(aux);
        aux = S->top;
    }
    free(S);
}

void free_stack_func(Stack S, void (*free_data_func)(void *))
{
    if (S == NULL)
        return;

    SNode aux = S->top;
    while (aux != NULL)
    {
        S->top = aux->prev;
        free_data_func(aux->data);
        free(aux);
        aux = S->top;
    }
    free(S);
}

int stack_size(Stack S)
{
    if (S == NULL)
        return -1;

    SNode aux = S->top;
    int count = 0;
    while (aux != NULL)
    {
        count++;
        aux = aux->prev;
    }
    return count;
}