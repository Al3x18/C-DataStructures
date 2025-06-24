#include "item.h"
#include <stdio.h>

int eq(item a, item b) {
    return a == b;
}

int inputItem(item *a) {
    return scanf("%d", a);
}

int outputItem(item a) {
    return printf("%d", a);
}