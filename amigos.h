
#ifndef RED_SOCIAL_PROYECTO_AMIGOS_H
#define RED_SOCIAL_PROYECTO_AMIGOS_H
#include <stdlib.h>
#include <string.h>
#include "users.h"

typedef struct{
    int* stack;
    int top;
}Stack;

Stack* init_stack();

int is_full(Stack* p, int N );

int is_empty(Stack* p);

int top(Stack* p);

void push(Stack* p, int valor);

void free_stack(Stack* p);



#endif //RED_SOCIAL_PROYECTO_AMIGOS_H
