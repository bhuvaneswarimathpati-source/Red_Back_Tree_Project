#include "main.h"

Node *find_min(Node *root)
{
    if (root == NIL)
        return NIL;

    while (root->left != NIL)
        root = root->left;

    return root;
}