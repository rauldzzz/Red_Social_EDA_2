
#ifndef RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
#define RED_SOCIAL_PROYECTO_HERRAMIENTAS_H
#include "users.h"
/**########################## FUNCIONES PILA ##########################*/

#define MAX_STACK 20
#define MAX_STRING_LENGTH 50

typedef struct{
    int head;
    int tail;
    int elements;
    char** A;
}Queue;

typedef struct{
    char *stack;
    int top;
}Stack;

Stack* init_stack();

int is_full(Stack* p);

int is_empty(Stack* p);

char* top(Stack* p);

Stack* push(Stack* p, char* valor);

Stack* pop(Stack* p);

void free_stack(Stack* p);

void add_desconicido();

Queue* init_queue();

int is_full_q(Queue* q);

int is_empty_q(Queue* q);

char* first(Queue* q);

Queue* enqueue(Queue* q, char e[MAX_STRING_LENGTH]);

Queue* dequeue(Queue* q);

/**############################ DICCIONARIO ############################*/

typedef struct Node {
    char* key;
    int count;
} Node;

typedef struct Dic {
    Node* table;
    int size;
    int count;
} Dic;

Dic create_dic(int size);

int hash(char* key, int size);

void add_word(Dic* dic, char* word);

int get_word_count(Dic* dic, char* word);

void print_most_frequent_words(Dic* dic, int n);

void clear_dic(Dic* dic);

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
