#include <stdio.h>
#include "list.h"
#include "item.h"

int main() {
    list l;
    item val;
    int pos;

    printf("Test delle operazioni sulla lista\n");
    printf("--------------------------------\n\n");

    // Test creazione lista vuota
    printf("1. Creazione lista vuota\n");
    l = newList();
    printf("La lista è vuota? %s\n\n", emptyList(l) ? "Sì" : "No");

    // Test inserimento elementi
    printf("2. Inserimento di 5 elementi\n");
    l = inputList(5);
    printf("\nLista dopo l'inserimento:\n");
    outputList(l);
    printf("\n");

    // Test dimensione lista
    printf("3. Dimensione della lista: %d\n\n", sizeList(l));

    // Test ricerca elemento
    printf("4. Test ricerca elemento\n");
    printf("Inserisci un elemento da cercare: ");
    input_item(&val);
    pos = posItem(val, l);
    if (pos != -1) {
        printf("Elemento trovato in posizione %d\n\n", pos);
    } else {
        printf("Elemento non trovato\n\n");
    }

    // Test accesso elemento per posizione
    printf("5. Test accesso elemento per posizione\n");
    printf("Inserisci una posizione (0-%d): ", sizeList(l)-1);
    int posizione;
    scanf("%d", &posizione);
    val = getItem(posizione, l);
    if (val != NULLITEM) {
        printf("Elemento in posizione %d: ", posizione);
        output_item(val);
        printf("\n\n");
    } else {
        printf("Posizione non valida\n\n");
    }

    // Test inversione lista
    printf("6. Test inversione lista\n");
    l = reverseList(l);
    printf("Lista dopo l'inversione:\n");
    outputList(l);
    printf("\n");

    // Test inserimento in testa
    printf("7. Test inserimento in testa\n");
    printf("Inserisci un elemento da aggiungere in testa: ");
    input_item(&val);
    l = consList(val, l);
    printf("\nLista dopo l'inserimento in testa:\n");
    outputList(l);
    printf("\n");

    return 0;
} 