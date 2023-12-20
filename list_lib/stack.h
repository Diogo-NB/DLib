#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// A stack's node
struct sNode
{
    void *data;
    struct sNode *prev; // Previous node
};

typedef struct sNode* SNode;

struct stack
{
    struct sNode *top;
};

// A stack's pointer
typedef struct stack *Stack;

// Allocates memory for a new Stack
Stack create_stack();

// Inserts a new element at the top of the stack
int push(Stack S, void *data);

// Removes and return the top element
void *pop(Stack S);

// Returns true (1) if the stack is empty
int is_stack_empty(Stack S);

// Deallocates the stack (doesn't free the data in each node!)
void free_stack(Stack S);

// free_stack(S) while calling a free data function passed by the user for each node
void free_stack_func(Stack S, void (*free_data_func)(void *));

// Return the stack's size
int stack_size(Stack S);

#endif