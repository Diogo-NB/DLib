#ifndef AVL_TREE_H_INCLUDED
#define AVL_TREE_H_INCLUDED

#include "stack.h"
#include "queue.h"

struct avl_node
{
    void *data;
    int BF; // Balancing factor
    struct avl_node *left;
    struct avl_node *right;
};

typedef struct avl_node *AVL_Node;

struct avl_tree
{
    struct avl_node *root;
    int (*comparef)(void *, void *);
};

typedef struct avl_tree *AVL_Tree;

// Allocates memory for a new tree
AVL_Tree create_avl_tree(int (*comparef)(void *, void *));

// Returns true (1) if the list is empty
int avl_is_empty(AVL_Tree T);

// Allocates memory for a new node
AVL_Node create_avl_node(void *data);

// Deallocates tree
void free_avl_tree(AVL_Tree T);

// free_avl_tree while calling a free data function for each element
void free_avl_tree_func(AVL_Tree T, void (*free_data_func)(void *));

// Inserts a new data into the tree
void avl_insert(AVL_Tree T, void *data);

// Searchs the tree and returns a node's data where comparef returns 0
void *avl_search(AVL_Tree T, void *data);

void avl_pre_order(AVL_Tree T, void (*func)(void *));

void avl_in_order(AVL_Tree T, void (*func)(void *));

void avl_post_order(AVL_Tree T, void (*func)(void *));

void avl_level_order(AVL_Tree T, void (*func)(void *));

#endif