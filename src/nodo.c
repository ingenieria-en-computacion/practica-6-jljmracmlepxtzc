#include "nodo.h"
#include <stdlib.h>
#include <stdio.h>

Nodo *node_create(char d){
    Nodo *nodoNew = (Nodo*)malloc(sizeof(Nodo));
    nodeNew->data=d;
    nodeNew->next=NULL;
    return nodeNew;
}

void node_destroy(Nodo *n){
    if(n->next=NULL){
        free(n);
        n=NULL;
    }
}
void node_print(Nodo*n){
    printf("Data:%c\tNext:%p\n",n->data,n->next);
}