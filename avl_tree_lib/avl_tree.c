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

void avl_insert(AVL_Tree T, void *data)
{
    AVL_Node root = T->root;
    if (avl_is_empty(T))
    {
        T->root = create_avl_node(data);
        return;
    }

    AVL_Node candidate = NULL, candidate_parrent = NULL;

    candidate = _avl_insert_node(T, data, &candidate_parrent);
    _recalculate_BF(candidate, data, T->comparef);

    if (candidate->BF == -2 || candidate->BF == 2)
    {
        if (candidate == root)
        {
            root = _rotate(candidate);
        }
        else
        {
            if (candidate_parrent->left == candidate)
                candidate_parrent->left = _rotate(candidate);
            else
                candidate_parrent->right = _rotate(candidate);
        }
    }
    T->root = root;
}

AVL_Node _avl_insert_node(AVL_Tree T, void *data, AVL_Node *candidate_parent_pointer)
{
    AVL_Node node = T->root, node_parent = NULL, candidate = T->root;
    int flag = 0, compare_result;

    while (node != NULL && !flag)
    {
        if (node->BF != 0)
        {
            *candidate_parent_pointer = node_parent;
            candidate = node;
        }

        // > 0 quando i1 > i2
        // = 0 quando i1 = i2
        // < 0 quando i1 < i2

        node_parent = node;

        compare_result = T->comparef(node->data, data);

        // if (node->value < value)
        if (compare_result < 0)
            node = node->right;
        // else if (node->value > value)
        else if (compare_result > 0)
            node = node->left;
        else
            flag = 1;
    }

    if (!flag)
    {
        // if (node_parent->value < value)
        if (T->comparef(node_parent->data, data) < 0)
            node_parent->right = create_avl_node(data);
        else
            node_parent->left = create_avl_node(data);
    }

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