#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__
#include <stdbool.h>
#include "nodo.h"

struct circularqueue{
    Nodo *head;
    Nodo *tail;
    int len;
};

typedef struct circularqueue CQueue;

CQueue *cqueue_create();
void cqueue_destroy(CQueue*);
void cqueue_print(CQueue*);
void cqueu_enqueue(CQueue*,char d);
void cqueue_dequeue(CQueue*);
char cqueue_first(CQueue* );
char cqueue_last(CQueue* );
bool cqueue_is_empty(CQueue* );
void cqueue_empty(CQueue* );

#endif