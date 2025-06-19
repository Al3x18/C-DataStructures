#include "vettore.h"
#include <stdio.h>
#include <stdlib.h>

void finput_array(char *file_name, int a[], int n) {
    int i;
    FILE *fd;

    fd = fopen(file_name, "r");
    if (fd == NULL) {
        printf("Errore nell'apertura del file: %s\n", file_name);
        exit(1);
    } else {
        for(i = 0; i < n; i++) {
            fscanf(fd, "%d", &a[i]);
        }
    }
    fclose(fd);
}

void foutput_array(char *file_name, int a[], int n) {
    int i;
    FILE *fd;

    fd = fopen(file_name, "w");
    if (fd == NULL) {
        printf("Errore nella creazione del file: %s\n", file_name);
        exit(1);
    } else {
        for(i = 0; i < n; i++) {
            fprintf(fd, "%d ", a[i]);
        }
    }
    fclose(fd);
}

int confronta_array(int a[], int b[], int n) {
    int i = 0;
    int trovato_diff = 0;

    while (i < n &&!trovato_diff) {
        if (a[i] != b[i]) {
            trovato_diff = 1;
        }
        i++;
    }
    return (trovato_diff) ? 0 : 1;
}

void ordina_array(int a[], int n) {
    // Insertion sort
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}