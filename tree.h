#ifndef TREE_H
#define TREE_H

void ADD_NODE ();
void DELETE_NODE ();
void SPLIT_NODE ();
void DELETE ();
void DELETE_SUBTREE ();
void RIGHTMOST_CHILD ();

struct Node;

typedef struct Node* Tree;

struct Node {
    int value;
    Tree left, right, prev, next, parent;
};

#endif
