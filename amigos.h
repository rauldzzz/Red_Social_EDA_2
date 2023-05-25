
#ifndef RED_SOCIAL_PROYECTO_AMIGOS_H
#define RED_SOCIAL_PROYECTO_AMIGOS_H
#include <stdlib.h>
#include <string.h>
#include "users.h"

/**########################## FUNCIONES PILA ##########################*/

#define MAX_STACK 20

typedef struct{
    char *stack;
    int top;
}Stack;

typedef struct{
    int head;
    int tail;
    int elements;
    char* A;
}Queue;

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

Queue* enqueue(Queue* q, char* e);

Queue* dequeue(Queue* q);

Queue* enviar_solicitud_amistad( char* nombre, Queue* cola_amigos);
/**#####################################################################*/




#endif //RED_SOCIAL_PROYECTO_AMIGOS_H
