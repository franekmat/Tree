#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "tree.h"

int number_of_nodes;
const int MAX_STRING_LENGTH = 100;
const int MAX = 1e5;
typedef enum { false, true } bool;

void INPUT (bool param) {
    int new_node_number = 1;
    Tree *wsk = malloc(MAX*sizeof(struct Node));
    char *input = malloc(MAX_STRING_LENGTH*sizeof(char));
    Tree t = (Tree) malloc(sizeof(struct Node));
    t->value = 0;
    t->left = t->right = t->prev = t->next = t->parent = NULL;
    wsk[0] = t;
    number_of_nodes = 1;

    while (scanf("%s", input) != EOF) {
        if (strcmp(input, "ADD_NODE") == 0) {
            int *a = (int *) malloc(sizeof(int));

            scanf ("%d", a);

            ADD_NODE (wsk, &wsk[*a], new_node_number);
            new_node_number++;

            free(a);
        }
        else if (strcmp(input, "RIGHTMOST_CHILD") == 0) {
            int *a = (int *) malloc(sizeof(int));

            scanf ("%d", a);

            RIGHTMOST_CHILD (wsk[*a]);

            free(a);
        }
        else if (strcmp(input, "DELETE_NODE") == 0) {
            int *a = (int *) malloc(sizeof(int));

            scanf ("%d", a);

            DELETE_NODE (&wsk[*a]);

            free(wsk[*a]);
            free(a);
        }
        else if (strcmp(input, "DELETE_SUBTREE") == 0) {
            int *a = (int *) malloc(sizeof(int));

            scanf ("%d", a);

            DELETE_SUBTREE (wsk[*a]);

            free(a);

            printf ("OK\n");
        }
        else {
            int *a = (int *) malloc(sizeof(int));
            int *b = (int *) malloc(sizeof(int));

            scanf ("%d %d", a, b);

            SPLIT_NODE (wsk, &wsk[*a], &wsk[*b], new_node_number);
            new_node_number++;

            free(a);
            free(b);
        }

        if (param) {
            fprintf(stderr, "NODES: %d\n", number_of_nodes);
        }
    }

    DELETE(wsk[0]);
    free(wsk);
    free(input);
}
