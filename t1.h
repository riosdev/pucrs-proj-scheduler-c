#ifndef T1_H
#define T1_H

#define MAX_TAREFAS 26
#define MAX_GRADE   8192
/* #define DEBUG */

typedef struct {
	char	 id;
	unsigned c;
	unsigned s;
	unsigned p;
	unsigned sched;
}  TAREFA;

typedef struct Node{
    TAREFA *tarefa;
    struct Node *next;
} Node;

typedef struct {
    Node *head, *tail;
} Queue;

void push(Queue * q, TAREFA * t);
TAREFA *pop(Queue *q);
TAREFA *peek(Queue q);
int _size(Node *n);
int size(Queue *q);

#endif