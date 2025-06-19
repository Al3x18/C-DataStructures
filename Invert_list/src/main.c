#include "proto.h"
#include <stdio.h>

int main(void) {
    list *l = NULL;

    add_element(&l, 5);
    add_element(&l, 9);
    add_element(&l, 4);
    add_element(&l, 1);

    print_list(l);
    invert_extremes(&l);
    print_list(l);

    return 0;
}