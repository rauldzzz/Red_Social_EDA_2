
#ifndef RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
#define RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
#include "users.h"
/**########################## FUNCIONES PILA ##########################*/

#define MAX_STACK 20
#define MAX_STRING_LENGTH 50

typedef struct{
    int head;
    int tail;
    int elements;
    char** A;
}Queue;

typedef struct{
    char *stack;
    int top;
}Stack;

Stack* init_stack();

int is_full(Stack* p);

int is_empty(Stack* p);

char* top(Stack* p);

Stack* push(Stack* p, char* valor);

Stack* pop(Stack* p);

void free_stack(Stack* p);

void add_desconicido();

Queue* init_queue();

int is_full_q(Queue* q);

int is_empty_q(Queue* q);

char* first(Queue* q);

Queue* enqueue(Queue* q, char e[MAX_STRING_LENGTH]);

Queue* dequeue(Queue* q);

#endif //RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
