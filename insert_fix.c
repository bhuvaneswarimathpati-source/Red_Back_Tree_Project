#include "main.h"

void insert_fix(Node **root, Node *z)
{
    Node *y;

    while (z->parent->color == RED)
    {
        /* Parent is left child */
        if (z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;

            /* Case 1: Uncle is RED */
            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;

                z = z->parent->parent;
            }
            else
            {
                /* Case 2 */
                if (z == z->parent->right)
                {
                    z = z->parent;
                    left_rotate(root, z);
                }

                /* Case 3 */
                z->parent->color = BLACK;
                z->parent->parent->color = RED;

                right_rotate(root, z->parent->parent);
            }
        }

        /* Parent is right child */
        else
        {
            y = z->parent->parent->left;

            /* Case 1 */
            if (y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;

                z = z->parent->parent;
            }
            else
            {
                /* Case 2 */
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(root, z);
                }

                /* Case 3 */
                z->parent->color = BLACK;
                z->parent->parent->color = RED;

                left_rotate(root, z->parent->parent);
            }
        }
    }

    /* Root must always be BLACK */
    (*root)->color = BLACK;
}