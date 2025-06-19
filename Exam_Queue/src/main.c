#include "queue.h"
#include "item.h"
#include <stdio.h>
#include "ex.h"

int main (void) {
    queue q = newQueue();

    item i1 = 1;
    item i2 = 4;
    item i3 = 5;
    item i4 = 9;
    
    printf("Coda vuota?: %d\n", emptyQueue(q));

    enqueue(q, i1);
    enqueue(q, i2);
    enqueue(q, i3);
    enqueue(q, i4);

    printf("Coda vuota?: %d\n", emptyQueue(q));

    printQueue(q);
    
    saltaCoda(q, i2);
    printf("\n");
    printQueue(q);

    return 0;
}