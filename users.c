#include <stdio.h>
#include "users.h"
#include <stdlib.h>
#include <string.h>

int menu(){
    int choice; //La eleccion del menu

    //Centramos la palabra 'MENU' y decoramos con #
    for (int i = 0; i < 40; ++i) printf("#");
    printf("\n");
    char menu[] = "MENU";
    int longitud = strlen(menu);
    int espacios = (40 - longitud) / 2;
    for(int i = 0; i < espacios; i++) putchar(' ');
    printf("%s\n", menu);
    for (int i = 0; i < 40; ++i) printf("#");
    printf("\n");

}

//Colocar el rellenar_datos() aqui Paula
void rellenar_datos(user user1);

void lista_usuarios(user* usuarios, user nuevo_usuario, int cantidad_usuarios){
    if (cantidad_usuarios == 0){
        usuarios = malloc(sizeof(user));
    } else{
        usuarios = (user*) realloc(usuarios, sizeof(user)+ sizeof(user));
    }
    usuarios[cantidad_usuarios] = nuevo_usuario;
    cantidad_usuarios++;
}