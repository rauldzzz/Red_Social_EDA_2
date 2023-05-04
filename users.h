#ifndef RED_SOCIAL_PROYECTO_USERS_H
#define RED_SOCIAL_PROYECTO_USERS_H
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 50
#define MAX_GUSTOS 5

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
    char mail[MAX_STRING_LENGTH];
    char ubicacion[MAX_STRING_LENGTH];
    char gustos[MAX_GUSTOS][MAX_STRING_LENGTH];
} user;

int menu();

void rellenar_datos(user *user1);

user *lista_usuarios(user* usuarios, user nuevo_usuario, int cantidad_usuarios);

void print_users();

#endif //RED_SOCIAL_PROYECTO_USERS_H
