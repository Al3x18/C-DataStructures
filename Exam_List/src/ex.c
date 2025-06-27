#include "ex.h"
#include <stdlib.h>

item max_duplicazioni(list l) {
    if (emptyList(l)) {
        return NULLITEM;
    }

    int max_count = 0;
    item max_item = getFirst(l);
    list outer = l;

    while (!emptyList(outer)) {
        item current = getFirst(outer);
        int count = 0;
        list inner = l;

        while (!emptyList(inner)) {
            if (eq(getFirst(inner), current)) {
                count++;
            }

            inner = tailList(inner);
        }

        if (count > max_count) {
            max_count = count;
            max_item = current;
        }

        outer = tailList(outer);
    }
    
    return max_item;
}