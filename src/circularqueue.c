#include "circularqueue.h"
#include <stdlib.h>
#include <stdio.h>

// Crear la cola
CQueue *cqueue_create() {
    CQueue *newQueue = (CQueue *)malloc(sizeof(CQueue));
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->len = 0;
    return newQueue;
}

// Verifica si está vacía
bool cqueue_is_empty(CQueue *q) {
    return q->len == 0;
}

// Vaciar la cola
void cqueue_empty(CQueue *q) {
    while (!cqueue_is_empty(q)) {
        cqueue_dequeue(q);
    }
}

// Destruir la cola
void cqueue_destroy(CQueue *q) {
    if (!q) return;
    cqueue_empty(q);
    free(q);
}

// Imprimir la cola
void cqueue_print(CQueue *q) {
    if (cqueue_is_empty(q)) {
        printf("Cola vacía\n");
        return;
    }

    Nodo *tmp = q->head;
    int count = 0;
    do {
        node_print(tmp);
        printf(" ");
        tmp = tmp->next;
        count++;
    } while (tmp != q->head && count < q->len);
    printf("\n");
}

// Encolar un dato
void cqueue_enqueue(CQueue *q, char d) {
    Nodo *newNode = node_create(d);
    if (cqueue_is_empty(q)) {
        q->head = q->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = q->head;
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->len++;
}

// Desencolar
void cqueue_dequeue(CQueue *q) {
    if (cqueue_is_empty(q)) {
        printf("Cola vacía\n");
        return;
    }

    Nodo *tmp = q->head;
    if (q->len == 1) {
        q->head = q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->tail->next = q->head;
    }

    node_destroy(tmp);
    q->len--;
}

// Primer elemento
char cqueue_first(CQueue *q) {
    if (!q || cqueue_is_empty(q)) return '\0';
    return q->head->data;
}

// Último elemento
char cqueue_last(CQueue *q) {
    if (!q || cqueue_is_empty(q)) return '\0';
    return q->tail->data;
}
