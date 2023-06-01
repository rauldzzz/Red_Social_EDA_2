#ifndef RED_SOCIAL_PROYECTO_USERS_H
#define RED_SOCIAL_PROYECTO_USERS_H
#include <stdlib.h>
#include <string.h>
#include "amigos.h"

#define MAX_STRING_LENGTH 50
#define MAX_GUSTOS 5
#define MAX_USERS 20

#define TRUE 1
#define FALSE 0

#define SUCCESS 0
#define ERROR -1

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
    char mail[MAX_STRING_LENGTH];
    char ubicacion[MAX_STRING_LENGTH];
    char gustos[MAX_GUSTOS][MAX_STRING_LENGTH];
    Queue* solicitudes_amistad;

} user;

typedef struct  {
    user *lista_de_usuarios;
    int cantidad_usuarios;
} user_list;

typedef struct{
    user  usuario;
    user_list seguidores;
}Amigos;

int menu(user_list lista_de_usuarios);

user rellenar_datos(user user1);

user_list lista_usuarios(user_list usuarios, user nuevo_usuario);

void print_users(user_list  usuarios);

user* buscar_usuario(user_list usuarios, char name[MAX_STRING_LENGTH]);

user generate_user();

user_list file_users(user_list lista_usuarios);

int buscar_amigo(user_list* usuarios);

user usuario_rdm(FILE * f, int num);

void buscar_usuarios_por_genero(char genero[MAX_STRING_LENGTH]);

#endif //RED_SOCIAL_PROYECTO_USERS_H
