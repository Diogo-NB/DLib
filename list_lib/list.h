#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

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

/*
struct iterator
{
    void *_data;
    int index;
    void (*function)(Iterator);
};

typedef struct iterator *Iterator;
*/

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

// Calls a function func for each list's element, from start to end
void for_each_element(List L, void (*func)(void *));

// Calls a function func for each list's element, from end to start
void for_each_element_reversed(List L, void (*func)(void *));

// Returns the first node where compare(node's data, compareData) returns true (1)
Node find_node(List L, int (*compare)(void *, void *), void* compareData);

// Returns a sublist of nodes where compare(node's data, compareData) returns true (1)
List find_all_nodes(List L, int (*compare)(void *, void *), void *compareData);

// Inserts a new element at the correct position to keep the list sorted using the compare function (same used in sort_list)
Node insert_sorted(List L, void *data, int (*compare)(void *, void *));

// Sort using user's compare function (returns > 0 when the data should be swapped)
void sort_list(List L, int (*compare)(void *, void *));

// Returns a new list containing the same elements
List clone_list(List L);

// Returns a new list containing the same elements in reversed order
List clone_list_reversed(List L);

// clone_list() with a custom copy_data function for each element
List clone_list_custom(List L, void *(*copy_data)(void *));

// clone_list_reversed() with a custom copy_data function for each element
List clone_list_custom_reversed(List L, void *(*copy_data)(void *));

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