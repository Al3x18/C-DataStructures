#include "stack.h"
#include "item.h"
#include <stdio.h>
#include "ex.h"

int main(void) {
    stack s1 = newStack();
    stack s2 = newStack();

    push('a', s1);
    push('e', s1);
    push(5, s1);
    push('d', s1);
    push('f', s1);

    push('a', s2);
    push('e', s2);
    push(5, s2);
    push('d', s2);
    push('f', s2);

    push('g', s2);
    push('e', s2);
    push(4, s2);
    push('d', s2);
    push('d', s2);
    push('a', s2);
    push('p', s2);
    push(5, s2);
    push('k', s2);
    push('f', s2);

    printf("Il numero di duplicati è: %d\n", duplicati(s1, s2));

    printStack(s1);
    printStack(s2);

    return 0;
}