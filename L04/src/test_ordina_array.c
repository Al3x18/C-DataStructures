#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Numero parametri non corretto\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    int *a = (int *)calloc(n, sizeof(int));

    if (a == NULL) {
        printf("Errore nell'allocazione della memoria\n");
        exit(1);
    }

    finput_array(argv[2], a, n);
    ordina_array(a, n);
    foutput_array(argv[4], a, n);

    int *oracle = (int *)calloc(n, sizeof(int));

    if (oracle == NULL) {
        printf("Errore nell'allocazione della memoria oracle main\n");
        exit(1);
    }

    finput_array(argv[3], oracle, n);

    if (confronta_array(a, oracle, n)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
    
    free(a);
    free(oracle);
    return 0;
}