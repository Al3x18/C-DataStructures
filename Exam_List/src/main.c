#include "list.h"
#include "ex.h"
#include <stdio.h>

int main(void) {
    list l = newList();

    l = consList(1, l);
    l = consList(2, l);
    l = consList(1, l);
    l = consList(4, l);
    l = consList(5, l);
    l = consList(6, l);
    l = consList(7, l);
    l = consList(8, l);
    l = consList(1, l);
    l = consList(5, l);
    l = consList(10, l);

    outputList(l);

    item centrale = itemCentrale(l);

    printf("l'item con il numero di duplicazioni massimo è: %d\n", max_duplicazioni(l));
    printf("L'item centrale della lista è: %d\n", centrale);

    outputList(l);

    return 0;
}