#include "proto.h"
#include <stdio.h>

int main (void) {
    PQueue q;
    q.queue_size = 0;

    enqueue(&q, 1, 3);
    enqueue(&q, 2, 1);
    enqueue(&q, 3, 2);
    enqueue(&q, 10, 6);

    print_queue(&q);
    dai_priorita(&q);

    print_queue(&q);

    extract(&q, 10);
    print_queue(&q);

    return 0;
}