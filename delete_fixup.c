#include "main.h"

void delete_fixup(Node **root, Node *x)
{
    Node *w;

    while (x != *root && x->color == BLACK)
    {
        /* x is left child */
        if (x == x->parent->left)
        {
            w = x->parent->right;

            /* Case 1: sibling is RED */
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;

                left_rotate(root, x->parent);

                w = x->parent->right;
            }

            /* Case 2: sibling children are BLACK */
            if (w->left->color == BLACK &&
                w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                /* Case 3 */
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;

                    right_rotate(root, w);

                    w = x->parent->right;
                }

                /* Case 4 */
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;

                left_rotate(root, x->parent);

                x = *root;
            }
        }

        /* x is right child */
        else
        {
            w = x->parent->left;

            /* Case 1 */
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;

                right_rotate(root, x->parent);

                w = x->parent->left;
            }

            /* Case 2 */
            if (w->right->color == BLACK &&
                w->left->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                /* Case 3 */
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;

                    left_rotate(root, w);

                    w = x->parent->left;
                }

                /* Case 4 */
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;

                right_rotate(root, x->parent);

                x = *root;
            }
        }
    }

    x->color = BLACK;
}