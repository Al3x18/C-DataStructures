#include "queue.h"
#include "item.h"
#include <stdio.h>
#include "ex.h"

int main (void) {
    queue q = newQueue();
    queue q2 = newQueue();

    item i1 = 1;
    item i2 = 4;
    item i3 = 5;
    item i4 = 9;

    item j1 = 9;
    item j2 = 5;
    item j3 = 4;
    item j4 = 1;
    
    //printf("Coda vuota?: %d\n", emptyQueue(q));

    enqueue(q, i1);
    enqueue(q, i2);
    enqueue(q, i3);
    enqueue(q, i4);

    enqueue(q2, j1);
    enqueue(q2, j2);
    enqueue(q2, j3);
    enqueue(q2, j4);

    //printf("Coda vuota?: %d\n", emptyQueue(q));

    // printQueue(q);
    
    // skipQueue(q, i2);
    // printf("\n");
    // printQueue(q);

    printf("Speculare: %d\n", speculare(q, q2));
    printf("Coda 1: ");
    printQueue(q);
    printf("Coda 2: ");
    printQueue(q2);

    return 0;
}