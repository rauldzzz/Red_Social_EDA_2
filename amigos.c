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
    p->stack = (user *)malloc(sizeof(user));
    p->top = 0;
    return p;
}

int is_full(Stack* p){ //   N es la capacidad maxima de la pila A[1...N]
    if ( p->top == MAX_STACK){
        return TRUE;
    }
    return FALSE;
}

int is_empty(Stack* p){
    if (p->top == 0){
        return TRUE;
    }
    return FALSE;
}

user top(Stack* p){
    if (is_empty(p) != TRUE) return p->stack[p->top];
    else printf("\nLa pila esta llena\n");
}

Stack* push(Stack* p, user valor) {
    if (is_full(p) != TRUE) {
        p->stack = realloc(p->stack, (p->top + 1) * sizeof(user));
        p->top++;
        p->stack[p->top] = valor;
    } else {
        printf("\nLa pila esta llena\n");
    }
    return p;
}

Stack* pop(Stack* p) {
    if (is_empty(p) != TRUE) {
        p->stack = realloc(p->stack, (p->top - 1) * sizeof(user));
        p->top--;
    } else {
        printf("\nLa pila esta vacia\n");
    }
    return p;
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

/**########################## FUNCIONES COLA ##########################*/
Queue* init_queue(){
    Queue* q = malloc(sizeof(Queue));
    //Alocar memeoria para A?
    q->A = malloc( MAX_USERS * sizeof(user));
    if (q->A == NULL) {
        free(q);
        return NULL;
    }
    q->head = 1;
    q->tail = 1;
    q->elements = 0;
    return q;
}
int is_full_q(Queue* q){
    return(q->elements == MAX_USERS);
}
int is_empty_q(Queue* q){
    return(q->elements == 0);
}
user* first(Queue* q){
    if (is_empty_q(q)) {
       printf("Queue is empty");
       //retornem error o algo?
    }
    else{
        return &(q->A[q->head]);
    }
}
Queue* enqueue(Queue* q, user* e){
    if(q->elements == MAX_USERS) {
        printf("Queue is full");
    }
    else{
        q->A[q->tail] = *e;
        q->tail = q->tail + 1;
        if(q->tail > MAX_USERS){
            q->tail = 1;
            q->elements = q->elements + 1;
        }
    }
    return q;
}
Queue* dequeue(Queue* q){
    if(is_empty_q(q)) {
        printf("Queue is empty");
    }
    else{
        q->head = q->head + 1;
        if(q->head > MAX_USERS){
            q->head = 1;
            q->elements = q->elements - 1;
        }
    }
    return q;
}
/**#####################################################################*/
