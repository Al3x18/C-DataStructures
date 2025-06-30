#include "queue.h"
#include "item.h"
#include <stdio.h>
#include "ex.h"

int main (void) {
    queue q = newQueue();
    queue q2 = newQueue();
    queue q3 = newQueue();

    item i1 = 1;
    item i2 = 4;
    item i3 = 5;
    item i4 = 9;

    item j1 = 9;
    item j2 = 5;
    item j3 = 4;
    item j4 = 1;
    
    item v1 = 1;
    item v2 = 4;
    item v3 = 9;
    item v4 = 1;
    item v5 = 9;
    item v6 = 1;
    item v7 = 1;
    item v8 = 1;
    item v9 = 9;
    //printf("Coda vuota?: %d\n", emptyQueue(q));

    enqueue(q, i1);
    enqueue(q, i2);
    enqueue(q, i3);
    enqueue(q, i4);

    enqueue(q2, j1);
    enqueue(q2, j2);
    enqueue(q2, j3);
    enqueue(q2, j4);

    enqueue(q3, v1);
    enqueue(q3, v2);
    enqueue(q3, v3);
    enqueue(q3, v4);
    enqueue(q3, v5);
    enqueue(q3, v6);
    enqueue(q3, v7);
    enqueue(q3, v8);
    enqueue(q3, v9);

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

    printf("Vicini: %d\n", vicini(q3, v4, v5));
    printf("Central Item: ");
    output_item(centralItem(q3));
    printf("\n");

    printf("Coda 3: ");
    printQueue(q3);

    return 0;
}