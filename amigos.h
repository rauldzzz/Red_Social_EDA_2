
#ifndef RED_SOCIAL_PROYECTO_AMIGOS_H
#define RED_SOCIAL_PROYECTO_AMIGOS_H
#include <stdlib.h>
#include <string.h>
#include "users.h"

typedef struct{
    int* stack;
    int top;
}Stack;

typedef struct{
    int head;
    int tail;
    int elements;
    int* A;
}Queue;

Stack* init_stack();

int is_full(Stack* p, int N );

int is_empty(Stack* p);

int top(Stack* p);

void push(Stack* p, int valor);

void free_stack(Stack* p);

void add_desconicido();

Queue* init_queue();

int is_full_q(Queue* q,int N);

int is_empty_q(Queue* q);

int first(Queue* q);

Queue* enqueue(Queue* q, int e, int N);

Queue* dequeue(Queue* q, int N);

#endif //RED_SOCIAL_PROYECTO_AMIGOS_H
