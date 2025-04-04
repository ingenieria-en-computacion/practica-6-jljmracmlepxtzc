#ifndef __CIRCULAR_QUEUE_ARRAY_H__
#define __CIRCULAR_QUEUE_ARRAY_H__
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int front;
    int rear;
    int size;
} CQueueArray;

CQueueArray* cqueue_array_create();
void cqueue_array_destroy(CQueueArray* q);
bool cqueue_array_is_empty(CQueueArray* q);
bool cqueue_array_is_full(CQueueArray* q);
void cqueue_array_enqueue(CQueueArray* q, char d);
char cqueue_array_dequeue(CQueueArray* q);
char cqueue_array_front(CQueueArray* q);
char cqueue_array_rear(CQueueArray* q);
void cqueue_array_print(CQueueArray* q);

#endif
