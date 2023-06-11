
#ifndef RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
#define RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
#include "users.h"
#define MAX_STACK 20
#define MAX_STRING_LENGTH 50
/**########################## FUNCIONES PILA ##########################*/

typedef struct Nodo {
    char* usuarioID; // Identificador del usuario en el nodo
    struct Nodo* siguiente; // Puntero al siguiente nodo en la pila
} Nodo;

Nodo* crearNodo(char* usuarioID);
// crea un nuevo nodo para la pila. Toma como parámetro el usuarioID que se va a almacenar en el nodo. La función
// reserva memoria para el nuevo nodo utilizando malloc y asigna el usuarioID al campo usuarioID del nodo utilizando
// strdup, que realiza una copia duplicada de la cadena. Luego, se establece el campo siguiente del nodo como NULL,
// ya que es el último nodo en la pila. Finalmente, se devuelve el nodo creado.

int estaVacia(Nodo* pila);
// verifica si la pila está vacía. Toma como parámetro un puntero a la pila y devuelve 1 si la pila está vacía
// (es decir, si el puntero es NULL) o 0 si la pila contiene elementos. La función simplemente compara el puntero de la
// pila con NULL y devuelve el resultado de la comparación. Si el puntero es NULL, se considera que la pila está vacía y
// se devuelve 1; de lo contrario, se considera que la pila contiene elementos y se devuelve 0.

void agregarLike(Nodo** pila, char* usuarioID);
// agrega un nuevo nodo a la pila de likes para indicar que un usuario ha dado like a una publicación. Toma como
// parámetros un puntero a la pila de likes y el ID del usuario que ha dado like. Se crea un nuevo nodo con el usuarioID
// proporcionado, se establece su siguiente nodo como el nodo actual de la pila, y luego se actualiza la pila para que
// apunte al nuevo nodo (se agrega el nodo al inicio de la pila). También se imprime un mensaje indicando que el usuario
// ha dado like al post.

void quitarLike(Nodo** pila, char* usuarioID);
// elimina el nodo correspondiente a un usuario que ha dado like a una publicación. Toma como parámetros un puntero a
// la pila de likes y el ID del usuario a quitar el like. El nodo actual se guarda en una variable temporal, luego se
// actualiza la pila para que apunte al siguiente nodo (se elimina el nodo actual), y finalmente se liberan las memorias
// asignadas para el usuarioID y el nodo actual. También se imprime un mensaje indicando que el usuario ha quitado su like del post.

int haDadoLike(Nodo* pila, char* usuarioID);
// verificar si un usuario ha dado "like" a una publicación. Recorre la pila de likes, que está compuesta por nodos,
// y compara el ID del usuario en cada nodo con el usuarioID dado. Si hay una coincidencia, se devuelve TRUE, lo que
// indica que el usuario ha dado like. Si se recorre toda la pila sin encontrar una coincidencia, se devuelve FALSE,
// lo que indica que el usuario no ha dado like.

/**#####################################################################*/
/**########################## FUNCIONES COLA ##########################*/
typedef struct{
    int head; // Índice del primer elemento en la cola
    int tail; // Índice del último elemento en la cola
    int elements; // Contador de elementos en la cola
    char** A; // Puntero a un array que almacena los elementos de la cola
}Queue;

Queue* init_queue();
//Esta función inicializa una cola vacía. Asigna memoria para la estructura
// Queue y el array A que almacenará los elementos de la cola.
// Inicializa los índices de la cabeza y la cola en -1, y el contador de
// elementos en 0. Devuelve un puntero a la cola inicializada.

int is_full_q(Queue* q);
//Verifica si la cola está llena. Compara el contador de elementos con el
// máximo permitido de usuarios en la cola. Devuelve un valor entero (TRUE o FALSE)
// indicando si la cola está llena.

int is_empty_q(Queue* q);
// Verifica si la cola está vacía. Compara el contador de elementos con 0.
// Devuelve un valor entero (TRUE o FALSE) indicando si la cola está vacía.

char* first(Queue* q);
// Devuelve el primer elemento de la cola sin eliminarlo. Verifica si la cola
// está vacía y, en caso afirmativo, puede imprimir un mensaje de error.
// Devuelve un puntero al primer elemento de la cola.

Queue* enqueue(Queue* q, char e[MAX_STRING_LENGTH]);
//Inserta un elemento en la cola. Verifica si la cola está llena y, en caso afirmativo,
// puede imprimir un mensaje de error. Incrementa el índice de la cabeza, incrementa
// el contador de elementos y copia el elemento en el array A de la cola.
// Devuelve un puntero a la cola actualizada.

