#include "proto.h"
#include <stdio.h>

void dai_priorita(PQueue *q) {
    if (q->queue_size <= 1) return;

    //Find max priority
    int max_priority = q->items[0].priority;
    for (int i = 1; i < q->queue_size; i++) {
        if (q->items[i].priority > max_priority) {
            max_priority = q->items[i].priority;
        }
    }

    //Increment by 1 the priority of all items except the one with max priority
    for (int i = 0; i < q->queue_size; i++) {
        if (q->items[i].priority < max_priority) {
            q->items[i].priority += 1;
        }
    }
}

void enqueue(PQueue *q, int data, int priority) {
    if (q->queue_size >= MAX_QUEUE_SIZE) {
        printf("Queue is full\n");
        return;
    }

    q->items[q->queue_size].data = data;
    q->items[q->queue_size].priority = priority;
    q->queue_size++;

    order_by_priority(q);
}

void print_queue(PQueue *q) {
    for (int i = 0; i < q->queue_size; i++) {
        printf("| Data: %d, Priority: %d |", q->items[i].data, q->items[i].priority);
        // Print arrow only if it's not the last element
        if (i < q->queue_size - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int extract(PQueue *q, int data) {
    // Find the element with the specified data
    int pos = -1;
    for (int i = 0; i < q->queue_size; i++) {
        if (q->items[i].data == data) {
            pos = i;
            break;
        }
    }

    // If element not found, return 0
    if (pos == -1) {
        return 0;
    }

    // Shift all elements after the found position one position back
    for (int i = pos; i < q->queue_size - 1; i++) {
        q->items[i] = q->items[i + 1];
    }

    // Decrease queue size
    q->queue_size--;
    return 1;
}

void order_by_priority(PQueue *q) {
    // If queue is empty or has only one element, no need to sort
    if (q->queue_size <= 1) return;

    // Selection sort implementation
    for (int i = 0; i < q->queue_size - 1; i++) {
        // Find the element with highest priority in the unsorted portion
        int max_idx = i;
        for (int j = i + 1; j < q->queue_size; j++) {
            if (q->items[j].priority > q->items[max_idx].priority) {
                max_idx = j;
            }
        }
        
        // Swap the found element with the first element of unsorted portion
        if (max_idx != i) {
            queue_item temp = q->items[i];
            q->items[i] = q->items[max_idx];
            q->items[max_idx] = temp;
        }
    }
}

