#include "prototipi.h"
#include <stdio.h>

int main() {
    libretto l1 = newLibretto(1010, "Rossi", "Mario");
    libretto l2 = newLibretto(11142, "Bianchi", "Luigi");
    libretto l3 = newLibretto(123256, "Neri", "Giovanni");

    esame e1 = {"Matematica", 28, "2024-01-01", NULL};
    esame e2 = {"Fisica", 24, "2024-01-02", NULL};
    esame e3 = {"Informatica", 30, "2024-01-03", NULL};

    esame e4 = {"POO", 28, "2024-01-04", NULL};
    esame e5 = {"Programmazione", 24, "2024-01-05", NULL};
    esame e6 = {"Algebra", 30, "2024-01-06", NULL};

    //esame e7 = {"Analisi", 28, "2024-01-07", NULL};
    //esame e8 = {"Geometria", 24, "2024-01-08", NULL};
    //esame e9 = {"Storia", 30, "2024-01-09", NULL};

    addEsame(&l1, e1);
    addEsame(&l1, e2);
    addEsame(&l1, e3);

    addEsame(&l2, e4);
    addEsame(&l2, e5);
    addEsame(&l2, e6);

    //addEsame(&l3, e7);
    //addEsame(&l3, e8);
    //addEsame(&l3, e9);

    printEsami(l1);
    printEsami(l2);
    printEsami(l3);

    esame *cercato = cercaEsame(l1, "Matematica");
    if (cercato != NULLITEM) {
        printf("Esame trovato: %s, %d, %s\n", cercato->nomeEsame, cercato->voto, cercato->data);
    } else {
        printf("Esame non trovato\n");
    }

    return 0;
}