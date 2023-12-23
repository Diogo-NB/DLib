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

// Appends an existing node
Node append_from_node(List L, Node N, void *data);

// Prepends an existing node
Node prepend_from_node(List L, Node N, void *data);

// Inserts a new element at the start of the list and returns it's node
Node prepend(List L, void *data);

// Creates a new node
Node _create_node(void *new_node_data);

// Removes a node from a list
void remove_node(List L, Node N);

// Removes all that nodes where func returns true
void remove_nodes_where(List L, int (*func)(void *));

// Finds a node where func returns true (1)
Node find_node(List L, int (*func)(void *));

// Calls a function func for each list's element, from start to end
void for_each_element(List L, void (*func)(void *));

// Calls a function func for each list's element, from end to start
void for_each_element_reversed(List L, void (*func)(void *));

// Sort using user's compare function (returns > 0 when the data should be swapped)
void sort_list(List L, int (*compare)(void *, void *));

// Returns a new list containing the same elements
List clone_list(List L);

// Returns a new list containing the same elements in reversed order
List clone_list_reversed(List L);

// Swaps data between two nodes
int swap(Node n1, Node n2);

// Returns true (1) if the list is empty
int is_list_empty(List L);

// Deallocates the list and nodes
void free_list(List L);

// free_list while calling a free data function passed by the user for each node's data
void free_list_func(List L, void (*free_data_func)(void *));

// Calculates and returns the list's length
int list_length(List L);

#endif