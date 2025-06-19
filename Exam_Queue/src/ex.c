#include "ex.h"
#include <stdlib.h>

int saltaCoda(queue q, item i) {
    if (q == NULL || emptyQueue(q)) {
        return 0;
    }

    queue temp = newQueue();
    item current;
    int found = 0;
    item target = NULLITEM;

    // Find the item and store it
    while (!emptyQueue(q)) {
        current = dequeue(q);
        if (!found && eq(current, i)) {
            target = current;
            found = 1;
        } else {
            enqueue(temp, current);
        }
    }

    // If item was found, put it at the front
    if (found) {
        enqueue(q, target);
    }

    // Put back all other elements in their original order
    while (!emptyQueue(temp)) {
        current = dequeue(temp);
        enqueue(q, current);
    }

    // Free temporary queue
    free(temp);

    return found ? 1 : 0;
}