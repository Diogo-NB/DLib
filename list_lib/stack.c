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
        SNode *aux;
        while (S->top != NULL)
        {
            aux = S->top;
            S->top = S->top->prev;
            free(aux);
        }
    }
    free(S);
}

void free_stack_func(Stack S, void (*free_data_func)(void *))
{
    if (!is_stack_empty(S))
    {
        SNode *aux;
        while (S->top != NULL)
        {
            aux = S->top;
            S->top = S->top->prev;
            free_data_func(aux->data);
            free(aux);
        }
    }
    free(S);
}

int stack_size(Stack S)
{
    int is_empty = is_stack_empty(S);

    if (!is_empty) // If stack's not empty
    {
        int count = 0;
        SNode *aux = S->top;
        while (aux != NULL)
        {
            count++;
            aux = aux->prev;
        }
        return count;
    }
    else
    {
        return is_empty;
    }
}