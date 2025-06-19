#include "prototipi.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct node *head = NULL;
    int nodo_cercato, nodo_cancellato;

    list_insert(&head, 53);
    list_insert(&head, 86);
    list_insert(&head, 17);

    list_display(head);
    list_insert(&head, 12);
    list_display(head);

    // Cerca nodo con dato 34
    nodo_cercato = 34;
    if (list_search(head, nodo_cercato)) {
        printf("Nodo con dato %d trovato\n", nodo_cercato);
    } else {
        printf("Nodo con dato %d non trovato\n", nodo_cercato);
    }

    // Cerca nodo con dato 22
    nodo_cercato = 22;
    if (list_search(head, nodo_cercato)) {
        printf("Nodo con dato %d trovato\n", nodo_cercato);
    } else {
        printf("Nodo con dato %d non trovato\n", nodo_cercato);
    }

    // Cancella nodo con valore 86
    nodo_cancellato = 86;
    printf("Cancello nodo con dato %d\n", nodo_cancellato);
    list_delete(&head, nodo_cancellato);
    
    list_display(head);


    // Cancella nodo con valore 90
    nodo_cancellato = 90;
    printf("Cancello nodo con dato %d\n", nodo_cancellato);
    list_delete(&head, nodo_cancellato);

    // Cerca nodo con dato 12 
    nodo_cercato = 12;
    if (list_search(head, nodo_cercato)) {
        printf("Nodo con dato %d trovato\n", nodo_cercato);
    } else {
        printf("Nodo con dato %d non trovato\n", nodo_cercato);
    }

    return 0;
}