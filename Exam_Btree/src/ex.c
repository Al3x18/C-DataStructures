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

int numNodesWithSingleChild(Btree t) {
    if (emptyBtree(t)) return 0;

    int count = 0;

    if (figlioDX(t) != NULL && figlioSX(t) == NULL) count++;
    if (figlioSX(t) != NULL && figlioDX(t) == NULL) count++;

    return count + numNodesWithSingleChild(figlioSX(t)) + numNodesWithSingleChild(figlioDX(t));
}

int numDXChilds(Btree t) {
    if (emptyBtree(t)) return 0;

    int count = 0;

    if(figlioDX(t) != NULL) count++;

    return count + numDXChilds(figlioSX(t)) + numDXChilds(figlioDX(t));
}

int fratelli(Btree t) {
    if (emptyBtree(t)) return 0;

    int count = 0;

    if (figlioSX(t) != NULL && figlioDX(t) != NULL) {
        count += 2;
    }

    return count + fratelli(figlioSX(t)) + fratelli(figlioDX(t));
}

int foglieK(Btree t, int k) {
    // Caso base: se il nodo è NULL, ritorna 0
    if (emptyBtree(t)) return 0;

    // Quando k arriva a 0, siamo arrivati all'altezza desiderata
    // Qui controlliamo se il nodo corrente è una foglia
    if (k == 0) {
        // Se entrambi i figli sono NULL, questo è una foglia all'altezza desiderata
        if (emptyBtree(figlioSX(t)) && emptyBtree(figlioDX(t))) return 1;
        // Se il nodo ha figli, non è una foglia, quindi ritorna 0
        return 0;
    }

    // Se k > 0, dobbiamo scendere ancora nell'albero
    // k rappresenta quanti livelli dobbiamo ancora scendere
    // Ad esempio: Se k=3, dobbiamo scendere 3 livelli dal nodo corrente
    // Se k=2, dobbiamo scendere 2 livelli dal nodo corrente
    // Se k=1, dobbiamo scendere 1 livello dal nodo corrente
    // Se k=0, abbiamo raggiunto l'altezza desiderata
    return foglieK(figlioSX(t), k - 1) + foglieK(figlioDX(t), k - 1);
}

int strutturalmenteUguali(Btree t1, Btree t2) {
    // Se entrambi sono vuoti, sono uguali
    if (emptyBtree(t1) && emptyBtree(t2)) return 1;

    // Se uno è vuoto e l'altro no, non sono uguali
    if (emptyBtree(t1) || emptyBtree(t2)) return 0;

    return strutturalmenteUguali(figlioSX(t1), figlioSX(t2)) && 
    strutturalmenteUguali(figlioDX(t1), figlioDX(t2));
}

int sumNodes(Btree t) {
    if (emptyBtree(t)) return 0;

    return getItem(t) + sumNodes(figlioSX(t)) + sumNodes(figlioDX(t));
}

int ugualeSommaDxSx(Btree t) {
    if (emptyBtree(t)) return 1;

    Btree sx = figlioSX(t);
    Btree dx = figlioDX(t);

    if (emptyBtree(sx) && emptyBtree(dx)) return 1;

    int sumSX = sumNodes(sx);
    int sumDX = sumNodes(dx);

    if (sumSX != sumDX) return 0;

    return ugualeSommaDxSx(sx) && ugualeSommaDxSx(dx);
}

int numeroNipoti(Btree t, item i) {
    if (emptyBtree(t)) return 0;

    if (eq(getItem(t), i)) {
        int count = 0;
        Btree left = figlioSX(t);
        Btree right = figlioDX(t);

        // Count children of left child
        if (!emptyBtree(left)) {
            if (!emptyBtree(figlioSX(left))) count++;
            if (!emptyBtree(figlioDX(left))) count++;
        }
        // Count children of right child
        if (!emptyBtree(right)) {
            if (!emptyBtree(figlioSX(right))) count++;
            if (!emptyBtree(figlioDX(right))) count++;
        }
        return count;
    }

    // Otherwise, search in left and right subtrees
    return numeroNipoti(figlioSX(t), i) + numeroNipoti(figlioDX(t), i);
}

int almenoUnFiglioDX(Btree t) {
    if (emptyBtree(t)) return 0;

    if (figlioDX(t) != NULL && figlioSX(t) == NULL) return 1;

    return almenoUnFiglioDX(figlioSX(t)) || almenoUnFiglioDX(figlioDX(t));
}

// Funzione helper per verificare se l'albero è diagonale in una direzione specifica
int isDiagonaleDirection(Btree t, int direction) {
    // direction: 0 = sinistra, 1 = destra
    if (emptyBtree(t)) return 1;
    
    // Se è una foglia, è sempre diagonale
    if (emptyBtree(figlioSX(t)) && emptyBtree(figlioDX(t))) return 1;
    
    // Se ha entrambi i figli, NON è diagonale
    if (!emptyBtree(figlioSX(t)) && !emptyBtree(figlioDX(t))) return 0;
    
    // Se cerchiamo direzione sinistra (0) ma ha solo figlio destro
    if (direction == 0 && !emptyBtree(figlioDX(t))) return 0;
    
    // Se cerchiamo direzione destra (1) ma ha solo figlio sinistro  
    if (direction == 1 && !emptyBtree(figlioSX(t))) return 0;
    
    // Se ha solo un figlio nella direzione corretta, continua ricorsivamente
    if (!emptyBtree(figlioSX(t))) {
        return isDiagonaleDirection(figlioSX(t), direction);
    } else {
        return isDiagonaleDirection(figlioDX(t), direction);
    }
}

int diagonale(Btree t) {
    // Un albero vuoto è diagonale
    if (emptyBtree(t)) return 1;
    
    // Prova entrambe le direzioni: solo sinistri O solo destri
    return isDiagonaleDirection(t, 0) || isDiagonaleDirection(t, 1);
}