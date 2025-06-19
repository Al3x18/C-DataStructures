#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"

/* Struttura che rappresenta un nodo della lista
 * value: contiene l'elemento della lista
 * next: puntatore al prossimo nodo
 */
struct node {
    item value;
    struct node *next;
};

/* Crea una nuova lista vuota
 * Ritorna NULL per rappresentare una lista vuota
 */
list newList(void) {
    return NULL;
}

/* Verifica se una lista è vuota
 * Ritorna 1 se la lista è vuota, 0 altrimenti
 */
int emptyList(list l) {
    return l == NULL;
}

/* Inserisce un nuovo elemento all'inizio della lista
 * val: elemento da inserire
 * l: lista in cui inserire l'elemento
 * Ritorna la lista modificata con il nuovo elemento in testa
 */
list consList(item val, list l) {
    struct node *nuovo = (struct node*)malloc(sizeof(struct node));
    if (nuovo != NULL) {
        nuovo -> value = val;
        nuovo -> next = l;
        l = nuovo;
    }
    return l;
}

/* Restituisce la lista senza il primo elemento
 * l: lista di input
 * Ritorna la lista senza il primo elemento, o NULL se la lista è vuota
 */
list tailList(list l) {
    list temp;
    if (l != NULL) {
        temp = l->next;
    } else {
        temp = NULL;
    }
    return temp;
}

/* Restituisce il primo elemento della lista
 * l: lista di input
 * Ritorna il primo elemento o NULLITEM se la lista è vuota
 */
item getFirst(list l) {
    item e;
    if (l != NULL) {
        e = l->value;
    } else {
        e = NULLITEM;
    }
    return e;
}

/* Calcola la dimensione della lista
 * l: lista di input
 * Ritorna il numero di elementi nella lista
 */
int sizeList(list l) {
    int count = 0;
    while (!emptyList(l)) {
        count++;
        l = tailList(l);
    }
    return count;
}

/* Cerca un elemento nella lista e restituisce la sua posizione
 * i: elemento da cercare
 * l: lista in cui cercare
 * Ritorna la posizione dell'elemento (0-based) o -1 se non trovato
 */
int posItem(item i, list l) {
    int pos = 0;
    int found = 0;

    while (!emptyList(l) && !found) {
        if (eq(getFirst(l), i)) {
            found = 1;
        } else {
            pos++;
            l = tailList(l);
        }
    }
    return found ? pos : -1;
}

/* Restituisce l'elemento in una specifica posizione
 * pos: posizione dell'elemento da ottenere
 * l: lista di input
 * Ritorna l'elemento nella posizione specificata o NULLITEM se la posizione non è valida
 */
item getItem(int pos, list l) {
    item e;
    int i = 0;

    if (pos < 0) return NULLITEM;

    while (i < pos && !emptyList(l)) {
        i++;
        l = tailList(l);
    }

    if (!emptyList(l)) {
        e = getFirst(l);
    } else {
        e = NULLITEM;
    }

    return e;
}

/* Inverte l'ordine degli elementi nella lista
 * l: lista da invertire
 * Ritorna una nuova lista con gli elementi in ordine inverso
 */
list reverseList(list l) {
    list rev;
    item val;

    rev = newList();

    while (!emptyList(l)) {
        val = getFirst(l);
        rev = consList(val, rev);
        l = tailList(l);
    }
    return rev;
}

/* Stampa tutti gli elementi della lista
 * l: lista da stampare
 * Per ogni elemento stampa la sua posizione e il suo valore
 */
void outputList(list l) {
    int i = 0;
    item val;

    while (!emptyList(l)) {
        val = getFirst(l);
        printf("Elemento in posizione %d: ", i);
        output_item(val);
        printf("\n");
        l = tailList(l);
        i++;
    }
}

/* Crea una nuova lista leggendo n elementi da input
 * n: numero di elementi da leggere
 * Ritorna una nuova lista contenente gli elementi inseriti
 */
list inputList(int n) {
    item val;
    list l = newList();

    for (int i = 0; i < n; i++) {
        printf("Inserisci l'elemento in posizione %d: ", i);
        input_item(&val);
        l = consList(val, l);
    }
    return reverseList(l);
}