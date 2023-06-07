
#ifndef RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
#define RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
#include "users.h"
#define MAX_STACK 20
#define MAX_STRING_LENGTH 50
/**########################## FUNCIONES PILA ##########################*/

typedef struct{
    char *stack; // Puntero a un array que representa la pila
    int top; // Entero que indica la posición del elemento superior en la pila
}Stack;

Stack* init_stack();
// Esta función inicializa una pila vacía y devuelve un puntero a la estructura Stack.

int is_full(Stack* p);
//Verifica si la pila está llena. Recibe un puntero a la pila y devuelve un
// valor entero (TRUE o FALSE) indicando si la pila está llena.

int is_empty(Stack* p);
//Verifica si la pila está vacía. Recibe un puntero a la pila y devuelve un
// valor entero (TRUE o FALSE) indicando si la pila está vacía.

char* top(Stack* p);
//Devuelve el elemento superior de la pila sin eliminarlo.
// Recibe un puntero a la pila y devuelve un puntero al elemento superior de la pila.

Stack* push(Stack* p, char* valor);
//Inserta un elemento en la parte superior de la pila.
// Recibe un puntero a la pila y un puntero al valor que se va a insertar.
// Devuelve un puntero a la pila actualizada.

Stack* pop(Stack* p);
// Elimina el elemento superior de la pila.
// Recibe un puntero a la pila y elimina el elemento superior.
// Devuelve un puntero a la pila actualizada.

void free_stack(Stack* p);
// Libera la memoria asignada para la pila. Recibe un puntero a la pila y libera
// la memoria tanto para la estructura de la pila como para el array que almacena
// los elementos.

/**#####################################################################*/
/**########################## FUNCIONES COLA ##########################*/
typedef struct{
    int head;
    int tail;
    int elements;
    char** A;
}Queue;

Queue* init_queue();

int is_full_q(Queue* q);

int is_empty_q(Queue* q);

char* first(Queue* q);

Queue* enqueue(Queue* q, char e[MAX_STRING_LENGTH]);

Queue* dequeue(Queue* q);
/**#####################################################################*/
/**############################ DICCIONARIO ############################*/

typedef struct Node {
    char* key; //cadena que almacena la palabra o clave.
    int count; //entero que almacena el número de ocurrencias de la palabra.
} Node; //estructura que representa un nodo en la tabla hash.

typedef struct Dic {
    Node* table; //puntero a un array de nodos (Node).
    int size; //el tamaño del array de nodos.
    int count; //el número actual de elementos en el diccionario.
} Dic; //estructura que representa el diccionario.

Dic create_dic(int size);
// recibe un parámetro size y devuelve una instancia de Dic.
// Esta función crea un diccionario vacío asignando memoria para el
// array table con el tamaño especificado,
// y luego inicializa los campos size y count
// en el diccionario creado. Finalmente, retorna el diccionario.

int hash(char* key, int size);
// recibe una cadena key y el tamaño de la tabla hash size.
// Implementa una función de hash simple utilizando el método de
// hash de multiplicación. Itera sobre cada carácter de la cadena
// y calcula un valor de hash basado en los valores anteriores.
// El resultado se obtiene tomando el módulo del valor de hash
// calculado con respecto al tamaño de la tabla, asegurando que
// se ajuste dentro del rango válido de índices para la tabla.
// Retorna el valor de hash calculado.

void add_word(Dic* dic, char* word);
// recibe un puntero a un diccionario dic y una cadena word.
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

int get_word_count(Dic* dic, char* word);
// recibe un puntero a un diccionario dic y una cadena word.
// Esta función busca la palabra en el diccionario y devuelve el
// número de ocurrencias. Calcula el índice de hash utilizando la
// función hash y el tamaño del diccionario. Utiliza la misma estrategia
// de resolución de colisiones lineal para buscar la palabra en la tabla.
// Si encuentra la palabra, devuelve el contador asociado a esa palabra.
// Si no encuentra la palabra, devuelve 0.

void print_most_frequent_words(Dic* dic, int n);
// recibe un puntero a un diccionario dic y un entero n.
// Esta función imprime las n palabras más frecuentes junto con su conteo.
// Primero, ordena la tabla de nodos en orden descendente basándose en el
// conteo de ocurrencias utilizando un algoritmo de ordenamiento
// (en este caso, el algoritmo de burbuja). Luego, imprime las n
// palabras más frecuentes junto con sus conteos utilizando un bucle.
// Tenga en cuenta que n se usa para asegurarse de no imprimir más
// palabras de las que hay en el diccionario.

void clear_dic(Dic* dic);
//  recibe un puntero a un diccionario dic.
//  Esta función limpia el diccionario liberando la memoria
//  asignada para cada clave en la tabla, estableciendo los punteros
//  de clave a NULL y restableciendo los contadores.
//  Itera sobre la tabla y libera la memoria asignada para cada clave
//  utilizando la función free(). Luego, establece los punteros de
//  clave a NULL y los contadores a 0.

/**#####################################################################*/
/**############################### POSTS ###############################*/
typedef struct Post {
    char* content;
    struct Post* next;
} Post;

void print_top_10_words(Dic* wordCount);

void print_all_posts(Post* posts);

void clear_posts(Post** posts);

/**#####################################################################*/

#endif //RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
