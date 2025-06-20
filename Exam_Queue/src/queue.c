#include "queue.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    item data;
    struct node *next;
} node;

typedef struct c_queue {
    struct node *head, *tail;
    int numel;
} c_queue;

queue newQueue(void) {
    c_queue *q;
    q = (c_queue *)malloc(sizeof(c_queue));

    if (q == NULL) return NULL;

    q->numel = 0;
    q->head = NULL;
    q->tail = NULL;

    return q;
}

int emptyQueue(queue q) {
    if (q == NULL) return -1;

    return q->numel == 0;
}

int enqueue(queue q, item val) {
    node *nuovo;
    nuovo = (node *)malloc(sizeof(node));

    if (nuovo == NULL) return -1;

    nuovo->data = val;
    nuovo->next = NULL;

    //caso coda vuota
    if (q->head == NULL) {
        q->head = nuovo;
    } else {
        q->tail->next = nuovo; //caso coda non vuota
    }

    q->tail = nuovo;
    (q->numel)++;

    return 1;
}

item dequeue(queue q) {
    if (q == NULL) return NULLITEM;

    if (q->numel == 0) return NULLITEM;

    item result = q->head->data; //elemento da restituire

    node *temp = q->head; //nodo da eliminare

    q->head = q->head->next; //la testa avanza di 1
    free(temp); //libero il nodo

    if (q->head == NULL) q->tail = NULL; //se la coda conteneva un solo elemento, la coda punta a NULL

    (q->numel)--; //diminuisco il numero di elementi

    return result;
}

void printQueue(queue q) {
    node* current = q->head;
    
    printf("HEAD-> ");
    
    while(current != NULL) {
        output_item(current->data);
        current = current->next;
    }
    printf("<-TAIL");
    printf("\n");
}