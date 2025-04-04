#ifndef __BICOLA_GENERIC_H__
#define __BICOLA_GENERIC_H__
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    void* data[MAX_SIZE];  // Usamos void* para permitir cualquier tipo de dato
    int front;
    int rear;
    int size;
} BiQueueGeneric;

BiQueueGeneric* biqueue_generic_create();
void biqueue_generic_destroy(BiQueueGeneric* q);
bool biqueue_generic_is_empty(BiQueueGeneric* q);
bool biqueue_generic_is_full(BiQueueGeneric* q);
void biqueue_generic_enqueue_front(BiQueueGeneric* q, void* d);
void biqueue_generic_enqueue_rear(BiQueueGeneric* q, void* d);
void* biqueue_generic_dequeue_front(BiQueueGeneric* q);
void* biqueue_generic_dequeue_rear(BiQueueGeneric* q);
void* biqueue_generic_front(BiQueueGeneric* q);
void* biqueue_generic_rear(BiQueueGeneric* q);
void biqueue_generic_print(BiQueueGeneric* q, void (*print_func)(void*));

#endif
