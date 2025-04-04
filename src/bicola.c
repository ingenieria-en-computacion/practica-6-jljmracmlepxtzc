#include "bicola_generic.h"
#include <stdio.h>
#include <stdlib.h>

BiQueueGeneric* biqueue_generic_create() {
    BiQueueGeneric* q = (BiQueueGeneric*)malloc(sizeof(BiQueueGeneric));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void biqueue_generic_destroy(BiQueueGeneric* q) {
    free(q);
}

bool biqueue_generic_is_empty(BiQueueGeneric* q) {
    return q->size == 0;
}

bool biqueue_generic_is_full(BiQueueGeneric* q) {
    return q->size == MAX_SIZE;
}

void biqueue_generic_enqueue_front(BiQueueGeneric* q, void* d) {
    if (biqueue_generic_is_full(q)) {
        printf("Bicola llena\n");
        return;
    }
    q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
    q->data[q->front] = d;
    if (q->rear == -1) q->rear = q->front;  // Si es el primer elemento
    q->size++;
}

void biqueue_generic_enqueue_rear(BiQueueGeneric* q, void* d) {
    if (biqueue_generic_is_full(q)) {
        printf("Bicola llena\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = d;
    if (q->front == -1) q->front = q->rear;  // Si es el primer elemento
    q->size++;
}

void* biqueue_generic_dequeue_front(BiQueueGeneric* q) {
    if (biqueue_generic_is_empty(q)) {
        printf("Bicola vacía\n");
        return NULL;
    }
    void* value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return value;
}

void* biqueue_generic_dequeue_rear(BiQueueGeneric* q) {
    if (biqueue_generic_is_empty(q)) {
        printf("Bicola vacía\n");
        return NULL;
    }
    void* value = q->data[q->rear];
    q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    q->size--;
    return value;
}

void* biqueue_generic_front(BiQueueGeneric* q) {
    if (biqueue_generic_is_empty(q)) return NULL;
    return q->data[q->front];
}

void* biqueue_generic_rear(BiQueueGeneric* q) {
    if (biqueue_generic_is_empty(q)) return NULL;
    return q->data[q->rear];
}

void biqueue_generic_print(BiQueueGeneric* q, void (*print_func)(void*)) {
    if (biqueue_generic_is_empty(q)) {
        printf("Bicola vacía\n");
        return;
    }
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_SIZE;
        print_func(q->data[index]);
    }
    printf("\n");
}
