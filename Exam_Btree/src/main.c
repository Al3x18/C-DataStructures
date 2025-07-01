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
    //  /     \   \
    // 10      6  12
    
    // Creo i nodi foglia
    
    Btree foglia6 = consBtree(6, newBtree(), newBtree());
    
    Btree foglia10 = consBtree(10, newBtree(), newBtree());
    Btree foglia12 = consBtree(12, newBtree(), newBtree());
    
    // Nodo 4 ha come figlio destro il nodo 6
    Btree nodo4 = consBtree(4, newBtree(), foglia6);
    
    // Creo i nodi intermedi
    Btree nodo1 = consBtree(1, foglia10, newBtree());
    Btree nodo3 = consBtree(3, nodo1, nodo4);
    Btree nodo9 = consBtree(9, newBtree(), foglia12);
    Btree nodo7 = consBtree(7, newBtree(), nodo9);
    
    // Creo la radice
    Btree albero = consBtree(5, nodo3, nodo7);

    
    // === SECONDO ALBERO DI ESEMPIO ===
    //       8
    //      / \
    //     2   12
    //    / \    \
    //   0   5    15
    //  /     \
    // 20      7

    Btree foglia7 = consBtree(7, newBtree(), newBtree());
    Btree foglia15 = consBtree(15, newBtree(), newBtree());
    Btree foglia20 = consBtree(20, newBtree(), newBtree());

    Btree nodo5 = consBtree(5, newBtree(), foglia7);
    Btree nodo0 = consBtree(0, foglia20, newBtree());
    Btree nodo2 = consBtree(2, nodo0, nodo5);
    Btree nodo12 = consBtree(12, newBtree(), foglia15);
    Btree albero2 = consBtree(8, nodo2, nodo12);
    
    printf("=== ALBERO BINARIO DI ESEMPIO 1 ===\n\n");
    
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
    printf("Il numero di nodi con un solo figlio è: %d\n", numNodesWithSingleChild(albero));
    printf("Il numero di figli destri è: %d\n", numDXChilds(albero));
    printf("La somma dei nodi dell'albero è: %d\n", sumNodes(albero));
    printf("Il numero di fratelli è: %d\n", fratelli(albero));
    printf("Il numero di foglie a distanza k è: %d\n", foglieK(albero, 3));
    printf("Gli alberi sono strutturalmente uguali? %d\n", strutturalmenteUguali(albero, albero2));
    printf("Il numero di nipoti di 7 è: %d\n", numeroNipoti(albero, 7));
    
    // === TEST FUNZIONE UGUALE SOMMA DX SX ===
    
    // === SOTTOALBERO 1 (VERO) ===
    //       2
    //      / \
    //     3   9
    //    / \  / \
    //   9  9 6  6

    Btree leaf9a = consBtree(9, newBtree(), newBtree());
    Btree leaf9b = consBtree(9, newBtree(), newBtree());
    Btree leaf6a = consBtree(6, newBtree(), newBtree());
    Btree leaf6b = consBtree(6, newBtree(), newBtree());
    Btree node3 = consBtree(3, leaf9a, leaf9b);
    Btree node9 = consBtree(9, leaf6a, leaf6b);
    Btree subtree1 = consBtree(2, node3, node9);

    // === SOTTOALBERO 2 (FALSO) ===
    //       2
    //      / \
    //     3   9
    //    / \  / \
    //   9 10 7  6

    Btree leaf9c = consBtree(9, newBtree(), newBtree());
    Btree leaf10 = consBtree(10, newBtree(), newBtree());
    Btree leaf7 = consBtree(7, newBtree(), newBtree());
    Btree leaf6c = consBtree(6, newBtree(), newBtree());
    Btree node3b = consBtree(3, leaf9c, leaf10);
    Btree node9b = consBtree(9, leaf7, leaf6c);
    Btree subtree2 = consBtree(2, node3b, node9b);

    // === SOTTOALBERO 3 (FALSO) ===
    //       2
    //      / \
    //     8   2
    //    / \  / \
    //   9 10 7  6

    Btree leaf9d = consBtree(9, newBtree(), newBtree());
    Btree leaf10b = consBtree(10, newBtree(), newBtree());
    Btree leaf7b = consBtree(7, newBtree(), newBtree());
    Btree leaf6d = consBtree(6, newBtree(), newBtree());
    Btree node8 = consBtree(8, leaf9d, leaf10b);
    Btree node2b = consBtree(2, leaf7b, leaf6d);
    Btree subtree3 = consBtree(2, node8, node2b);

    printf("\n=== SOTTOALBERI DI TEST UGUALE SOMMA DX SX ===\n\n");
    printf("Sottoalbero 1:\n\n");
    outputBtreeVisual(subtree1);
    printf("\n");
    printf("Sottoalbero 2:\n\n");
    outputBtreeVisual(subtree2);
    printf("\n");
    printf("Sottoalbero 3:\n\n");
    outputBtreeVisual(subtree3);
    printf("\n");
    
    printf("Il sottoalbero 1? %d\n", ugualeSommaDxSx(subtree1));
    printf("Il sottoalbero 2? %d\n", ugualeSommaDxSx(subtree2));
    printf("Il sottoalbero 3? %d\n", ugualeSommaDxSx(subtree3));
    
    return 0;
}