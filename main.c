#include <stdio.h>
#include "avl_tree.h"

void abb_em_ordem(AVL_Node root)
{
    if (root != NULL)
    {
        abb_em_ordem(root->left);
        printf("%d ", root->value);
        abb_em_ordem(root->right);
    }
}

int main(void)
{
    AVL_Node root = NULL;

    root = avl_insert(root, 30);
    root = avl_insert(root, 10);
    root = avl_insert(root, 35);
    root = avl_insert(root, 7);
    root = avl_insert(root, 20);
    root = avl_insert(root, 25);

    printf("\n[ ");
    abb_em_ordem(root);
    printf("]");
    return 0;
}
