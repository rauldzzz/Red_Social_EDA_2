#include <stdio.h>
#include "users.h"
#include "amigos.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "time.h"

/**########################## FUNCIONES PILA ##########################*/
Stack* init_stack(){
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->stack = NULL;
    p->top = 0;
    return p;
}

int is_full(Stack* p, int N ){ //   N es la capacidad maxima de la pila A[1...N]
    return( p->top == N);
}

int is_empty(Stack* p){
    return(p->top == 0);
}

int top(Stack* p){
    if (!is_empty(p)) return p->stack[p->top];
    else{
        //LA PILA ESTA VACIA!!!!
        return ERROR;
    }
}
void push(Stack* p, int valor) {
    p->stack = realloc(p->stack, (p->top + 1) * sizeof(int));
    p->stack[p->top] = valor;
    p->top++;
}

void free_stack(Stack* p) {
    free(p->stack);
    free(p);
}
/**#####################################################################*/

void seleccionar_usuarios(user_list* user,Stack* p){
    int usuario;
    //1. mirar si son amigos o no
    //2. si no lo son, añadir a la pila
    push(p, usuario);

}


