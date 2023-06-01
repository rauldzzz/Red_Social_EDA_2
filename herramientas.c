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
    //p->stack = (user *)malloc(sizeof(user));
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

char* top(Stack* p){
    if (is_empty(p) != TRUE) return &p->stack[p->top];
    else printf("\nLa pila esta llena\n");
}

Stack* push(Stack* p, char* valor) {
    if (is_full(p) != TRUE) {
        p->stack = realloc(p->stack, (p->top + 1) * sizeof(user));
        p->top++;
        p->stack[p->top] = *valor;
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


/**########################## FUNCIONES COLA ##########################*/
Queue* init_queue(){
    Queue* q = malloc(sizeof(Queue));
    //Alocar memeoria para A?
    q->A = (char**)malloc( MAX_USERS * sizeof(char*));
    for (int i = 0; i < MAX_USERS; ++i) {
        q->A[i] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
    }
    q->head = 0;
    q->tail = 0;
    q->elements = 0;
    return q;
}

int is_full_q(Queue* q){
    if(q->elements == MAX_USERS) return TRUE;
    return FALSE;
}

int is_empty_q(Queue* q){
    if (q->elements == 0)return TRUE;
    return FALSE;
}

char* first(Queue* q){
    if (is_empty_q(q) == TRUE) {
        printf("\nQueue is empty\n");
        //retornem error o algo?
    }
    else{
        return (q->A[q->head]);
    }
}

Queue* enqueue(Queue* q, char e[MAX_STRING_LENGTH]){
    if(is_full_q(q) == TRUE) {
        printf("Queue is full");
    }
    else{
        strcpy(q->A[q->head], e);
        q->head = q->head + 1;
        q->elements++;
    }
    return q;
}

Queue* dequeue(Queue* q){
    if(is_empty_q(q) == TRUE) {
        printf("Queue is empty");
    }
    else{
        q->head = q->head - 1;
        q->elements--;
    }
    return q;
}

Queue* enviar_solicitud_amistad( char nombre[MAX_STRING_LENGTH], Queue *cola_solicitudes_amigos){
    return enqueue(cola_solicitudes_amigos, nombre);
}

Queue* recibir_solicitud_amistad(user usuario){
    if (is_empty_q(usuario.solicitudes_amistad) == TRUE){
        printf("\nNo tienes solicitudes de amistad ;(\n");
        return usuario.solicitudes_amistad;
    }
    char option;
    for (int i = 0; i < usuario.solicitudes_amistad->elements;) {
        printf("\nQuieres aceptar la solicitud de amistad de %s?", usuario.solicitudes_amistad->A[i]);
        scanf("%c", &option);
        if (option == '0') break;
        else if (option == 'Y'){
            usuario.lista_amigos[usuario.cantidd_amigos] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
            usuario.lista_amigos[usuario.cantidd_amigos] = first(usuario.solicitudes_amistad);
            usuario.cantidd_amigos++;
            dequeue(usuario.solicitudes_amistad);

        }
        else if (option == 'N'){
            dequeue(usuario.solicitudes_amistad);
        }
        else{
            printf("\nOPCION INCORRECTA\n");
            printf("\nPulsa '0' para salir de las solicitudes de amistad, escribe 'Y' para acepar y 'N' para rechazar las solicitudes de amistad\n");
        }
    }
    return usuario.solicitudes_amistad;
}

/**#####################################################################*/