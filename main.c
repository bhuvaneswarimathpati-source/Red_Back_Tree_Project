/*Name:Bhuvaneshwari
  Batch:int26001_174
  Description:Red-Black Tree Implementation in C
              I developed a menu-driven Red-Black Tree implementation in C as a Data Structures project.
              The main objective of the project was to understand how a self-balancing Binary Search Tree maintains its balance after insertion and deletion.
              I implemented the complete tree operations including insertion, deletion, finding minimum and maximum elements, deleting minimum and maximum elements, inorder traversal, and tree visualization.
              The important part of the project is the balancing mechanism. I implemented left and right rotations along with insertion fix-up and deletion fix-up operations to maintain the Red-Black Tree properties.
              I also used a Black `NIL` sentinel node instead of `NULL` for leaf nodes, which simplifies the balancing logic. Dynamic memory allocation is used for creating tree nodes.
             The project is divided into multiple C source files with a common header file and a Makefile for compilation. I also implemented validation logic to check important Red-Black Tree properties such as the Black root, no consecutive Red nodes, and equal Black height on all paths.
              Through this project, I gained practical understanding of pointers, structures, dynamic memory allocation, tree rotations, recursion, self-balancing data structures, modular C programming, and Makefile-based compilation.
*/


#include "main.h"

Node *NIL;

int main()
{
    Node *root = NULL;
    int choice;
    int data;

    /* Create NIL sentinel */
    NIL = (Node *)malloc(sizeof(Node));

    NIL->data = 0;
    NIL->color = BLACK;
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->parent = NIL;

    root = NIL;

    while (1)
    {
        printf("\n====================================\n");
        printf("        RED BLACK TREE MENU\n");
        printf("====================================\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Delete Minimum\n");
        printf("6. Delete Maximum\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        if (!validate_choice(choice))
            continue;

        switch (choice)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);

                insert(&root, data);
                printf("%d inserted successfully.\n", data);
                break;

            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);

                delete_node(&root, data);
                break;

            case 3:
            {
                Node *min = find_min(root);

                if (min == NIL)
                    printf("Tree is empty.\n");
                else
                    printf("Minimum element: %d\n", min->data);

                break;
            }

            case 4:
            {
                Node *max = find_max(root);

                if (max == NIL)
                    printf("Tree is empty.\n");
                else
                    printf("Maximum element: %d\n", max->data);

                break;
            }

            case 5:
                delete_min(&root);
                break;

            case 6:
                delete_max(&root);
                break;

            case 7:
                if (root == NIL)
                {
                    printf("Tree is empty.\n");
                }
                else
                {
                    printf("\nTree structure:\n\n");
                    display(root, 0);

                    printf("\nInorder traversal:\n");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 8:
                printf("Exiting...\n");
                free(NIL);
                return 0;
        }
    }

    return 0;
}