#include "ex.h"
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

int skipQueue(queue q, item i) {
    queue temp = newQueue(); //Nuova coda temporanea
    int foundFlag = 0; //flag per l'elemento trovato
    item target = NULLITEM; //elemento da spostare in testa
    item currentItem; //variabile per scorrere la coda
    
    /*
     Fino a quando la coda originale (q) non è vuota assegna a currentItem l'elemento corrente 
     rimuovendolo dalla coda (q) con dequeue (rimuove e restituisce l'item) 
     se la flag è 0 e l'item corrente e uguale all'item cercato (i) 
     assegna a target l'item, altrimenti inserisci l'item nella coda.
     */
    while (!emptyQueue(q)) {
        currentItem = dequeue(q);
        if (!foundFlag && eq(currentItem, i)) {
            target = currentItem;
            foundFlag = 1;
        } else {
            enqueue(temp, currentItem);
        }
    }
    
    /*
     In questo momento la coda originale (q) è vuota dopo il ciclo while, 
     se la flag è vera (1) inserisci l'item target in testa alla coda originale.
     */
    if (foundFlag) {
        enqueue(q, target);
    }
    
    /*
     A questo punto la coda temp contiene tutti gli elementi della coda originale tranne l'elemento target
     (che la funzione deve inserire in testa alla coda).
     Scorri la coda temp prelevando ogni elemento ed aggiungilo alla coda originale (q).
     */
    while (!emptyQueue(temp)) {
        currentItem = dequeue(temp);
        enqueue(q, currentItem);
    }
    
    /*
     A questo punto la coda originale (q) è strutturata come vogliamo
    con l'item i passato alla funzione in testa alla coda, 
    quindi possiamo liberare la memoria della coda temporanea che ora è vuota e non serve più.
     */
    free(temp);
    
    //Se la tutto è andato correttamente la funzione ritorna 1 altrimenti 0
    return foundFlag ? 1 : 0;
}

int speculare(queue q1, queue q2) {
    if (emptyQueue(q1) || emptyQueue(q2)) {
        return 0;
    }

    item arr1[50];
    item arr2[50];

    //Salva coda 1 in arr1
    int i = 0;
    while (!emptyQueue(q1)) {
        arr1[i] = dequeue(q1);
        i++;
    }

    //Salva coda 2 in arr2
    int j = 0;
    while (!emptyQueue(q2)) {
        arr2[j] = dequeue(q2);
        j++;
    }

    //Rimette coda 1 in coda 1
    for (int c1 = 0; c1 < i; c1++) {
        enqueue(q1, arr1[c1]);
    }

    //Rimette coda 2 in coda 2
    for (int c2 = 0; c2 < j; c2++) {
        enqueue(q2, arr2[c2]);
    }

    //Se le due code non hanno lo stesso numero di elementi non sono speculari
    if (i != j) return 0;

    //Controlla se le due code sono speculari tramite l'array
    for (int k = 0; k < i; k++) {
        if (!eq(arr1[k], arr2[i - 1 - k])) {
            return 0;
        }
    }

    return 1;
}

int vicini(queue q, item a, item b) {
    if (emptyQueue(q)) {
        return 0;
    }

    queue temp = newQueue();
    int viciniCount = 0;
    item current = NULLITEM;
    item previous = NULLITEM;

    // Leggi tutti gli elementi dalla coda originale
    while (!emptyQueue(q)) {
        current = dequeue(q);
        
        // Controlla se la coppia (previous, current) è uguale a (a, b)
        if (previous != NULLITEM && eq(previous, a) && eq(current, b)) {
            viciniCount++;
        }
        
        // Salva l'elemento corrente nella coda temporanea
        enqueue(temp, current);
        previous = current;
    }

    // Rimetti tutti gli elementi nella coda originale
    while (!emptyQueue(temp)) {
        item restored = dequeue(temp);
        enqueue(q, restored);
    }

    free(temp);
    return viciniCount;
}

item centralItem(queue q) {
    if (emptyQueue(q)) {
        return NULLITEM;
    }

    queue temp = newQueue();
    int numElements = 0;
    item target = NULLITEM;

    while (!emptyQueue(q)) {
        item current = dequeue(q);
        enqueue(temp, current);
        numElements++;
    }

    int middleIndex = numElements / 2;

    for (int i = 0; i < numElements; i++) {
        item current = dequeue(temp);
        enqueue(q, current);

        if (i == middleIndex) {
            target = current;
        }
    }
    
    free(temp);
    return target;
}