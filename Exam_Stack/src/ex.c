#include "ex.h"
#include <stdlib.h>

int duplicati(stack s1, stack s2) {
    if (emptyStack(s1) || emptyStack(s2)) return 0;

    int count = 0;
    
    stack tmpS1 = newStack();
    stack tmpS2 = newStack();

    // Primo ciclo: copio tutti gli elementi di s1 in tmpS1
    // In questo modo posso poi ripristinare s1 e scorrere i suoi elementi senza perderli
    while (!emptyStack(s1)) {
        item currentS1 = top(s1);
        push(currentS1, tmpS1);
        pop(s1);
    }

    /*
    Secondo ciclo: ripristino s1 e, per ogni elemento di s1 (che ora prendo da tmpS1),
    conto quante volte compare in s2. Per ogni elemento di tmpS1:
    - lo reinserisco in s1 (così alla fine s1 torna come prima)
    - scorro tutti gli elementi di s2 (spostandoli temporaneamente in tmpS2)
    - confronto ogni elemento di s2 con quello corrente di s1 usando eq()
    - incremento count se trovo una corrispondenza
    - alla fine ripristino s2 da tmpS2
    */
    while (!emptyStack(tmpS1)) {
        item currentS1 = top(tmpS1);
        push(currentS1, s1);
        pop(tmpS1);

        // Terzo ciclo: scorro tutti gli elementi di s2, spostandoli in tmpS2
        // e confronto ciascun elemento con currentS1
        while (!emptyStack(s2)) {
            item currentS2 = top(s2);
            push(currentS2, tmpS2);
            pop(s2);

            if (eq(currentS1, currentS2)) count++;
        }

        // Quarto ciclo: ripristino s2 spostando tutti gli elementi da tmpS2 a s2
        while (!emptyStack(tmpS2)) {
            item currentS2 = top(tmpS2);
            push(currentS2, s2);
            pop(tmpS2);
        }
    }

    free(tmpS1);
    free(tmpS2);

    return count;
}