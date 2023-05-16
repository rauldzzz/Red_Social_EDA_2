#ifndef RED_SOCIAL_PROYECTO_USERS_H
#define RED_SOCIAL_PROYECTO_USERS_H
#include <stdlib.h>
#include <string.h>

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
} user;

typedef struct  {
    user *lista_de_usuarios;
    int cantidad_usuarios;
} user_list;

int menu();

user rellenar_datos(user user1);

user_list lista_usuarios(user_list usuarios, user nuevo_usuario);

void print_users(user_list  usuarios);

user buscador_usuario(user_list usuarios, char name[MAX_STRING_LENGTH]);

user generate_user();

user_list file_users(user_list lista_usuarios);

#endif //RED_SOCIAL_PROYECTO_USERS_H
