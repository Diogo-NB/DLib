#ifndef AVL_TREE_H_INCLUDED
#define AVL_TREE_H_INCLUDED

#include "stdlib.h"

struct avl_node
{
    int value;
    int BF; // Balancing factor
    struct avl_node *left;
    struct avl_node *right;
};

typedef struct avl_node *AVL_Node;

int avl_is_empty(AVL_Node root);

AVL_Node create_avl_node(int value);

AVL_Node avl_insert(AVL_Node root, int value);

AVL_Node _avl_insert_node(AVL_Node root, int value, AVL_Node *candidate_parent_pointer);

void _recalculate_BF(AVL_Node candidate, int value);

AVL_Node rotate(AVL_Node candidate);

AVL_Node _rotate_right(AVL_Node candidate);

AVL_Node _rotate_left(AVL_Node candidate);

AVL_Node _rotate_left_right(AVL_Node candidate);

AVL_Node _rotate_right_left(AVL_Node candidate);

int comparef(void *i1, void *i2);

#endif