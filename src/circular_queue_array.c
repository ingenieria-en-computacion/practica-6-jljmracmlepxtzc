#include "circular_queue_array.h"
#include <stdio.h>
#include <stdlib.h>

CQueueArray* cqueue_array_create() {
    CQueueArray* q = (CQueueArray*)malloc(sizeof(CQueueArray));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void cqueue_array_destroy(CQueueArray* q) {
    free(q);
}

void cqueue_array_is_empty(CQueueArray* q) {
    return q->size == 0;
}

bool cqueue_array_is_full(CQueueArray* q) {
    return q->size == MAX_SIZE;
}

void cqueue_array_enqueue(CQueueArray* q, char d) {
    if (cqueue_array_is_full(q)) {
        printf("Cola llena\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = d;
    q->size++;
}

char cqueue_array_dequeue(CQueueArray* q) {
    if (cqueue_array_is_empty(q)) {
        printf("Cola vacía\n");
        return '\0';
    }
    char value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return value;
}

char cqueue_array_front(CQueueArray* q) {
    if (cqueue_array_is_empty(q)) return '\0';
    return q->data[q->front];
}

char cqueue_array_rear(CQueueArray* q) {
    if (cqueue_array_is_empty(q)) return '\0';
    return q->data[q->rear];
}

void cqueue_array_print(CQueueArray* q) {
    if (cqueue_array_is_empty(q)) {
        printf("Cola vacía\n");
        return;
    }
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_SIZE;
        printf("%c ", q->data[index]);
    }
    printf("\n");
}
