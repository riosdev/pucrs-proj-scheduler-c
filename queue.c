#include "t1.h"
#include "stdlib.h"

void push(Queue * q, TAREFA * t){
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    node->tarefa = t;
    if(q->head == NULL){
        q->head = node;
    }
    else{
        Node *aux = q->tail;
        aux->next = node;
    }
    q->tail = node;
}

TAREFA *pop(Queue *q){
    Node *node = NULL;
    if(q->head != NULL){
        node = q->head;
        q->head = node->next;
        return node->tarefa;
    }
    return NULL;
}

TAREFA *peek(Queue q){
    return q.head != NULL ? q.head->tarefa : NULL;
}

int size(Queue* q){
    int i = 0; 
    Node *n = q->head;
    while(n != NULL){
        n = n->next;
        i++;
    }
    return i;
}