#include <stdio.h>
#include "users.h"
#include "amigos.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "time.h"

/**########################## FUNCIONES PILA ##########################*/
// Inicializa una pila vacía
Stack* init_stack(){
    Stack* p = (Stack*)malloc(sizeof(Stack)); // Asigna memoria para la estructura de la pila
    p->stack = (user *)malloc(sizeof(user)); // Inicializa el puntero superior en 0 (pila vacía)
    p->top = 0;
    return p;
}

// Verifica si la pila está llena
int is_full(Stack* p){ //   N es la capacidad maxima de la pila A[1...N]
    if ( p->top == MAX_STACK){ // Compara el puntero superior con la capacidad máxima de la pila
        return TRUE; // Si el puntero superior es igual a la capacidad máxima, la pila está llena
    }
    return FALSE; // Si no, la pila no está llena
}

// Verifica si la pila está vacía
int is_empty(Stack* p){
    if (p->top == 0){ // Compara el puntero superior con 0 (pila vacía)
        return TRUE; // Si el puntero superior es igual a 0, la pila está vacía
    }
    return FALSE; // Si no, la pila no está vacía
}
// Devuelve el elemento superior de la pila
char* top(Stack* p){
    if (is_empty(p) != TRUE) return &p->stack[p->top]; // Si la pila no está vacía, devuelve el elemento superior
    else printf("\nLa pila esta llena\n"); // Si la pila está vacía, imprime un mensaje de error
}

// Inserta un elemento en la parte superior de la pila (push)
Stack* push(Stack* p, char* valor) {
    if (is_full(p) != TRUE) {
        p->stack = realloc(p->stack, (p->top + 1) * sizeof(user)); // Aumenta el tamaño de la memoria asignada para la pila
        p->top++; // Incrementa el puntero superior
        p->stack[p->top] = *valor; // Asigna el valor al elemento superior
    } else {
        printf("\nLa pila esta llena\n"); // Si la pila está llena, imprime un mensaje de error
    }
    return p;
}

// Elimina el elemento superior de la pila (pop)
Stack* pop(Stack* p) {
    if (is_empty(p) != TRUE) {
        p->stack = realloc(p->stack, (p->top - 1) * sizeof(user)); // Reduce el tamaño de la memoria asignada para la pila
        p->top--; // Decrementa el puntero superior
    } else {
        printf("\nLa pila esta vacia\n"); // Si la pila está vacía, imprime un mensaje de error
    }
    return p;
}

// Libera la memoria asignada para la pila
void free_stack(Stack* p) {
    free(p->stack); // Libera la memoria asignada para el array de la pila
    free(p); // Libera la memoria asignada para la estructura de la pila
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
    q->head = -1;
    q->tail = -1;
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
        q->head = q->head + 1;
        q->elements++;
        strcpy(q->A[q->head], e);
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
/**#################################????????????????####################################*/
Queue* enviar_solicitud_amistad( char nombre[MAX_STRING_LENGTH], Queue *cola_solicitudes_amigos){
    return enqueue(cola_solicitudes_amigos, nombre);
}

Queue* recibir_solicitud_amistad(user usuario){
    if (is_empty_q(usuario.solicitudes_amistad) == TRUE){
        printf("\nNo tienes solicitudes de amistad ;(\n");
        return usuario.solicitudes_amistad;
    }
    while (is_empty_q(usuario.solicitudes_amistad) != TRUE) {
        char option;
        printf("\nPulsa '0' para salir de las solicitudes de amistad, escribe 'Y' para acepar y 'N' para rechazar las solicitudes de amistad\n");
        printf("\nQuieres aceptar la solicitud de amistad de %s?", usuario.solicitudes_amistad->A[usuario.solicitudes_amistad->head]);
        scanf(" %c", &option);
        if (option == '0') {
            break;
        }
        else if (option == 'Y'){
            usuario.lista_amigos[usuario.cantidd_amigos] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
            usuario.lista_amigos[usuario.cantidd_amigos] = first(usuario.solicitudes_amistad);
            usuario.cantidd_amigos++;
            dequeue(usuario.solicitudes_amistad);
            printf("\n\n");
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
/**#####################################################################*/

/**############################ DICCIONARIO ############################*/

// Crea un diccionario vacío con el tamaño especificado
Dic create_dic(int size) {
    Dic dic;
    dic.table = (Node*)malloc(size * sizeof(Node)); // Asigna memoria para el array de nodos
    dic.size = size;
    dic.count = 0;
    return dic;
}

// Función de hash para calcular el índice de una palabra en la tabla
int hash(char* key, int size) {
    int hashvalue = 0;
    for (int i = 0; i < strlen(key); i++) {
        hashvalue = (hashvalue * 31 + key[i]) % size; // Cálculo del valor de hash utilizando el método de multiplicación
    }
    return hashvalue;
}
// Agrega una palabra al diccionario
void add_word(Dic* dic, char* word) {
    int i = hash(word, dic->size); // Calcula el índice de hash para la palabra
    while (dic->table[i].key != NULL && strcmp(dic->table[i].key, word) != 0) {
        i = (i + 1) % dic->size; // Resolución de colisiones lineal mediante sondas lineales
    }
    if (dic->table[i].key == NULL) {
        dic->table[i].key = strdup(word); // Asigna memoria y copia la palabra en el campo key del nodo
        dic->table[i].count = 1; // Establece el contador en 1
        dic->count++; // Incrementa el contador total de palabras en el diccionario
    } else {
        dic->table[i].count++; // Si la palabra ya existe, incrementa el contador de ocurrencias
    }
}
// Obtiene el número de ocurrencias de una palabra en el diccionario
int get_word_count(Dic* dic, char* word) {
    int i = hash(word, dic->size); // Calcula el índice de hash para la palabra
    while (dic->table[i].key != NULL) {
        if (strcmp(dic->table[i].key, word) == 0) {
            return dic->table[i].count; // Si encuentra la palabra, devuelve el contador asociado
        }
        i = (i + 1) % dic->size; // Resolución de colisiones lineal mediante sondas lineales
    }
    return 0; // Si la palabra no se encuentra, devuelve 0
}
// Imprime las n palabras más frecuentes en el diccionario
void print_most_frequent_words(Dic* dic, int n) {
    // Ordenar la tabla por conteo descendente usando un algoritmo de ordenamiento (por ejemplo, bubble sort)
    for (int i = 0; i < dic->count - 1; i++) {
        for (int j = 0; j < dic->count - i - 1; j++) {
            if (dic->table[j].count < dic->table[j + 1].count) {
                Node temp = dic->table[j];
                dic->table[j] = dic->table[j + 1];
                dic->table[j + 1] = temp;
            }
        }
    }
    // Imprimir las n palabras más frecuentes
    printf("Las %d palabras más frecuentes son:\n", n);
    for (int i = 0; i < n && i < dic->count; i++) {
        printf("%s: %d\n", dic->table[i].key, dic->table[i].count);
    }
}

// Limpia el diccionario, liberando la memoria y restableciendo los valores
void clear_dic(Dic* dic) {
    for (int i = 0; i < dic->size; i++) {
        free(dic->table[i].key); // Libera la memoria asignada para cada clave
        dic->table[i].key = NULL; // Establece el puntero de clave a NULL
        dic->table[i].count = 0; // Establece el contador a 0
    }
    dic->count = 0; // Restablece el contador total de palabras en el diccionario
}

/**#####################################################################*/




/**#####################################################################*/