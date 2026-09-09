#include "main.h"

int validate_choice(int choice)
{
    if (choice < 1 || choice > 8)
    {
        printf("Invalid choice. Please enter 1 to 8.\n");
        return 0;
    }

    return 1;
}

/*
 * Basic Red-Black Tree validation.
 * Returns 1 if valid, 0 otherwise.
 */

static int black_height(Node *root)
{
    int left_height;
    int right_height;

    if (root == NIL)
        return 1;

    /* Red node cannot have RED child */
    if (root->color == RED)
    {
        if (root->left->color == RED ||
            root->right->color == RED)
        {
            return -1;
        }
    }

    left_height = black_height(root->left);

    if (left_height == -1)
        return -1;

    right_height = black_height(root->right);

    if (right_height == -1)
        return -1;

    /* Black height must be same */
    if (left_height != right_height)
        return -1;

    if (root->color == BLACK)
        return left_height + 1;

    return left_height;
}

int validate_tree(Node *root)
{
    if (root == NIL)
        return 1;

    /* Root must be BLACK */
    if (root->color != BLACK)
        return 0;

    if (black_height(root) == -1)
        return 0;

    return 1;
}