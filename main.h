#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct Node
{
    int data;
    int color;

    struct Node *left;
    struct Node *right;
    struct Node *parent;

} Node;

/* Global NIL sentinel */
extern Node *NIL;

/* Insert */
Node *create_node(int data);
void insert(Node **root, int data);
void insert_fix(Node **root, Node *z);

/* Rotations */
void left_rotate(Node **root, Node *x);
void right_rotate(Node **root, Node *y);

/* Delete */
void delete_node(Node **root, int data);
void delete_fixup(Node **root, Node *x);

/* Minimum / Maximum */
Node *find_min(Node *root);
Node *find_max(Node *root);

/* Delete minimum / maximum */
void delete_min(Node **root);
void delete_max(Node **root);

/* Display */
void inorder(Node *root);
void display(Node *root, int space);

/* Validation */
int validate_choice(int choice);
int validate_tree(Node *root);

#endif