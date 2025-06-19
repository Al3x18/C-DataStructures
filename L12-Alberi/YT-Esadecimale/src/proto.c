#include "proto.h"
#include <stdio.h>

node *new_node(int value) {
    node *n = (node *)malloc(sizeof(node));

    // initialize the node
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    return n;  // return node address
}

void del_node(node *n) {
    free(n);
}

int compute_depth(node *n) {
    if (n == NULL) return 0;

    int right_depth = compute_depth(n->right);
    int left_depth = compute_depth(n->left);

    return 1 + (right_depth >= left_depth ? right_depth : left_depth);
}

int compute_sum(node *n) {
    if (n == NULL) return 0;

    int result = n->value;

    int right_sum = compute_sum(n->right);
    int left_sum = compute_sum(n->left);

    return result + right_sum + left_sum;
}

int child_nodes(node *n) {
    // Base case: if node is NULL, return 0
    if (n == NULL) return 0;
    
    // If both children are NULL, this is a leaf node
    if (n->left == NULL && n->right == NULL) return 1;
    
    // Recursively count leaf nodes in left and right subtrees
    return child_nodes(n->left) + child_nodes(n->right);
}

int foglieK(node *n, int k) {
    // Base case: if node is NULL, return 0
    if (n == NULL) return 0;
    
    // When k reaches 0, we've arrived at the target height
    // This is where we check if the current node is a leaf
    if (k == 0) {
        // If both children are NULL, this is a leaf node at our target height
        if (n->left == NULL && n->right == NULL) return 1;
        // If the node has children, it's not a leaf, so return 0
        return 0;
    }
    
    // If k > 0, we need to go deeper in the tree
    // k represents how many levels we still need to descend
    // For example:
    // - If k=3, we need to go down 3 levels from the current node
    // - If k=2, we need to go down 2 levels from the current node
    // - If k=1, we need to go down 1 level from the current node
    // - If k=0, we've reached our target height
    return foglieK(n->left, k-1) + foglieK(n->right, k-1);
}

int strutturalmente_uguali(node *t1, node *t2) {
    // Se entrambi gli alberi sono vuoti, sono strutturalmente uguali
    if (t1 == NULL && t2 == NULL) return 1;
    
    // Se uno dei due alberi è vuoto e l'altro no, non sono strutturalmente uguali
    if (t1 == NULL || t2 == NULL) return 0;
    
    // Controlla ricorsivamente se i sottoalberi sinistro e destro hanno la stessa struttura
    // Non ci interessa il valore dei nodi, solo la loro presenza/assenza
    return strutturalmente_uguali(t1->left, t2->left) && 
           strutturalmente_uguali(t1->right, t2->right);
}

int somma_uguale_dx_sx(node *n) {
    if (n == NULL) return 0;

    node *rLeft = n->left;
    node *rRight = n->right;

    int sumLeft = compute_sum(rLeft);
    int sumRight = compute_sum(rRight);

    printf("sumLeft: %d, sumRight: %d\n", sumLeft, sumRight);

    return sumLeft == sumRight ? 1 : 0;
}