#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// A list's node
struct node
{
    void *data;
    struct node *next;
    struct node *prev;
};

typedef struct node *Node;

struct list
{
    struct node *start;
    struct node *end;
};

// A list's pointer
typedef struct list *List;

// Allocates memory for a new List
List create_list();

// Inserts a new element at the end of the list and returns it's node
Node append(List L, void *data);

// Inserts a new element at the start of the list and returns it's node
Node prepend(List L, void *data);

// Creates a new node
Node _create_node(void *new_node_data);

// Swaps data between two nodes
int swap(Node n1, Node n2);

// Returns true (1) if the list is empty
int is_list_empty(List L);

// Deallocates the list (doesn't free the data in each node!)
void free_list(List L);

// free_list(S) while calling a free data function passed by the user for each node
void free_list_func(List L, void (*free_data_func)(void *));

// Return the list's length
int list_length(List L);

#endif