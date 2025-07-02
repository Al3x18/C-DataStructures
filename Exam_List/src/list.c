#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct node
{
    item value;
    struct node *next;
};

list newList(void)
{
    return NULL;
}

int emptyList(list l)
{
    return l == NULL;
}

list consList(item val, list l)
{
    struct node *nuovo;
    nuovo = (struct node *)malloc(sizeof(struct node));

    if (nuovo != NULL)
    {
        nuovo->value = val;
        nuovo->next = l;
        l = nuovo;
    }
    return l;
}

list tailList(list l)
{
    list temp;
    if (l != NULL)
    {
        temp = l->next;
    }
    else
    {
        temp = NULL;
    }
    return temp;
}

item getFirst(list l)
{
    item e;
    if (l != NULL)
    {
        e = l->value;
    }
    else
    {
        e = NULLITEM;
    }
    return e;
}

void outputList(list l)
{
    int i = 0;
    item val;

    while (!emptyList(l))
    {
        val = getFirst(l);
        printf("Elemento di posizione %d: ", i);
        outputItem(val);
        printf("\n");
        l = tailList(l);
        i++;
    }
}

list removeList(list l, int pos) {
    list l1, prec; // puntatore al nodo da eliminare
    int i;

    if (pos == 0 && l != NULL) { // eliminazione in posizione 0
        l1 = l;
        l = tailList(l);
        free(l1);
    } else {
        // se non dobbiamo cancellare in posizione 0, scorriamo
        // la lista fino alla posizione precedente a quella del
        // nodo da eliminare
        i = 0;
        prec = l;
        while (i < pos - 1 && prec != NULL) {
            prec = prec->next;
            i++;
        }
         /* alla fine del ciclo, se prec != NULL allora prec->next punta al nodo da
        eliminare. Se prec->next != NULL allora il nodo si può eliminare */

        if (prec != NULL && prec->next != NULL) { // short-circuit evaluation
            l1 = prec->next;
            prec->next = l1->next;
            free(l1);
        }
    }

    return l;
}