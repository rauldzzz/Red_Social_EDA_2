#include <stdio.h>
#include "users.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    printf("1.Insertar nuevo usuario\n");
    printf("2.Listar todos los usuarios existentes \n");
    printf("3.Operar como un usuario especifico\n");
    printf("4.Salir\n" );
    printf("Elija el número de la opción deseada\n");
    scanf("%d\n",&choice);
    while(choice <= 4){
        if(choice == 1 );
        else if(choice == 2 );
        else if(choice == 3 ){
            int option;
            printf("a.Enviar solicitudes de amistad ");
            printf("b.Gestionar las solicitudes pendientes ");
            printf("c.Realizar una publicación ");
            printf("d.Listar las publicaciones del usuario seleccionado ");
            scanf("Elija la letra de la opción deseada %c",&option);

            if(option == "a" || option == "A" );
            else if(option == "b" || option == "B" );
            else if(option == "c" || option == "C" );
            else if(option == "d" || option == "D" );
            else{
                printf("Opción inexistente.Elija la letra de la opción deseada\n");
                scanf("%c\n",&option);
            }
        }
        else if(choice == 4) break;
        else{
           printf("Opción inexistente.Elija el número de la opción deseada\n");
           scanf("%d\n",&choice);
        }
    }


}





//Colocar el rellenar_datos() aqui Paula
void rellenar_datos(user *user1) {
    // Validación de nombre
    do {
        printf("Inserta nombre de usuario: \n");
        scanf("%s", user1->name);
    } while (!isupper(user1->name[0]) || !islower(user1->name[1]));

    // Validación de edad
    int age;
    char buffer[10];
    do {
        printf("Inserta tu edad (ej: si tienes 11 años, escribe 11): \n");
        scanf("%s", buffer);
        age = atoi(buffer);
    } while (age <= 0 || age > 120);
    user1->age = age;

    //Validación de correo
    do {
        printf("Inserta tu correo electrónico: \n");
        scanf("%s", user1->mail);
    } while (strchr(user1->mail, '@') == NULL || strchr(user1->mail, '.') == NULL);

    // Validación de ubicación
    char ciudad[50];
    do {
        printf("Inserta tu ubicación (ciudad): \n");
        scanf("%s", ciudad);
    } while (!isupper(ciudad[0]) || !islower(ciudad[1]));
    strcpy(user1->ubicacion, ciudad);

    // Ingreso de gustos
    printf("Inserta 5 gustos o preferencias: \n");
    for (int i = 0; i < MAX_GUSTOS; i++) {
        printf("Gusto %d: ", i + 1);
        scanf("%s", user1->gustos[i]);
    }
}

user* lista_usuarios(user* usuarios, user nuevo_usuario, int cantidad_usuarios){
    if (cantidad_usuarios == 0){
        usuarios = malloc(sizeof(user));
    } else{
        usuarios = (user*) realloc(usuarios, (cantidad_usuarios+1)*sizeof(user));
    }
    usuarios[cantidad_usuarios] = nuevo_usuario;
    cantidad_usuarios++;
    return usuarios;
}

void print_users(user* usuarios, int cantidad_users){
    for(int i=0; i<cantidad_users; i++){
        printf("%d) %s\n",i+1, usuarios[i].name);
    }
}
