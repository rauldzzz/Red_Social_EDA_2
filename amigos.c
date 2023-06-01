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
/*
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
        //push(user3);

        // 4. Cerrar fichero --> la función de añadir usuario
        fclose(f);
        free_stack(p);
    }
}
*/


/**########################## FUNCIONES COLA ##########################*/
Queue* init_queue(){
    Queue* q = malloc(sizeof(Queue));
    //Alocar memeoria para A?
    q->A = (char**)malloc( MAX_USERS * sizeof(char*));
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

char* first(Queue* q){
    if (is_empty_q(q)) {
       printf("\nQueue is empty\n");
       //retornem error o algo?
    }
    else{
        return (q->A[q->head]);
    }
}

Queue* enqueue(Queue* q, char e[MAX_STRING_LENGTH]){
    if(q->elements == MAX_USERS) {
        printf("Queue is full");
    }
    else{
        q->A[q->tail] = e;
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

Queue* enviar_solicitud_amistad( char* nombre, Queue *cola_solicitudes_amigos){
    return enqueue(cola_solicitudes_amigos, nombre);
}

Queue* recibir_solicitud_amistad(Queue *cola_solicitudes_amigos){
    printf("\nPulsa '0' para salir de las solicitudes de amistad, escribe 'Y' para acepar y 'N' para rechazar las solicitudes de amistad\n");
    char option;
    for (int i = 0; i < cola_solicitudes_amigos->elements;) {
        printf("\nQuieres aceptar la solicitud de amistad de %s?", cola_solicitudes_amigos->A[i]);
        scanf("%c", &option);
        if (option == '0') break;
        else if (option == 'Y'){

        }
        else if (option == 'N'){

        }
        else{
            printf("\nOPCION INCORRECTA\n");
            printf("\nPulsa '0' para salir de las solicitudes de amistad, escribe 'Y' para acepar y 'N' para rechazar las solicitudes de amistad\n");
        }
    }
}

/**############################ DICCIONARIO ############################*/

Dic create_dic(int size) {
    Dic dic;
    dic.table = (Node*)malloc(size * sizeof(Node));
    dic.size = size;
    dic.count = 0;
    return dic;
}

int hash(char* key, int size) {
    int hashvalue = 0;
    for (int i = 0; i < strlen(key); i++) {
        hashvalue = (hashvalue * 31 + key[i]) % size;
    }
    return hashvalue;
}

void add_word(Dic* dic, char* word) {
    int i = hash(word, dic->size);
    while (dic->table[i].key != NULL && strcmp(dic->table[i].key, word) != 0) {
        i = (i + 1) % dic->size;
    }
    if (dic->table[i].key == NULL) {
        dic->table[i].key = strdup(word);
        dic->table[i].count = 1;
        dic->count++;
    } else {
        dic->table[i].count++;
    }
}

int get_word_count(Dic* dic, char* word) {
    int i = hash(word, dic->size);
    while (dic->table[i].key != NULL) {
        if (strcmp(dic->table[i].key, word) == 0) {
            return dic->table[i].count;
        }
        i = (i + 1) % dic->size;
    }
    return 0;
}

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


void clear_dic(Dic* dic) {
    for (int i = 0; i < dic->size; i++) {
        free(dic->table[i].key);
        dic->table[i].key = NULL;
        dic->table[i].count = 0;
    }
    dic->count = 0;
}

/**#####################################################################*/

/**############################### POSTS ###############################*/

void add_post(Dic* wordCount, Post** posts, char* post) {
    // Separar el contenido de la publicación en palabras individuales
    char* word = strtok(post, " ");
    while (word != NULL) {
        add_word(wordCount, word);
        word = strtok(NULL, " ");
    }

    // Agregar la publicación a la lista de publicaciones de los usuarios
    Post* newPost = (Post*)malloc(sizeof(Post));
    newPost->content = strdup(post);
    newPost->next = NULL;

    if (*posts == NULL) {
        *posts = newPost;
    } else {
        Post* currentPost = *posts;
        while (currentPost->next != NULL) {
            currentPost = currentPost->next;
        }
        currentPost->next = newPost;
    }
}

void print_top_10_words(Dic* wordCount) {
    print_most_frequent_words(wordCount, 10);
}
/*void print_all_posts(Post* posts) {
    printf("Publicaciones de TODOS los usuarios:\n");
    Post* currentPost = posts;
    while (currentPost != NULL) {
        printf("%s\n", currentPost->content);
        currentPost = currentPost->next;
    }
}*/

void clear_posts(Post** posts) {
    Post* currentPost = *posts;
    while (currentPost != NULL) {
        Post* nextPost = currentPost->next;
        free(currentPost->content);
        free(currentPost);
        currentPost = nextPost;
    }
    *posts = NULL;
}

Post* create_post(char* content) {
    Post* newPost = (Post*)malloc(sizeof(Post));
    newPost->content = strdup(content);
    newPost->next = NULL;
    return newPost;
}
/** COMO AÑADIR POSTS */
/* Post* posts = NULL;

Post* post1 = create_post("Esta es una publicacion de prueba");
Post* post2 = create_post("Otra publicacion de ejemplo");
Post* post3 = create_post("Esta publicacion es otra prueba");

// Agregar las publicaciones a la lista
if (posts == NULL) {
    posts = post1;
} else {
    Post* currentPost = posts;
    while (currentPost->next != NULL) {
        currentPost = currentPost->next;
    }
    currentPost->next = post1;
}

post1->next = post2;
post2->next = post3;

// Imprimir las publicaciones
Post* currentPost = posts;
while (currentPost != NULL) {
    printf("%s\n", currentPost->content);
    currentPost = currentPost->next;
}

// Liberar la memoria de las publicaciones
currentPost = posts;
while (currentPost != NULL) {
    Post* nextPost = currentPost->next;
    free(currentPost->content);
    free(currentPost);
    currentPost = nextPost;
}
*/

/**#####################################################################*/












