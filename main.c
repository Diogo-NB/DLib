#include <stdio.h>
#include "avl_tree.h"
#include "stack.h"
#include "queue.h"

void avl_pre_order(AVL_Node root)
{
    AVL_Node node = root;
    Stack s = create_stack();

    while (node != NULL || !is_stack_empty(s))
    {
        while (push(s, node))
        {
            printf("%d ", node->value); // Visit
            node = node->left;
        }
        node = (AVL_Node)pop(s);
        node = node->right;
    }

    free_stack(s);
}

void avl_in_order(AVL_Node root)
{
    AVL_Node node = root;
    Stack s = create_stack();

    while (node != NULL || !is_stack_empty(s))
    {
        while (push(s, node))
            node = node->left;
        node = (AVL_Node)pop(s);

        printf("%d ", node->value); // Visit

        node = node->right;
    }

    free_stack(s);
}

void avl_post_order(AVL_Node root)
{
    AVL_Node node = root, last_visited_node = NULL;
    Stack s = create_stack();

    while (node != NULL && last_visited_node != root)
    {
        while (node != NULL && node != last_visited_node)
        {
            push(s, node);
            node = node->left;
        }

        node = (AVL_Node)pop(s);

        if (node->right == NULL || node->right == last_visited_node)
        {
            printf("%d ", node->value); // Visit
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

void avl_level_order(AVL_Node root)
{
    if (root == NULL)
        return;

    AVL_Node node;
    Queue q = create_queue();

    enqueue(q, node);

    while (!is_queue_empty(q))
    {
        node = (AVL_Node)qpop(q);
        printf("%d ", node->value); // Visit
        enqueue(q, node->left);
        enqueue(q, node->right);
    }

    free_queue(q);
}

int main(void)
{
    AVL_Node root = NULL;
    int input;
    scanf("%d", &input);

    while (input != -1)
    {
        root = avl_insert(root, input);
        scanf("%d", &input);
    }

    printf("\n[ ");
    avl_in_order(root);
    printf("]");

    printf("\n[ ");
    avl_pre_order(root);
    printf("]");

    printf("\n[ ");
    avl_post_order(root);
    printf("]");

    printf("\n[ ");
    avl_level_order(root);
    printf("]");

    return 0;
}
