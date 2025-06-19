#include "proto.h"
#include <stdlib.h>
#include <stdio.h>

void add_element(list **l, int data) {
    list *new_elem = (list *)malloc(sizeof(list));

    new_elem->data = data;
    new_elem->next = *l;

    *l = new_elem;
}

void print_list(list *l) {
    while (l != NULL) {
        printf("%d -> ", l->data);
        l = l->next;
    }
    printf("NULL\n");
}

void print_pointer(list *l) {
    while (l != NULL) {
        printf("%p -> ", l);
        l = l->next;
    }
    printf("NULL\n");
}

void invert_list(list **l) {
    list *prev = NULL;
    list *current = *l;
    list *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *l = prev;
}

void invert_extremes(list **l) {
    if (*l == NULL || (*l)->next == NULL) {
        return;
    }

    list *first = *l;
    list *prev = NULL;
    list *current = *l;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    current->next = first->next;  //collega l'ultimo elemento al secondo elemento
    prev->next = first; //collega il penultimo elemento al primo elemento
    first->next = NULL; //il primo elemento diventa l'ultimo, quindi il suo next diventa NULL
    *l = current; //aggiorna l'inizio della lista per puntare al nuovo primo elemento
}