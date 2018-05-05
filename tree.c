#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Node;

typedef struct Node* Tree;

typedef enum { false, true } bool;

struct Node {
    int value;
    Tree left, right, prev, next, parent;
};

int number_of_nodes;

void ADD_NODE (Tree *wsk, Tree *treePtr, int x) {
    Tree t = *treePtr;
    Tree t_new = (Tree) malloc(sizeof(struct Node));
    t_new->left = t_new->right = NULL;
    t_new->prev = t_new->next = t_new->parent = NULL;
    t_new->value = x;
    t_new->parent = t;
    wsk[x] = t_new;
    number_of_nodes++;

    if (t->left == NULL) {
        t->left = t_new;
        t->right = t_new;
    }
    else {
        t->right->next = t_new;
        t_new->prev = t->right;
        t->right = t_new;
    }

    printf ("OK\n");
}

void DELETE_NODE (Tree *treePtr) {
    Tree t = *treePtr;

    if (t->prev == NULL && t->left != NULL) {
        t->left->parent = t->parent;
        t->parent->left = t->left;
    }
    else if (t->prev == NULL && t->left == NULL) {
        if (t->next != NULL) {
            t->next->parent = t->parent;
        }
        t->parent->left = t->next;
    }
    else if (t->prev != NULL && t->left != NULL) {
        t->prev->next = t->left;
        t->left->prev = t->prev;
    }
    else {
        t->prev->next = t->next;
        if (t->next != NULL) {
            t->next->prev = t-> prev;
        }
    }

    if (t->next == NULL && t->right != NULL) {
        t->right->parent = t->parent;
        t->parent->right = t->right;
    }
    else if (t->next == NULL && t->right == NULL) {
        if (t->prev != NULL) {
            t->prev->parent = t->parent;
        }
        t->parent->right = t->prev;
    }
    else if (t->next != NULL && t->right != NULL){
        if (t->right != NULL) {
            t->next->prev = t->right;
            t->right->next = t->next;
        }
    }
    else {
        t->next->prev = t->prev;
        if (t->prev != NULL) {
            t->prev->next = t->next;
        }
    }

    number_of_nodes--;

    printf ("OK\n");
}

void SPLIT_NODE (Tree *wsk, Tree *treePtr, Tree *treePtr2, int x) {
    Tree k = *treePtr;
    Tree w = *treePtr2;

    Tree t = (Tree) malloc(sizeof(struct Node));
    t->value = x;
    wsk[x] = t;
    t->left = t->right = t->prev = t->next = t->parent = NULL;

    if (w->next != NULL) {
        t->left = (Tree) malloc(sizeof(struct Node));;w->next->parent = t;
        t->left = w->next;
        t->left->prev = NULL;

        k->right->parent = t;
        if (w->next->next != NULL) {
            t->right = (Tree) malloc(sizeof(struct Node));;
            t->right = k->right;
            t->right->parent = t;
        }
        else t->right = t->left;
    }

    w->next = t;
    t->prev = w;
    k->right = t;
    t->parent = k;

    number_of_nodes++;

    printf ("OK\n");
}

void DELETE (Tree t) {
    Tree pom = t->left;

    while (pom != NULL) {
        DELETE(pom);
        pom = pom->next;
    }

    number_of_nodes--;
    free(t);
}

void DELETE_SUBTREE (Tree t) {
    if (t->prev != NULL) {
        t->prev->next = t->next;
    }
    else {
        t->parent->left = t->next;
        if (t->next != NULL) {
            t->next->prev = NULL;
            t->next->parent = t->parent;
        }
    }

    if (t->next != NULL) {
        t->next->prev = t->prev;
    }
    else {
        t->parent->right = t->prev;
        if (t->prev != NULL) {
            t->prev->next = NULL;
            t->prev->parent = t->parent;
        }
    }

    DELETE(t);
}


void RIGHTMOST_CHILD (Tree t) {
    if (t->right == NULL) {
        printf ("-1\n");
    }
    else {
        printf("%d\n", t->right->value);
    }
}
