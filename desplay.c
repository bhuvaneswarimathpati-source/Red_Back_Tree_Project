#include "main.h"

void inorder(Node *root)
{
    if (root == NIL)
        return;

    inorder(root->left);

    if (root->color == RED)
        printf("%d(R) ", root->data);
    else
        printf("%d(B) ", root->data);

    inorder(root->right);
}

void display(Node *root, int space)
{
    int i;

    if (root == NIL)
        return;

    space += 5;

    /* Right subtree */
    display(root->right, space);

    printf("\n");

    for (i = 5; i < space; i++)
        printf(" ");

    if (root->color == RED)
        printf("%d(R)\n", root->data);
    else
        printf("%d(B)\n", root->data);

    /* Left subtree */
    display(root->left, space);
}