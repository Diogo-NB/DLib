#include <stdlib.h>

#include "avl_tree.h"

AVL_Tree create_avl_tree(int (*comparef)(void *, void *))
{
    AVL_Tree T = (AVL_Tree)malloc(sizeof(struct avl_tree));
    T->comparef = comparef;
    T->root = NULL;
    return T;
}

int avl_is_empty(AVL_Tree T)
{
    if (T == NULL)
        return -1;

    return T->root == NULL;
}

AVL_Node create_avl_node(void *data)
{
    AVL_Node node = (AVL_Node)malloc(sizeof(struct avl_node));
    node->left = node->right = NULL;
    node->data = data;
    node->BF = 0;
    return node;
}

void free_avl_tree(AVL_Tree T)
{
    AVL_Node node = T->root, aux;
    Stack s = create_stack();

    while (node != NULL || !is_stack_empty(s))
    {
        while (push(s, node))
            node = node->left;
        node = (AVL_Node)pop(s);

        aux = node->right;

        free(node);

        node = aux;
    }

    free_stack(s);
    free(T);
}

void free_avl_tree_func(AVL_Tree T, void (*free_data_func)(void *))
{
    AVL_Node node = T->root, aux;
    Stack s = create_stack();

    while (node != NULL || !is_stack_empty(s))
    {
        while (push(s, node))
            node = node->left;
        node = (AVL_Node)pop(s);

        aux = node->right;

        free_data_func(node->data);
        free(node);

        node = aux;
    }

    free_stack(s);
    free(T);
}

void avl_insert(AVL_Tree T, void *data)
{
    if (avl_is_empty(T))
    {
        T->root = create_avl_node(data);
        return;
    }

    AVL_Node candidate = NULL;
    AVL_Node *candidate_parrent_pointer = NULL;
    candidate = _avl_insert_node(T, data, &candidate_parrent_pointer);
    _recalculate_BF(candidate, data, T->comparef);

    if (candidate->BF == -2 || candidate->BF == 2)
    {
        if (candidate == T->root)
            T->root = _rotate(candidate);
        else
            *candidate_parrent_pointer = _rotate(candidate);
    }
}

AVL_Node _avl_insert_node(AVL_Tree T, void *data, AVL_Node **candidate_parent_pointer_pointer)
{
    AVL_Node node = T->root, candidate = T->root;
    AVL_Node *node_parent_pointer = NULL;
    int flag = 0, compare_result;

    while (node != NULL && !flag)
    {
        if (node->BF != 0)
        {
            *candidate_parent_pointer_pointer = node_parent_pointer;
            candidate = node;
        }

        // > 0 quando i1 > i2
        // = 0 quando i1 = i2
        // < 0 quando i1 < i2

        compare_result = T->comparef(node->data, data);

        // if (node->value < value)
        if (compare_result < 0)
        {
            node_parent_pointer = &node->right;
            node = node->right;
        }
        // else if (node->value > value)
        else if (compare_result > 0)
        {
            node_parent_pointer = &node->left;
            node = node->left;
        }
        else
        {
            flag = 1;
        }
    }

    if (!flag)
        *node_parent_pointer = create_avl_node(data);

    return candidate;
}

void _recalculate_BF(AVL_Node candidate, void *data, int (*comparef)(void *, void *))
{
    AVL_Node aux = candidate;
    int compare_result = comparef(data, aux->data);

    // while (aux->value != value)
    while (compare_result != 0)
    {
        // if (value > aux->value)
        if (compare_result > 0)
        {
            aux->BF--;
            aux = aux->right;
        }
        else
        {
            aux->BF++;
            aux = aux->left;
        }
        compare_result = comparef(data, aux->data);
    }
}

AVL_Node _rotate(AVL_Node candidate)
{
    AVL_Node new_root = NULL;

    if (candidate->BF == 2)
    {
        if (candidate->left->BF == 1)
            new_root = _rotate_right(candidate);
        else
            new_root = _rotate_left_right(candidate);
    }
    else
    {
        if (candidate->right->BF == -1)
            new_root = _rotate_left(candidate);
        else
            new_root = _rotate_right_left(candidate);
    }

    return new_root;
}

AVL_Node _rotate_right(AVL_Node candidate)
{
    AVL_Node child = candidate->left;
    AVL_Node child_child = child->right;

    child->right = candidate;
    candidate->left = child_child;

    candidate->BF = child->BF = 0;

    return child;
}

AVL_Node _rotate_left(AVL_Node candidate)
{
    AVL_Node child = candidate->right;
    AVL_Node child_child = child->left;

    child->left = candidate;
    candidate->right = child_child;

    candidate->BF = child->BF = 0;

    return child;
}

AVL_Node _rotate_left_right(AVL_Node candidate)
{
    AVL_Node new_root = NULL;
    AVL_Node child = candidate->left;
    AVL_Node child_child = child->right;
    int child_child_BF = 0;

    if (child_child != NULL)
        child_child_BF = child_child->BF;

    candidate->left = _rotate_left(child);
    new_root = _rotate_right(candidate);

    if (child_child_BF == 1)
    {
        candidate->BF = -1;
        child->BF = 0;
        child_child->BF = 0;
    }
    else if (child_child_BF == -1)
    {
        candidate->BF = 0;
        child->BF = +1;
        child_child->BF = 0;
    }

    return new_root;
}

AVL_Node _rotate_right_left(AVL_Node candidate)
{
    AVL_Node new_root = NULL;
    AVL_Node child = candidate->right;
    AVL_Node child_child = child->left;
    int child_child_BF = 0;

    if (child_child != NULL)
        child_child_BF = child_child->BF;

    candidate->left = _rotate_right(child);
    new_root = _rotate_left(candidate);

    if (child_child_BF == 1)
    {
        candidate->BF = 0;
        child->BF = -1;
        child_child->BF = 0;
    }
    else if (child_child_BF == -1)
    {
        candidate->BF = +1;
        child->BF = 0;
        child_child->BF = 0;
    }

    return new_root;
}

/*
int T->comparef(void *i1, void *i2)
{
    // > 0 quando i1 > i2
    // = 0 quando i1 = i2
    // < 0 quando i1 < i2
    return *(int *)i1 - *(int *)i2;
}
*/