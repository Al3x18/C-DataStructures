#include <stdio.h>
#include <stdlib.h>

void inserisci_elemento(int arr[], int elem, int pos);
void inserisci_elemento_array_dinamico(int **arr, int *n, int elem, int pos);
void elimina_elemento_array_dinamico(int **arr, int *n, int pos);
void cerca_minimo(int arr[], int n);

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    int n = 5;
    int *arr_dinamico = (int *) malloc(n * sizeof(int));

    //Riempimento array dinamico
    for (int i = 0; i < n; i++) {
        arr_dinamico[i] = (i + 1) * 20;
    }
    
    inserisci_elemento(arr, 60, 1);
    //inserisci_elemento_array_dinamico(&arr_dinamico, &n, 70, 0);
    elimina_elemento_array_dinamico(&arr_dinamico, &n, 4);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr_dinamico[i]);
    }

    cerca_minimo(arr, n);

    return 0;
}

void inserisci_elemento(int arr[], int elem, int pos) {
    arr[pos] = elem;
}

/*
 * Questa funzione riceve un doppio puntatore (int **arr) perché:
 * - Vogliamo modificare direttamente l'array dinamico (aggiungere un elemento)
 * - Dopo la reallocazione con realloc, il puntatore potrebbe cambiare
 * - Passando un puntatore a puntatore, possiamo aggiornare il valore originale nel main
 *
 * Non sarebbe corretto usare int *arr[] (array di puntatori), perché:
 * - Anche se è sintatticamente simile a int **arr, non ci permette di modificare il puntatore originale
 * - Non potremmo assegnare *arr = realloc(...) con effetto visibile all'esterno della funzione
 */
void inserisci_elemento_array_dinamico(int **arr, int *n, int elem, int pos) {
    int *tmp = (int *)realloc(*arr, (*n + 1) * sizeof(int));

    if (tmp == NULL) {
        fprintf(stderr, "Memoria non disponibile\n");
        return;
    }

    // Assegniamo il nuovo puntatore all'array riallocato
    // *arr è di tipo int*, quindi gli assegniamo tmp (che è un int*)
    // Non va usato *tmp perché significherebbe accedere al primo valore dell'array, non al suo indirizzo
    *arr = tmp;
    
    // (*n)++ incrementa il valore puntato (cioè il numero di elementi nell'array)
    // Senza parentesi, *n++ incrementerebbe il puntatore stesso, non il suo contenuto
    (*n)++;

    for (int i = *n; i > pos; i--)
    {
        // (*arr) è necessario per dereferenziare il doppio puntatore prima di accedere con l'indice [i]
        // Senza parentesi, *arr[i] sarebbe interpretato come *(arr[i]), cioè accedere a un array di puntatori
        (*arr)[i] = (*arr)[i - 1];
    }
    
    (*arr)[pos] = elem;
}

/*
 * Questa funzione rimuove un elemento dall'array dinamico alla posizione specificata.
 * Riceve un doppio puntatore (int **arr) per consentire la modifica diretta dell'array.
 * Aggiorna il numero di elementi dopo l'eliminazione e rialloca la memoria.
 * Se la posizione è invalida, stampa un messaggio di errore.
 * Se la reallocazione fallisce, stampa un messaggio di memoria non disponibile.
 * 
 * Parametri:
 * - int **arr: doppio puntatore all'array dinamico
 * - int *n: puntatore al numero di elementi nell'array
 * - int pos: posizione dell'elemento da rimuovere
 */

void elimina_elemento_array_dinamico(int **arr, int *n, int pos) {
    if (pos > *n - 1 || pos < 0) {
        fprintf(stderr, "Indice non valido, eliminazione fallita\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++)
    {
        (*arr)[i] = (*arr)[i + 1];
    }

    int *tmp = (int *)realloc(*arr, (*n - 1) * sizeof(int));

    if (tmp == NULL) {
        fprintf(stderr, "Memoria non disponibile\n");
        return;
    }

    (*n)--;

    *arr = tmp;   
}

void cerca_minimo(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("\nIl minimo è: %d\n", min);
}