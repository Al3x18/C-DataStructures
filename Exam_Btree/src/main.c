#include "ex.h"
#include "item.h"
#include <stdio.h>

int main(void) {
    // Creo un albero di esempio:
    //       5
    //      / \
    //     3   7
    //    / \   \
    //   1   4   9
    //        \
    //         6
    
    // Creo i nodi foglia
    Btree foglia1 = consBtree(1, newBtree(), newBtree());
    Btree foglia6 = consBtree(6, newBtree(), newBtree());
    Btree foglia9 = consBtree(9, newBtree(), newBtree());
    
    // Nodo 4 ha come figlio destro il nodo 6
    Btree nodo4 = consBtree(4, newBtree(), foglia6);
    
    // Creo i nodi intermedi
    Btree nodo3 = consBtree(3, foglia1, nodo4);
    Btree nodo7 = consBtree(7, newBtree(), foglia9);
    
    // Creo la radice
    Btree albero = consBtree(5, nodo3, nodo7);
    
    printf("=== ALBERO BINARIO DI ESEMPIO ===\n\n");
    
    printf("1. Output in pre-order:\n");
    outputBtree(albero);
    printf("\n\n");
    
    printf("2. Output visuale (struttura dell'albero, radice a sinistra):\n");
    outputBtreeVisual(albero);
    printf("\n");
    
    printf("La radice dell'albero è: ");
    output_item(getItem(albero));
    printf("\n");

    printf("La profondità dell'albero è: %d\n", computeDepth(albero));
    printf("Il numero di nodi dell'albero è: %d\n", numNodes(albero));
    printf("Il numero di foglie dell'albero è: %d\n", numLeaves(albero));
    printf("Il numero di nodi con un solo figlio (function V2) è: %d\n", numNodesWithSingleChildV2(albero));
    
    printf("\n=== FINE ESEMPIO ===\n");
    
    return 0;
}