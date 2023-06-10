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
// Inicializa una cola vacía
Queue* init_queue(){
    Queue* q = malloc(sizeof(Queue)); // Asigna memoria para la estructura de la cola
    q->A = (char**)malloc( MAX_USERS * sizeof(char*)); // Asigna memoria para el array que almacenará los elementos de la cola
    for (int i = 0; i < MAX_USERS; ++i) {
        q->A[i] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char)); // Asigna memoria para cada elemento del array
    }
    q->head = -1; // Inicializa el índice de la cabeza en -1 (cola vacía)
    q->tail = -1; // Inicializa el índice de la cola en -1 (cola vacía)
    q->elements = 0; // Inicializa el contador de elementos en 0 (cola vacía)
    return q;
}

// Verifica si la cola está llena
int is_full_q(Queue* q){
    if(q->elements == MAX_USERS) return TRUE; // Compara el contador de elementos con el máximo permitido
    return FALSE; // Si el contador de elementos es menor que el máximo permitido, la cola no está llena
}

// Verifica si la cola está vacía
int is_empty_q(Queue* q){
    if (q->elements == 0)return TRUE; // Compara el contador de elementos con 0
    return FALSE; // Si el contador de elementos es mayor que 0, la cola no está vacía
}

// Devuelve el primer elemento de la cola
char* first(Queue* q){
    if (is_empty_q(q) == TRUE) {
        printf("\nQueue is empty\n"); // Si la cola está vacía, imprime un mensaje de error
    }
    else{
        return (q->A[q->head]); // Devuelve el primer elemento de la cola
    }
}

// Inserta un elemento en la cola (enqueue)
Queue* enqueue(Queue* q, char e[MAX_STRING_LENGTH]){
    if(is_full_q(q) == TRUE) {
        printf("Queue is full"); // Si la cola está llena, imprime un mensaje de error
    }
    else{
        q->head = q->head + 1; // Incrementa el índice de la cabeza
        q->elements++; // Incrementa el contador de elementos
        strcpy(q->A[q->head], e); // Copia el elemento en el array de la cola
    }
    return q; // Devuelve la cola actualizada
}

// Elimina el primer elemento de la cola (dequeue)
Queue* dequeue(Queue* q){
    if(is_empty_q(q) == TRUE) {
        printf("Queue is empty"); // Si la cola está vacía, imprime un mensaje de error
    }
    else{
        q->head = q->head - 1; // Decrementa el índice de la cabeza
        q->elements--; // Decrementa el contador de elementos
    }
    return q; // Devuelve la cola actualizada
}
void free_queue(Queue* q) {
    for (int i = 0; i < MAX_USERS; ++i) {
        free(q->A[i]); // Libera la memoria asignada para cada elemento del array A
    }
    free(q->A); // Libera la memoria asignada para el array A
    free(q); // Libera la memoria asignada para la estructura de la cola
}

/*#################################????????????????####################################*/
Queue* enviar_solicitud_amistad( char nombre[MAX_STRING_LENGTH], Queue *cola_solicitudes_amigos){
    return enqueue(cola_solicitudes_amigos, nombre); // Agrega la solicitud de amistad a la cola de solicitudes de amigos
}

friends recibir_solicitud_amistad(user *usuario){
    if (is_empty_q(usuario->solicitudes_amistad) == TRUE){
        printf("\nNo tienes solicitudes de amistad ;(\n"); // Si la cola de solicitudes de amistad está vacía, muestra un mensaje
    }else {
        while (is_empty_q(usuario->solicitudes_amistad) != TRUE) {
            char option;
            printf("\nPulsa '0' para salir de las solicitudes de amistad, escribe 'Y' para aceptar y 'N' para rechazar las solicitudes de amistad\n");
            printf("\nQuieres aceptar la solicitud de amistad de %s?", usuario->solicitudes_amistad->A[usuario->solicitudes_amistad->head]); // Muestra la solicitud de amistad actual en la cabeza de la cola
            scanf(" %c", &option); // Lee la opción del usuario

            if (option == '0') {
                printf("\n Saliendo...\n"); // Si la opción es '0', muestra un mensaje y sale del bucle
                break;
            } else if (option == 'Y') {
                printf("\nAhora %s y tu sois amigos <3\n", usuario->solicitudes_amistad->A[usuario->solicitudes_amistad->head]); // Muestra un mensaje de amistad aceptada
                usuario->amigos.lista_amigos[usuario->amigos.cantidd_amigos] = (char *) malloc(MAX_STRING_LENGTH * sizeof(char)); // Asigna memoria para el nombre del amigo
                usuario->amigos.lista_amigos[usuario->amigos.cantidd_amigos] = first(usuario->solicitudes_amistad); // Copia el nombre del amigo aceptado en la lista de amigos del usuario
                usuario->amigos.cantidd_amigos++; // Incrementa el contador de amigos del usuario
                dequeue(usuario->solicitudes_amistad); // Elimina la solicitud de amistad de la cola
            } else if (option == 'N') {
                dequeue(usuario->solicitudes_amistad); // Elimina la solicitud de amistad de la cola
                printf("\nHas rechazado la solicitud de amistad ;(\n"); // Muestra un mensaje de solicitud de amistad rechazada
            } else {
                printf("\nOPCION INCORRECTA"); // Si la opción no es válida, muestra un mensaje de error
                printf("\nPulsa '0' para salir de las solicitudes de amistad, escribe 'Y' para aceptar y 'N' para rechazar las solicitudes de amistad\n");
            }
        }
    }
    return usuario->amigos; // Devuelve la lista de amigos actualizada del usuario
}
/**#####################################################################*/

