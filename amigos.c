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
void add_desconicido(){
    // 1. abrimos el fichero
    int num;
    user user1;
    user user2;
    user user3;
    int status = SUCCESS;
    FILE *f = fopen("f_users.txt","r");
    if (f == NULL) status = ERROR;
    if(status == SUCCESS){
        // 2. llamamos a la función para buscar aleatorio 3 veces
        num = rand() % 20;
        user1 = usuario_rdm(f,num);
        num = rand() % 20; //hay 19 users (empieza desde el 0) pero el ultimo número no lo incluye
        user2 = usuario_rdm(f,num);
        num = rand() % 20;
        user3 = usuario_rdm(f,num);
        // 3. Recorrer lista con pila
        Stack* p = init_stack();
        push(p, user1);
        push(p,user2);
        push(user3);

        // 4. Cerrar fichero --> la función de añadir usuario
        fclose(f);
        free_stack(p);
    }


}

