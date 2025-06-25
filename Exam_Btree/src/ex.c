#include "ex.h"
#include <stdio.h>

Btree inputBtree(void) {
    Btree t1, t2;
    int ris;
    item el;

    printf("L'albero è vuoto?(1/0): ");
    scanf("%d", &ris);

    if (ris) return newBtree();

    printf("Inserisci la radice: ");
    input_item(&el);

    printf("Costruisco sottoalbero SX\n");
    t1 = inputBtree();

    printf("Costruisco sottoalbero DX\n");
    t2 = inputBtree();

    return consBtree(el, t1, t2);
}

int computeDepth(Btree t) {
    if (emptyBtree(t)) return 0;

    int depthSX = computeDepth(figlioSX(t));
    int depthDX = computeDepth(figlioDX(t));

    return 1 + (depthSX > depthDX ? depthSX : depthDX);
}

int numNodes(Btree t) {
    if (emptyBtree(t)) return 0;

    return 1 + numNodes(figlioSX(t)) + numNodes(figlioDX(t));
}

int numLeaves(Btree t) {
    if (emptyBtree(t)) return 0;

    if (emptyBtree(figlioSX(t)) && emptyBtree(figlioDX(t))) return 1;

    return numLeaves(figlioSX(t)) + numLeaves(figlioDX(t));
}

// int numNodesWithSingleChild(Btree t) {
//     if (emptyBtree(t)) return 0;

//     if (emptyBtree(figlioSX(t)) && !emptyBtree(figlioDX(t))) return 1 + numNodesWithSingleChild(figlioDX(t));
//     if (!emptyBtree(figlioSX(t)) && emptyBtree(figlioDX(t))) return 1 + numNodesWithSingleChild(figlioSX(t));

//     return numNodesWithSingleChild(figlioSX(t)) + numNodesWithSingleChild(figlioDX(t));
// }

int numNodesWithSingleChildV2(Btree t) {
    if (emptyBtree(t)) return 0;

    int count = 0;

    if (figlioDX(t) != NULL && figlioSX(t) == NULL) count++;
    if (figlioSX(t) != NULL && figlioDX(t) == NULL) count++;

    return count + numNodesWithSingleChildV2(figlioSX(t)) + numNodesWithSingleChildV2(figlioDX(t));
}

int numDXChilds(Btree t) {
    if (emptyBtree(t)) return 0;

    int count = 0;

    if(figlioDX(t) != NULL) count++;

    return count + numDXChilds(figlioSX(t)) + numDXChilds(figlioDX(t));
}

int sumNodes(Btree t) {
    if (emptyBtree(t)) return 0;

    return getItem(t) + sumNodes(figlioSX(t)) + sumNodes(figlioDX(t));
}

int fratelli(Btree t) {
    if (emptyBtree(t)) return 0;

    int count = 0;

    if (figlioSX(t) != NULL && figlioDX(t) != NULL) {
        count += 2;
    }

    return count + fratelli(figlioSX(t)) + fratelli(figlioDX(t));
}