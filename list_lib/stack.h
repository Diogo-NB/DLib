#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct sNode // Stack's node
{
    void *data;
    struct sNode *prev;
};

typedef struct sNode SNode;

struct stack
{
    struct sNode *top;
};

typedef struct stack* Stack;

Stack create_stack();

int push(Stack S, void *data);

void* pop(Stack S);

int is_stack_empty(Stack S);

void free_stack(Stack S);

#endif