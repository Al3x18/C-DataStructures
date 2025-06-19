#include "prototipi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

libretto newLibretto(int matricola, char* cognome, char* nome) {
    libretto l;
    l.matricola = matricola;
    strncpy(l.cognome, cognome, MAX_NOME);
    strncpy(l.nome, nome, MAX_NOME);
    l.headListaEsami = NULL;
    return l;
}

void addEsame(libretto *l, esame e) {
  //Allocazione memoria per il nuovo nodo esame
    esame *nuovo = (esame*)malloc(sizeof(esame));
    
    if (nuovo != NULL) {
        strncpy(nuovo->nomeEsame, e.nomeEsame, MAX_NOME);
        nuovo->voto = e.voto;
        strncpy(nuovo->data, e.data, MAX_DATA);

        /*
          Inserimento in testa alla lista:
          Supponiamo che la lista contenga già:
            [Informatica] -> [Fisica] -> NULL

          Quando aggiungiamo "Matematica", vogliamo che diventi il nuovo primo esame.

          Passaggi:
          - nuovo->next = l->headListaEsami;
            Il nuovo esame punta al primo esame attuale (Informatica).
          - l->headListaEsami = nuovo;
            Cambiamo la testa della lista: ora punta a "Matematica".

          Risultato finale:
            [Matematica] -> [Informatica] -> [Fisica] -> NULL

          In questo modo, la testa della lista viene aggiornata per includere l'esame più recente in prima posizione.
        */
        nuovo->next = l->headListaEsami;
        l->headListaEsami = nuovo;
    }
}

void printEsami(libretto l) {
    printf("Esami di %s %s (matricola: %d):\n", l.cognome, l.nome, l.matricola);
    esame *current = l.headListaEsami;

    if (current == NULL) {
        printf("Nessun esame registrato\n\n");
        return;
    }

    while (current != NULL) {
        printf("%s %d %s\n", current->nomeEsame, current->voto, current->data);
        current = current->next;  //Passo al puntatore del prossimo esame
    }
    printf("\n");
}

esame* cercaEsame(libretto l, char* nomeEsame) {
    esame *current = l.headListaEsami;
    while (current != NULL) {
        if (strcmp(current->nomeEsame, nomeEsame) == 0) {
            return current;
        }
        //Passo al puntatore del prossimo esame
        current = current->next;
    }
    return NULLITEM;
}