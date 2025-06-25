#include "item.h"
#include <stdio.h>

int eq(item a, item b) {
    return a == b;
}

void outputItem(item a) {
    printf("%d", a);
}

void inputItem(item *a) {
    scanf("%d", a);
}