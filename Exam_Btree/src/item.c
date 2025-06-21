#include "item.h"
#include <stdio.h>

int eq(item a, item b) {
    return a == b;
}

void output_item(item a) {
    printf("%d", a);
}

void input_item(item *a) {
    scanf("%d", a);
}