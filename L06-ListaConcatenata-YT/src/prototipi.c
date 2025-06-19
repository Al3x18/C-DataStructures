#include "prototipi.h"
#include <stdio.h>
#include <stdlib.h>

// Funzione per inserire un nodo in testa alla lista
void list_insert(struct node** head, int new_data) {
    // Allocazione memoria per il nuovo nodo e preparazione campi
    struct node* nuovo = (struct node *)malloc(sizeof(struct node));
    if (nuovo == NULL) {
        printf("Errore di allocazione memoria\n");
        exit(0);
    }

    nuovo->data = new_data;
    nuovo->next = (*head);

    // Aggiornamento del puntatore alla testa della lista
    (*head) = nuovo;
}

// Funzione per stampare la lista
void list_display(struct node* p) {
    printf("\n");
    printf("LISTA CONCATENATA: ");
    while (p != NULL) {
        printf("|%d| -> ", p->data);
        p = p->next;
    }

    printf("NULL\n\n");
}

// Funzione di ricerca di un elemento nella lista per nodo
int list_search(struct node* corrente, int ricercato) {
    while (corrente != NULL) {

        if (corrente->data == ricercato) {
            return 1;
        }

        corrente = corrente->next;
    }

    return 0;
}

// Funzione per eliminare un nodo dalla lista
void list_delete(struct node** head, int key) {
    struct node *tmp = *head;
    struct node *prev = NULL;

    // Elimina la testa se il valore è uguale a quello cercato
    if (tmp != NULL && tmp->data == key) {
        *head = tmp->next; // Aggiorna il puntatore alla testa al prossimo nodo della lista
        free(tmp); // Libera la memoria del nodo eliminato
        return;
    }

    // Ricerca il nodo da eliminare tenendo traccia del nodo precedente (per poter modificare prev->next)
    while (tmp != NULL && tmp->data != key) {
        prev = tmp;
        tmp = tmp->next;
    }

    // Nessun nodo ha come chiave quella cercata (key)
    if (tmp == NULL) {
        printf("Nodo con dato %d non trovato\n", key);
        return;
    }

    // Nodo trovato, aggiorna il puntatore del nodo precedente
    prev->next = tmp->next;
    free(tmp); // Libera la memoria del nodo eliminato
}