#ifndef RED_SOCIAL_PROYECTO_USERS_H
#define RED_SOCIAL_PROYECTO_USERS_H
#include <stdlib.h>
#include <string.h>
#include "amigos.h"

#define MAX_STRING_LENGTH 50
#define MAX_GUSTOS 5
#define MAX_USERS 20
#define MAX_LEN_POSTS 120

#define TRUE 1
#define FALSE 0

#define SUCCESS 0
#define ERROR -1

typedef struct{
    char title[MAX_STRING_LENGTH];
    char post[MAX_LEN_POSTS];
    int post_idx;
}post;

typedef struct{
    char** lista_amigos;
    int cantidd_amigos;
}friends;

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
    char mail[MAX_STRING_LENGTH];
    char ubicacion[MAX_STRING_LENGTH];
    char gustos[MAX_GUSTOS][MAX_STRING_LENGTH];
    Queue* solicitudes_amistad;
    friends amigos;
    post* publi;
    int cant_post;
} user;

typedef struct  {
    user *lista_de_usuarios;
    int cantidad_usuarios;
} user_list;


int menu(user_list lista_de_usuarios);

user rellenar_datos(user user1);

user_list lista_usuarios(user_list usuarios, user nuevo_usuario);

void print_users(user_list  usuarios);

user* buscar_usuario(user_list usuarios, char name[MAX_STRING_LENGTH]);

user_list actualizar_usuario(user_list lista_usuarios, user usuario_nuevo);

user generate_user();

user_list file_users(user_list lista_usuarios, int cantidad_usuarios);

user_list read_users(user_list lista_de_usuarios);

int buscar_amigo(user_list* usuarios);

user usuario_rdm(FILE * f, int num);

Queue* enviar_solicitud_amistad( char* nombre, Queue *cola_solicitudes_amigos);

friends recibir_solicitud_amistad(user *usuario);

post* add_post(user* usuario, Dic dic);

void print_posts(user *usuario);

void imprimir_usuarios_por_genero(char genero[MAX_STRING_LENGTH], user_list* lista_de_usuarios);

void update_dictionary(Dic* dic, char *text);

void print_dictionary(Dic* dic);

#endif //RED_SOCIAL_PROYECTO_USERS_H