/**############################ DICCIONARIO ############################*/

// Función que calcula el valor hash de una clave utilizando el método de multiplicación
unsigned int hashFunction(Dic* dict, char key[MAX_STRING_LENGTH]) {
    unsigned int hash = 0;
    int i = 0;
    while (key[i] != '\0') {
        hash = hash * 31 + key[i]; // Método de multiplicación para generar el hash
        i++;
    }
    return hash % dict->size;  // Retorna el índice calculado dentro del rango del tamaño del diccionario
}

// Inicializa un diccionario con el tamaño especificado
void initializeDic(Dic* dict, int size) {
    dict->size = size;  // Establece el tamaño del diccionario
    dict->count = 0;  // Inicializa el contador de palabras en 0
    dict->table = (Node**)malloc(dict->size * sizeof(Node*));  // Asigna memoria para la tabla hash
    for (int i = 0; i < dict->size; i++) {
        dict->table[i] = NULL;  // Inicializa todos los elementos de la tabla como nulos
    }
}

// Libera la memoria utilizada por el diccionario
void freeDic(Dic* dict) {
    for (int i = 0; i < dict->size; i++) {
        if (dict->table[i] != NULL) {
            free(dict->table[i]->key);  // Libera la memoria asignada para la clave del nodo
            free(dict->table[i]);  // Libera la memoria asignada para el nodo
        }
    }
    free(dict->table);  // Libera la memoria asignada para la tabla hash
}

// Inserta una palabra en el diccionario o incrementa su contador si ya existe
void insert(Dic* dict, char key[MAX_STRING_LENGTH]) {
    unsigned int index = hashFunction(dict, key);  // Obtiene el índice de hash para la clave
    Node* node = dict->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {  // Si la clave ya existe en el diccionario
            node->count++;  // Incrementa el contador de la palabra
            return;
        }
        index = (index + 1) % dict->size;  // Resuelve colisiones usando lineal probing
        node = dict->table[index];
    }
    // La palabra no existe en el diccionario, la añadimos
    Node* newNode = (Node*)malloc(sizeof(Node));  // Crea un nuevo nodo
    //newNode->key = (char*)malloc((strlen(key) + 1) * sizeof(char));  // Asigna memoria para la clave del nodo
    strcpy(newNode->key, key);  // Copia la clave al nuevo nodo
    newNode->count = 1;  // Inicializa el contador del nuevo nodo en 1
    dict->table[index] = newNode;  // Inserta el nuevo nodo en la tabla hash
    dict->count++;  // Incrementa el contador total de palabras en el diccionario
}

// Obtiene la frecuencia de una palabra en el diccionario
int get_word_count(Dic* dict, char key[MAX_STRING_LENGTH]) {
    unsigned int index = hashFunction(dict, key);  // Obtiene el índice de hash para la clave
    Node* node = dict->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {  // Si encuentra la clave en el diccionario
            return node->count;  // Retorna la frecuencia (contador) de la palabra
        }
        index = (index + 1) % dict->size;  // Resuelve colisiones usando lineal probing
        node = dict->table[index];
    }
    return 0; // Palabra no encontrada
}

// Implementa el algoritmo de ordenamiento de selección para ordenar los nodos por frecuencia
void selectionSort(Node** arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j]->count > arr[maxIndex]->count) {  // Compara las frecuencias de los nodos
                maxIndex = j;  // Actualiza el índice del nodo con mayor frecuencia
            }
        }
        // Intercambiar los nodos
        Node* temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

// Imprime las N palabras más frecuentes en el diccionario
void printTopNWords(Dic* dict, int n) {
    Node** words = (Node**)malloc(dict->count * sizeof(Node*));  // Crea un arreglo de punteros a nodos
    int count = 0;
    for (int i = 0; i < dict->size; i++) {
        if (dict->table[i] != NULL) {
            words[count] = dict->table[i];  // Agrega el nodo a la lista de palabras
            count++;
        }
    }
    selectionSort(words, count);  // Ordena los nodos por frecuencia de mayor a menor
    printf("\nTOP %d palabras mas usadas:\n", n);
    for (int i = 0; i < n && i < count; i++) {
        printf("%d# %s (%d veces)\n", i+1, words[i]->key, words[i]->count);  // Imprime la palabra y su frecuencia
    }
    free(words);  // Libera la memoria asignada para el arreglo de nodos
}
/**#####################################################################*/