Queue* dequeue(Queue* q);
//Elimina el primer elemento de la cola. Verifica si la cola está vacía y, en caso
// afirmativo, puede imprimir un mensaje de error. Decrementa el índice de la cabeza
// y el contador de elementos. Devuelve un puntero a la cola actualizada.


void free_queue(Queue* q);
// itera sobre cada elemento del array A de la cola y utiliza free() para liberar la
// memoria asignada para cada elemento. Luego, libera la memoria asignada para el
// array A y finalmente libera la memoria asignada para la estructura de la cola.
/**#####################################################################*/
/**############################ DICCIONARIO ############################*/

typedef struct Node {
    char key[MAX_STRING_LENGTH]; //cadena que almacena la palabra o clave.
    int count; //entero que almacena el número de ocurrencias de la palabra.
} Node; //estructura que representa un nodo en la tabla hash.

typedef struct Dic {
    Node** table; //puntero a un array de nodos (Node).
    int size; //el tamaño del array de nodos.
    int count; //el número actual de elementos en el diccionario.
} Dic; //estructura que representa el diccionario.

void initializeDic(Dic* dict, int size);
// recibe una instancia de Dic y un entero size.
// Esta función crea un diccionario vacío asignando memoria para el
// array table con el tamaño especificado,
// y luego inicializa los campos size y count
// en el diccionario creado. Finalmente, retorna el diccionario.

void freeDic(Dic* dict);
//  recibe un puntero a un diccionario dict.
//  Esta función limpia el diccionario liberando la memoria
//  asignada para cada clave en la tabla, estableciendo los punteros
//  de clave a NULL y restableciendo los contadores.
//  Itera sobre la tabla y libera la memoria asignada para cada clave
//  utilizando la función free().

unsigned int hashFunction(Dic* dict, char key[MAX_STRING_LENGTH]);
// recibe una cadena key y el tamaño de la tabla hash size.
// Implementa una función de hash simple utilizando el método de
// hash de multiplicación. Itera sobre cada carácter de la cadena
// y calcula un valor de hash basado en los valores anteriores.
// El resultado se obtiene tomando el módulo del valor de hash
// calculado con respecto al tamaño de la tabla, asegurando que
// se ajuste dentro del rango válido de índices para la tabla.
// Retorna el valor de hash calculado.

void insert(Dic* dict, char key[MAX_STRING_LENGTH]);
// recibe un puntero a un diccionario dict y una cadena key.
// Esta función agrega una palabra al diccionario.
// Primero calcula el índice de hash utilizando la función hash
// y el tamaño del diccionario. Luego, utiliza una estrategia de
// resolución de colisiones lineal mediante sondas lineales para
// encontrar una posición vacía en la tabla o la posición donde se
// encuentra la palabra. Si la posición está vacía, se asigna memoria
// para almacenar una copia de la palabra en el campo key del nodo
// correspondiente, se establece count en 1 y se incrementa el contador
// total de palabras en el diccionario. Si la posición ya contiene la
// palabra, simplemente se incrementa el contador de ocurrencias de esa palabra.

int get_word_count(Dic* dict, char key[MAX_STRING_LENGTH]);
// recibe un puntero a un diccionario dict y una cadena key.
// Esta función busca la palabra en el diccionario y devuelve el
// número de ocurrencias. Calcula el índice de hash utilizando la
// función hash y el tamaño del diccionario. Utiliza la misma estrategia
// de resolución de colisiones lineal para buscar la palabra en la tabla.
// Si encuentra la palabra, devuelve el contador asociado a esa palabra.
// Si no encuentra la palabra, devuelve 0.

void selectionSort(Node** arr, int n);
// Recibe un arreglo de punteros a nodos arr y el tamaño del arreglo n.
// Implementa el algoritmo de ordenamiento de selección para ordenar los nodos por frecuencia de uso.
// El algoritmo compara las frecuencias de los nodos y realiza intercambios para ordenarlos en orden descendente.
// Utiliza el algoritmo de selección, donde en cada iteración encuentra el nodo con la frecuencia más alta
// y lo coloca en la posición correcta.
// Después de completar el ordenamiento, los nodos en arr estarán ordenados por frecuencia de mayor a menor.

void printTopNWords(Dic* dict, int n);
// recibe un puntero a un diccionario dict y un entero n.
// Esta función imprime las n palabras más frecuentes junto con su conteo.
// Primero, ordena la tabla de nodos en orden descendente basándose en el
// conteo de ocurrencias utilizando un algoritmo de ordenamiento
// (en este caso, el Selection Sort). Luego, imprime las n
// palabras más frecuentes junto con sus conteos utilizando un bucle.
// Tenga en cuenta que n se usa para asegurarse de no imprimir más
// palabras de las que hay en el diccionario.

/**#####################################################################*/

#endif //RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
