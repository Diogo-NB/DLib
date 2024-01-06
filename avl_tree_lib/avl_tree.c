#include "avl_tree.h"

int avl_is_empty(AVL_Node root)
{
    return root == NULL;
}

AVL_Node create_avl_node(int value)
{
    AVL_Node node = (AVL_Node)malloc(sizeof(struct avl_node));
    node->left = node->right = NULL;
    node->value = value;
    node->BF = 0;
    return node;
}

AVL_Node avl_insert(AVL_Node root, int value)
{
    if (avl_is_empty(root))
        return create_avl_node(value);

    AVL_Node candidate = NULL, candidate_parrent = NULL;

    candidate = _avl_insert_node(root, value, &candidate_parrent);
    _recalculate_BF(candidate, value);

    if (candidate->BF == -2 || candidate->BF == 2)
    {
        if (candidate == root)
        {
            root = rotate(candidate);
        }
        else
        {
            if (candidate_parrent->left == candidate)
                candidate_parrent->left = rotate(candidate);
            else
                candidate_parrent->right = rotate(candidate);
        }
    }
    return root;
}

AVL_Node _avl_insert_node(AVL_Node root, int value, AVL_Node *candidate_parent_pointer)
{
    AVL_Node node = root, node_parent = NULL, candidate = root;
    int flag = 0;

    while (node != NULL && !flag)
    {
        if (node->BF != 0)
        {
            *candidate_parent_pointer = node_parent;
            candidate = node;
        }

        node_parent = node;
        if (node->value < value)
            node = node->right;
        else if (node->value > value)
            node = node->left;
        else
            flag = 1;
    }

    if (!flag)
    {
        if (node_parent->value < value)
            node_parent->right = create_avl_node(value);
        else
            node_parent->left = create_avl_node(value);
    }

    return candidate;
}

void _recalculate_BF(AVL_Node candidate, int value)
{
    AVL_Node aux = candidate;

    while (aux->value != value)
    {
        if (value > aux->value)
        {
            aux->BF--;
            aux = aux->right;
        }
        else
        {
            aux->BF++;
            aux = aux->left;
        }
    }
}

AVL_Node rotate(AVL_Node candidate)
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

int comparef(void *i1, void *i2)
{
    return *(int *)i1 < *(int *)i2;
}