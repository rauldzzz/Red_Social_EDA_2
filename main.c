#include <stdio.h>
#include "users.h"
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    user_list lista_de_usuarios;
    lista_de_usuarios.cantidad_usuarios = 0;
    FILE* f = fopen("f_users.txt", "r");
    if (f == NULL) {
        // El archivo no existe o no se puede abrir en modo de lectura
        lista_de_usuarios= file_users(lista_de_usuarios, MAX_USERS);
        fclose(f);
    } else {
        // El archivo existe y tiene contenido, no se debe modificar
        printf("El archivo f_users.txt ya contiene datos. No se debe modificar.\n");
        fclose(f);
        lista_de_usuarios = read_users(lista_de_usuarios);
    }
    menu(lista_de_usuarios);

    //Crear diccionario:
    //Dic wordCount;
    //create_dic(&wordCount);

    return 0;
}

 /* Parte del main de la interfaz para llenar los datos básicos de los usuarios
    Usuario usuario;

    rellenar_datos(&user);

    printf("\n--- Datos del usuario ---\n");
    printf("Nombre: %s\n", user1.name);
    printf("Edad: %d\n", user1.age);
    printf("Email: %s\n", user.mail);
    printf("Ubicación: %s\n", user.ubicacion);
    printf("Gustos:\n");
    for (int i = 0; i < MAX_GUSTOS; i++) {
        printf("%d. %s\n", i + 1, user1.gustos[i]);
    }

    return 0;
  */