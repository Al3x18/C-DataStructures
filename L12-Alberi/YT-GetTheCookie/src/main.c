#include "prototipi.h"
#include <stdio.h>

// Funzione per stampare l'albero in modo visivo
void printTree(node* T, int space) {
    if (T == NULL) return;

    // Aumenta la distanza tra i livelli
    space += 10;

    // Processa prima il figlio destro
    printTree(T->right, space);

    // Stampa il nodo corrente
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", T->key);

    // Processa il figlio sinistro
    printTree(T->left, space);
}

// Funzione wrapper per stampare l'albero
void printBST(node* T) {
    printf("\nStruttura dell'albero:\n");
    printTree(T, 0);
    printf("\n");
}

int main() {
    node* T = createBST();
    printf("Albero binario di ricerca creato (vuoto)\n");

    // Inserimento di alcuni nodi
    printf("\nInserimento dei nodi: 50, 30, 70, 20, 40, 60, 80\n");
    insert(&T, 50);
    insert(&T, 30);
    insert(&T, 70);
    insert(&T, 20);
    insert(&T, 40);
    insert(&T, 60);
    insert(&T, 80);
    printBST(T);

    // Ricerca di un nodo
    printf("\nRicerca del nodo con chiave 40:\n");
    node* found = search(T, 40);
    if (found != NULL) {
        printf("Nodo trovato: %d\n", found->key);
    } else {
        printf("Nodo non trovato\n");
    }

    // Ricerca di un nodo non presente
    printf("\nRicerca del nodo con chiave 45:\n");
    found = search(T, 45);
    if (found != NULL) {
        printf("Nodo trovato: %d\n", found->key);
    } else {
        printf("Nodo non trovato\n");
    }

    // Cancellazione di un nodo foglia
    printf("\nCancellazione del nodo foglia 20:\n");
    del_node(&T, 20);
    printBST(T);

    // Cancellazione di un nodo con un figlio
    printf("\nCancellazione del nodo con un figlio 30:\n");
    del_node(&T, 30);
    printBST(T);

    // Cancellazione di un nodo con due figli
    printf("\nCancellazione del nodo con due figli 50:\n");
    del_node(&T, 50);
    printBST(T);

    return 0;
}