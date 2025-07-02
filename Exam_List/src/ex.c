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

item itemCentrale(list l) {
    if (emptyList(l)) return NULLITEM;

    int numEl = 0;
    int centro = 0;
    list tmp = l;
    item target = NULLITEM;

    while (!emptyList(tmp)) {
        numEl++;
        tmp = tailList(tmp);
    }

    centro = numEl / 2;

    tmp = l;
    for (int i = 0; i < centro; i++) {
        tmp = tailList(tmp);
    }

    target = getFirst(tmp);

    removeList(l, centro);

    return target;
}