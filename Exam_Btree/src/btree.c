#include "btree.h"
#include <stdlib.h>
#include <stdio.h>

item getItem(node *n) {
    if(n == NULL) return NULLITEM;
    return n->value;
}

void setItem(node *n, item el) {
    if (n == NULL) return;
    n->value = el;
}

Btree newBtree(void) {
    return NULL;
}

int emptyBtree(Btree t) {
    return t == NULL;
}

node *getRoot(Btree t) {
    return t;
}

Btree consBtree(item val, Btree sx, Btree dx) {
    struct node *nuovo;
    nuovo = (struct node*)malloc(sizeof(struct node));
    if (nuovo != NULL) {
        setItem(nuovo, val);
        nuovo->left = sx;
        nuovo->right = dx;
    }
    return nuovo;
}

Btree figlioSX(Btree t) {
    if (t != NULL) {
        return t->left;
    }
    return NULL;
}

Btree figlioDX(Btree t) {
    if (t != NULL) {
        return t->right;
    }
    return NULL;
}

void outputBtree(Btree t) {
    if (t == NULL) return;
    
    // Visita in in-order: sinistra, radice, destra
    outputBtree(figlioSX(t));
    output_item(getItem(t));
    outputBtree(figlioDX(t));
}

void outputBtreeVisual(Btree t) {
    outputBtreeVisualHelper(t, 0);
}

void outputBtreeVisualHelper(Btree t, int depth) {
    if (t == NULL) return;
    
    // Stampa il figlio destro (in alto)
    outputBtreeVisualHelper(figlioDX(t), depth + 1);
    
    // Stampa la radice con indentazione
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    output_item(getItem(t));
    printf("\n");
    
    // Stampa il figlio sinistro (in basso)
    outputBtreeVisualHelper(figlioSX(t), depth + 1);
}