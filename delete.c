#include "main.h"

static void transplant(Node **root, Node *u, Node *v)
{
    if (u->parent == NIL)
    {
        *root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }

    v->parent = u->parent;
}

void delete_node(Node **root, int data)
{
    Node *z = *root;
    Node *y;
    Node *x;
    int original_color;

    /* Search for node */
    while (z != NIL && z->data != data)
    {
        if (data < z->data)
            z = z->left;
        else
            z = z->right;
    }

    if (z == NIL)
    {
        printf("%d not found in the tree.\n", data);
        return;
    }

    y = z;
    original_color = y->color;

    /* Case 1: No left child */
    if (z->left == NIL)
    {
        x = z->right;
        transplant(root, z, z->right);
    }

    /* Case 2: No right child */
    else if (z->right == NIL)
    {
        x = z->left;
        transplant(root, z, z->left);
    }

    /* Case 3: Two children */
    else
    {
        y = find_min(z->right);

        original_color = y->color;
        x = y->right;

        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            transplant(root, y, y->right);

            y->right = z->right;
            y->right->parent = y;
        }

        transplant(root, z, y);

        y->left = z->left;
        y->left->parent = y;

        y->color = z->color;
    }

    free(z);

    /* Fix if a BLACK node was removed */
    if (original_color == BLACK)
        delete_fixup(root, x);

    printf("%d deleted successfully.\n", data);
}