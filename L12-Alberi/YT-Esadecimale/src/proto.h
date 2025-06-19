#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

node *new_node(int value);
void del_node(node *n);
int compute_depth(node *n);
int compute_sum(node *n);
int child_nodes(node *n);
int foglieK(node *n, int k);
int strutturalmente_uguali(node *t1, node *t2);
int somma_uguale_dx_sx(node *n);