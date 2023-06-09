#include <stdio.h>
#include "users.h"
#include "amigos.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "time.h"

/**########################## FUNCIONES PILA ##########################*/

Nodo* crearNodo(char* usuarioID) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->usuarioID = strdup(usuarioID);
    nodo->totalLikes = 0;
    nodo->siguiente = NULL;
    return nodo;
}

int estaVacia(Nodo* pila) {
    return pila == NULL;
}

void agregarLike(Nodo** pila, char* usuarioID) {
    Nodo* nuevoNodo = crearNodo(usuarioID);
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
    (*pila)->totalLikes++;
    printf("El usuario %s ha dado like al post.\n", usuarioID);
}

void quitarLike(Nodo** pila, char* usuarioID) {
    if (estaVacia(*pila)) {
        printf("La pila de likes está vacía. No se puede quitar un like.\n");
        return;
    }

    Nodo* nodoTemp = *pila;
    *pila = (*pila)->siguiente;
    free(nodoTemp->usuarioID);
    free(nodoTemp);
    printf("El usuario %s ha quitado su like del post.\n", usuarioID);
}

void mostrarLikes(Nodo* pila) {
    printf("\n<3 %d\n", pila->totalLikes);
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

int haDadoLike(Nodo* pila, char* usuarioID) {
    while (pila != NULL) {
        if (strcmp(pila->usuarioID, usuarioID) == 0) {
            return TRUE;
        }
        pila = pila->siguiente;
    }
    return FALSE;
}

/*#################################????????????????####################################*/
Queue* enviar_solicitud_amistad( char nombre[MAX_STRING_LENGTH], Queue *cola_solicitudes_amigos){
    return enqueue(cola_solicitudes_amigos, nombre);
}

friends recibir_solicitud_amistad(user *usuario){
    if (is_empty_q(usuario->solicitudes_amistad) == TRUE){
        printf("\nNo tienes solicitudes de amistad ;(\n");
    }else {
        while (is_empty_q(usuario->solicitudes_amistad) != TRUE) {
            char option;
            printf("\nPulsa '0' para salir de las solicitudes de amistad, escribe 'Y' para acepar y 'N' para rechazar las solicitudes de amistad\n");
            printf("\nQuieres aceptar la solicitud de amistad de %s?",
                   usuario->solicitudes_amistad->A[usuario->solicitudes_amistad->head]);
            scanf(" %c", &option);
            if (option == '0') {
                printf("\n Saliendo...\n");
                break;
            } else if (option == 'Y') {
                printf("\nAhora %s y tu sois amigos <3\n", usuario->solicitudes_amistad->A[usuario->solicitudes_amistad->head]);
                usuario->amigos.lista_amigos[usuario->amigos.cantidd_amigos] = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
                usuario->amigos.lista_amigos[usuario->amigos.cantidd_amigos] = first(usuario->solicitudes_amistad);
                usuario->amigos.cantidd_amigos++;
                dequeue(usuario->solicitudes_amistad);
            } else if (option == 'N') {
                dequeue(usuario->solicitudes_amistad);
                printf("\nHas rechazado la solicitud de amistad ;(\n");
            } else {
                printf("\nOPCION INCORRECTA");
                printf("\nPulsa '0' para salir de las solicitudes de amistad, escribe 'Y' para acepar y 'N' para rechazar las solicitudes de amistad\n");
            }
        }
    }
    return usuario->amigos;
}
/*#####################################################################*/
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