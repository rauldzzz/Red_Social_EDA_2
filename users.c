#include <stdio.h>
#include "users.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int menu(){
    int choice = -1; //La eleccion del menu
    user usuario;
    user_list lista_de_usuarios;
    lista_de_usuarios.cantidad_usuarios = 0;

    //Centramos la palabra 'MENU' y decoramos con #
    while (choice != 4 ) {
        choice = -1; //La eleccion del menu
        for (int i = 0; i < 40; ++i) printf("#");
        printf("\n");
        char menu[] = "MENU";
        int longitud = strlen(menu);
        int espacios = (40 - longitud) / 2;
        for (int i = 0; i < espacios; i++) putchar(' ');
        printf("%s\n", menu);
        for (int i = 0; i < 40; ++i) printf("#");
        printf("\n");
        printf("1.Insertar nuevo usuario\n");
        printf("2.Listar todos los usuarios existentes \n");
        printf("3.Operar como un usuario especifico\n");
        printf("4.Salir\n");
        printf("Elija la letra de la opcion deseada: ");
        scanf("%d", &choice);
        //choice = 1;
        if (choice == 1){
            usuario = rellenar_datos(usuario);
            lista_de_usuarios= lista_usuarios(lista_de_usuarios, usuario);
            printf("\n%d\n", lista_de_usuarios.cantidad_usuarios);
        }
        else if (choice == 2){
            print_users(lista_de_usuarios);
        }
        else if (choice == 3) {
            int option = -1;
            while (option != 5) {
                printf("\n1.Enviar solicitudes de amistad\n");
                printf("2.Gestionar las solicitudes pendientes\n");
                printf("3.Realizar una publicacion\n");
                printf("4.Listar las publicaciones del usuario seleccionado\n");
                printf("5.Salir\n");
                printf("Elija la letra de la opcion deseada: ");
                scanf("%d", &option);
                if (option == 1);
                else if (option == 2);
                else if (option == 3);
                else if (option == 4);
                else if (option == 5) printf("\nSaliendo...\n\n");
                else printf("Opcion inexistente.Elija la letra de la opcion deseada\n");

            }
        } else if (choice == 4) printf("\nSaliendo...");
        else {
            printf("Opcion inexistente.Elija el numero de la opcion deseada\n");
            scanf("%d\n", &choice);
        }
    }

}


//Colocar el rellenar_datos() aqui Paula
user rellenar_datos(user user1) {
    // Validación de nombre
    do {
        printf("\nInserta nombre de usuario: ");
        scanf("%s", user1.name);
    } while (!isupper(user1.name[0]) || !islower(user1.name[1]));

    // Validación de edad
    int age;
    char buffer[10];
    do {
        printf("\nInserta tu edad (ej: si tienes 11 anos, escribe 11): ");
        scanf("%s", buffer);
        age = atoi(buffer);
    } while (age <= 0 || age > 120);
    user1.age = age;

    //Validación de correo
    do {
        printf("\nInserta tu correo electronico: ");
        scanf("%s", user1.mail);
    } while (strchr(user1.mail, '@') == NULL || strchr(user1.mail, '.') == NULL);

    // Validación de ubicación
    char ciudad[50];
    do {
        printf("\nInserta tu ubicacion (ciudad): ");
        scanf("%s", ciudad);
    } while (!isupper(ciudad[0]) || !islower(ciudad[1]));
    strcpy(user1.ubicacion, ciudad);

    // Ingreso de gustos
    printf("\nInserta 5 gustos o preferencias:\n");
    for (int i = 0; i < MAX_GUSTOS; i++) {
        printf("Gusto %d:", i + 1);
        scanf("%s", user1.gustos[i]);
    }
    printf("\n");
    return user1;
}

user_list lista_usuarios(user_list usuarios, user nuevo_usuario){
    if (usuarios.cantidad_usuarios == 0){
        usuarios.lista_de_usuarios = malloc(sizeof(user));
    } else{
        usuarios.lista_de_usuarios = (user*) realloc(usuarios.lista_de_usuarios, (usuarios.cantidad_usuarios+1)*sizeof(user));
    }
    usuarios.lista_de_usuarios[usuarios.cantidad_usuarios] = nuevo_usuario;
    usuarios.cantidad_usuarios++;
    return usuarios;
}

void print_users(user_list  usuarios){
    for(int i=0; i<usuarios.cantidad_usuarios; i++){
        printf("%d) %s\n",i+1, usuarios.lista_de_usuarios[i].name);
    }
}
