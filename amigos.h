
#ifndef RED_SOCIAL_PROYECTO_AMIGOS_H
#define RED_SOCIAL_PROYECTO_AMIGOS_H
#include <stdlib.h>
#include <string.h>
#include "users.h"

/**########################## FUNCIONES PILA ##########################*/

#define MAX_STACK 20

typedef struct{
    user *stack;
    int top;
}Stack;

Stack* init_stack();

int is_full(Stack* p);

int is_empty(Stack* p);

user top(Stack* p);

Stack* push(Stack* p, user valor);

Stack* pop(Stack* p);

void free_stack(Stack* p);

void add_desconicido();

/**#####################################################################*/




#endif //RED_SOCIAL_PROYECTO_AMIGOS_H
