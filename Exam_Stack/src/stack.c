#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    item value;
    struct node *next;
} node;

struct c_stack {
    struct node *top;
    int numel;
};

stack newStack(void) {
    stack s;
    s = (struct c_stack *)malloc(sizeof(struct c_stack));
    
    if(s == NULL) return NULL;

    s->top = NULL;
    s->numel = 0;

    return s;
}

int emptyStack(stack s) {
    return s->numel == 0;
}

int push(item val, stack s) {
    node *newNode;
    newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL) return 0;

    newNode->value = val;
    newNode->next = s->top;

    s->top = newNode;
    (s->numel)++;

    return 1;
}

int pop(stack s) {
    if (emptyStack(s)) return 0;

    node *tmp = s->top;
    s->top = s->top->next;

    free(tmp);
    (s->numel)--;

    return 1;
}

item top(stack s) {
    item e;

    if (emptyStack(s)) {
        e = NULLITEM;
    } else {
        e = s->top->value;
    }

    return e;
}

void printStack(stack s) {
    node *current = s->top;
    while (current != NULL) {
        printf("|%d|", current->value);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("\n");
}