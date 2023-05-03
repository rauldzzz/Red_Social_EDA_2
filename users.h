#ifndef RED_SOCIAL_PROYECTO_USERS_H
#define RED_SOCIAL_PROYECTO_USERS_H
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
    char* mail;
    char* ubicacion;
    char* gustos[5];
}user;

int menu();

void rellenar_datos(user user1);

void lista_usuarios(user* usuarios, user nuevo_usuario, int cantidad_usuarios);

#endif //RED_SOCIAL_PROYECTO_USERS_H
