#include "main.h"

Node *find_max(Node *root)
{
    if (root == NIL)
        return NIL;

    while (root->right != NIL)
        root = root->right;

    return root;
}