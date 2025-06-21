#include "item.h"

typedef struct node {
    item value;
    struct node *left;
    struct node *right;
} node;

typedef struct node *Btree;

Btree newBtree(void);

int emptyBtree(Btree t);

Btree figlioSX(Btree t);

Btree figlioDX(Btree t);

Btree consBtree(item val, Btree sx, Btree dx);

node *getRoot(Btree t);

item getItem(node *n);

void setItem(node *n, item el);

void outputBtree(Btree t);
void outputBtreeVisual(Btree t);
void outputBtreeVisualHelper(Btree t, int depth);
