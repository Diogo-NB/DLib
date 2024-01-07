#include "avl_tree.h"

void avl_pre_order(AVL_Tree T, void (*func)(void *))
{
    AVL_Node node = T->root;
    Stack s = create_stack();

    while (node != NULL || !is_stack_empty(s))
    {
        while (push(s, node))
        {
            func(node->data);
            node = node->left;
        }
        node = (AVL_Node)pop(s);
        node = node->right;
    }

    free_stack(s);
}

void avl_in_order(AVL_Tree T, void (*func)(void *))
{
    AVL_Node node = T->root;
    Stack s = create_stack();

    while (node != NULL || !is_stack_empty(s))
    {
        while (push(s, node))
            node = node->left;
        node = (AVL_Node)pop(s);

        func(node->data);

        node = node->right;
    }

    free_stack(s);
}

void avl_post_order(AVL_Tree T, void (*func)(void *))
{
    AVL_Node node = T->root, last_visited_node = NULL;
    Stack s = create_stack();

    while (node != NULL && last_visited_node != T->root)
    {
        while (node != NULL && node != last_visited_node)
        {
            push(s, node);
            node = node->left;
        }

        node = (AVL_Node)pop(s);

        if (node->right == NULL || node->right == last_visited_node)
        {
            func(node->data);
            last_visited_node = node;
        }
        else
        {
            push(s, node);
            node = node->right;
        }
    }

    free_stack(s);
}

void avl_level_order(AVL_Tree T, void (*func)(void *))
{
    if (T->root == NULL)
        return;

    AVL_Node node = T->root;
    Queue q = create_queue();

    enqueue(q, node);

    while (!is_queue_empty(q))
    {
        node = (AVL_Node)qpop(q);
        func(node->data);
        enqueue(q, node->left);
        enqueue(q, node->right);
    }

    free_queue(q);
}
