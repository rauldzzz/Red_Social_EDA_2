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

void init_users(user* users);

void rellenar_datos(user* users);

#endif //RED_SOCIAL_PROYECTO_USERS_H
