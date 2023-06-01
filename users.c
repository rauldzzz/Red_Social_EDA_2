#include <stdio.h>
#include "users.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "time.h"

int menu(user_list lista_de_usuarios) {
    int choice = -1; // La eleccion del menu
    user usuario;

    while (choice != 4) {
        choice = -1; // La eleccion del menu
        for (int i = 0; i < 40; ++i) printf("#");
        printf("\n");
        char menu[] = "MENU";
        int longitud = strlen(menu);
        int espacios = (40 - longitud) / 2;
        for (int i = 0; i < espacios; i++) putchar(' ');
        printf("%s\n", menu);
        for (int i = 0; i < 40; ++i) printf("#");
        printf("\n");
        printf("1. Insertar nuevo usuario\n");
        printf("2. Listar todos los usuarios existentes\n");
        printf("3. Operar como un usuario especifico\n");
        printf("4. Buscar usuarios por genero\n");
        printf("5. Salir\n");
        printf("Elija el número de la opción deseada: ");
        scanf("%d", &choice);

        if (choice == 1) {
            usuario = rellenar_datos(usuario);
            lista_de_usuarios = lista_usuarios(lista_de_usuarios, usuario);
        } else if (choice == 2) {
            print_users(lista_de_usuarios);
        } else if (choice == 3) {
            char u[MAX_STRING_LENGTH];
            int state = TRUE;
            printf("Nombre de usuario: ");
            scanf("%s", u);
            if (buscar_usuario(lista_de_usuarios, u) == NULL) {
                printf("Asegurate de insertar antes tu nombre de usuario en la lista!\n\n");
                state = FALSE;
            }
            user usuario_actual = *buscar_usuario(lista_de_usuarios, u);
            int option = -1;
            while (option != 5 && state == TRUE) {
                printf("\n1. Enviar solicitudes de amistad\n");
                printf("2. Gestionar las solicitudes pendientes\n");
                printf("3. Realizar una publicacion\n");
                printf("4. Listar las publicaciones del usuario seleccionado\n");
                printf("5. Salir\n");
                printf("Elija el número de la opción deseada: ");
                scanf("%d", &option);

                if (option == 1) {
                    char usuario_buscado[MAX_STRING_LENGTH];
                    user usuario_amigo;
                    printf("Escribe el nombre de usuario que quieres seguir: ");
                    scanf("%s", usuario_buscado);
                    while (buscar_usuario(lista_de_usuarios, usuario_buscado) == NULL) {
                        printf("Escribe el nombre de usuario que quieres seguir: ");
                        scanf("%s", usuario_buscado);
                    }
                    usuario_amigo.solicitudes_amistad = enviar_solicitud_amistad(u, usuario_amigo.solicitudes_amistad);
                    printf("\nSolicitud enviada a %s\n", usuario_buscado);
                } else if (option == 2) {

                } else if (option == 3) {
                } else if (option == 4) {
                } else if (option == 5) {
                    printf("\nSaliendo...\n\n");
                } else {
                    printf("\nOpción inexistente. Elija el número de la opción deseada\n");
                }
            }
        } else if (choice == 4) {
            char genero[MAX_STRING_LENGTH];
            printf("\nIngrese el genero a buscar: \n");
            printf("Generos disponibles\n");
            printf("1. Animacion\n");
            printf("2. Aventura\n");
            printf("3. Ciencia ficcion\n");
            printf("4. Cine de autor\n");
            printf("5. Comedia\n");
            printf("6. Crimen\n");
            printf("7. Documental\n");
            printf("8. Drama\n");
            printf("9. Fantasia\n");
            printf("10. Guerra\n");
            printf("11. Historica\n");
            printf("12. Misterio\n");
            printf("13. Musical\n");
            printf("14. Romance\n");
            printf("15. Superheroes\n");
            printf("16. Suspenso\n");
            printf("17. Thriller psicologico\n");
            printf("18. Western\n");

            scanf("%s", genero);
            buscar_usuarios_por_genero(genero);
        } else {
            printf("\nOpción inexistente.\n");
            scanf("%d\n", &choice);
            fflush(stdin);
        }
    }
    return 0;
}



//Colocar el rellenar_datos()
user rellenar_datos(user user1) {
    // Validación de nombre
    do {
        printf("\nInserta nombre de usuario (tiene que contener 1 mayuscula, 1 simbolo y 1 numero): ");
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

    // Insertar los géneros favoritos de cada usuario para después ver todos los usuarios que les gusta ese mismo
    printf("\nInserta tus 5 generos cinematograficos favoritos (Escribe el numero):\n");
    printf("\nGeneros disponibles:\n");
    printf("1. Animación\n");
    printf("2. Aventura\n");
    printf("3. Ciencia ficción\n");
    printf("4. Cine de autor\n");
    printf("5. Comedia\n");
    printf("6. Crimen\n");
    printf("7. Documental\n");
    printf("8. Drama\n");
    printf("9. Fantasía\n");
    printf("10. Guerra\n");
    printf("11. Histórica\n");
    printf("12. Misterio\n");
    printf("13. Musical\n");
    printf("14. Romance\n");
    printf("15. Superhéroes\n");
    printf("16. Suspenso\n");
    printf("17. Thriller psicológico\n");
    printf("18. Western\n");

    for (int i = 0; i < MAX_GUSTOS; i++) {
        printf("Genero %d:", i + 1);
        scanf("%s", user1.gustos[i]);
    }
    printf("\n");
    user1.solicitudes_amistad = init_queue();
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
    printf("Lista de usuarios:\n");
    for(int i=0; i<usuarios.cantidad_usuarios; i++){
        printf("%d) %s\n",i+1, usuarios.lista_de_usuarios[i].name);
    }
}

user* buscar_usuario(user_list usuarios, char name[MAX_STRING_LENGTH]){
    if (usuarios.lista_de_usuarios == NULL || usuarios.cantidad_usuarios == 0) {
        printf("\nNo hay usuarios en la lista\n");
        return NULL;
    }
    if (name[0] == '\0') {
        printf("\nEl nombre de usuario proporcionado está vacío\n");
        return NULL;
    }
    for (int i = 0; i < usuarios.cantidad_usuarios; ++i) {
        if (strcmp(usuarios.lista_de_usuarios[i].name, name) == 0){
            return &(usuarios.lista_de_usuarios[i]);
        }
    }
    printf("\nUsuario %s no encontrado :( \n", name);
    return NULL;
}

/*#######################################################################*/
user usuario_rdm(FILE * f, int num){
    int contador = 0;
    user user1;
    while(fscanf(f,"%s, %d, %s, %s, %s, %s, %s, %s, %s", user1.name, &user1.age, user1.mail, user1.ubicacion, user1.gustos[0], user1.gustos[1], user1.gustos[2], user1.gustos[3], user1.gustos[4]) != EOF){
        if (contador == num) return user1;
        contador ++;
    }
}

user generate_user(){
    const char* names[MAX_USERS] = {"Carmen", "Lucas", "Maria", "Mario", "Jimena", "Carlos", "Albert", "Alba", "Esther", "Hugo", "Mateo", "Leo", "Dani", "Anna", "Alexia", "Sara", "Valentina", "Zoe", "Olivia", "Sergio"};
    const char* surnames[MAX_USERS] = {"García", "Lopez", "Martinez", "Rodriguez", "Gonzalez", "Fernandez", "Sanchez", "Perez", "Gomez", "Martin", "Torres", "Romero", "Morales", "Ortega", "Delgado", "Muñoz", "Navarro", "Vargas", "Jimenez", "Rivas"};
    const char* gustos[MAX_USERS] = {"Acción", "Aventura", "Comedia", "Drama", "Ciencia ficcion", "Terror", "Suspenso", "Romance", "Fantasia", "Animacion", "Documental", "Crimen", "Mistero", "Superheroes", "Guerra", "Western", "Musical", "Històrica", "Thriller psicologico", "Cine de autor"};
    const char* ciudades[MAX_USERS] = {"Madrid", "Barcelona", "Valencia", "Sevilla", "Zaragoza", "Malaga", "Murcia", "Palma de Mallorca", "Bilbao", "Alicante", "Cordoba", "Valladolid", "Vigo", "Gijon", "Hospitalet de Llobregat", "A Coruña", "Granada", "Vitoria", "Elche", "Oviedo"};
    const char* symbol[2] = {".", "_"};
    user usuario;
    int random_name = rand() % 20;
    int random_surname = rand() % 20;
    sprintf(usuario.mail, "%s.%s@gmail.com", names[random_name], surnames[random_surname]);
    int random_age = rand() % 68 + 13;;
    usuario.age = random_age;
    int random_symbol = rand() % 2;
    sprintf(usuario.name, "%s%s%d", names[random_name], symbol[random_symbol], 2023-usuario.age);
    int random_city = rand() % 20;
    strcpy(usuario.ubicacion, ciudades[random_city]);
    for (int i = 0; i < MAX_GUSTOS; ++i) {
        int random_gusto = rand() % 20;
        strcpy(usuario.gustos[i], gustos[random_gusto]);
    }
    usuario.solicitudes_amistad = init_queue();
    return usuario;
}


user_list file_users(user_list lista_de_usuarios){
    FILE* f = fopen("f_users.txt", "w");
    user usuario;
    for (int i = 0; i < MAX_USERS; ++i) {
        usuario = generate_user();
        fprintf(f, "%s, %d, %s, %s, %s, %s, %s, %s, %s\n", usuario.name, usuario.age, usuario.mail, usuario.ubicacion, usuario.gustos[0], usuario.gustos[1], usuario.gustos[2], usuario.gustos[3], usuario.gustos[4]);
        lista_de_usuarios= lista_usuarios(lista_de_usuarios, usuario);
    }
    fclose(f);
    return lista_de_usuarios;
}


/*######################################################################*/

/*######################################################################*/
//Añadir amigo --> algoritmo busqueda --> error
//solicitud de amistad
//Solicitudes recibidas --> acceptar o no

int buscar_amigo(user_list* usuarios){
    char nombre[MAX_STRING_LENGTH];
    user* usuario_amigo;
    do {
        printf("\nInserta nombre de usuario: ");
        scanf("%s", nombre);
    } while (!isupper(nombre[0]) || !islower(nombre[1]));
    usuario_amigo = buscar_usuario(*usuarios, nombre);
    if (usuario_amigo != NULL) strcpy(usuario_amigo->name, nombre);
    else{
        return ERROR;
    }


}

void add_post(user* user1, const char* text){
    if(strlen(text) > MAX_POST){
        printf("El texto debe tener máximo 120 caracteres.");
    }
}

/*######################################################################*/

//Paula cositas q estic provant

void add_user_to_list(user_list* lista, user usuario) {
    if (lista->cantidad_usuarios >= MAX_USUARIOS) {
        printf("La lista de usuarios está llena. No se puede agregar más usuarios.\n");
        return;
    }

    lista->lista_de_usuarios[lista->cantidad_usuarios] = usuario;
    lista->cantidad_usuarios++;
}

user_list cargar_usuarios_desde_archivo(char filename[MAX_STRING_LENGTH]) {
    FILE* file = fopen("f_users.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    user_list usuarios;
    usuarios.lista_de_usuarios = malloc(MAX_USUARIOS * sizeof(user));
    usuarios.cantidad_usuarios = 0;

    char line[MAX_STRING_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        user nuevo_usuario;

        strcpy(nuevo_usuario.name, token);
        token = strtok(NULL, ",");
        nuevo_usuario.age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(nuevo_usuario.mail, token);
        token = strtok(NULL, ",");
        strcpy(nuevo_usuario.ubicacion, token);

        for (int i = 0; i < MAX_GUSTOS; i++) {
            token = strtok(NULL, ",");
            if (token != NULL) {
                strcpy(nuevo_usuario.gustos[i], token);
            } else {
                strcpy(nuevo_usuario.gustos[i], "");
            }
        }

        usuarios.lista_de_usuarios[usuarios.cantidad_usuarios] = nuevo_usuario;
        usuarios.cantidad_usuarios++;
    }

    fclose(file);

    return usuarios;
}

char generos_cinematograficos[][MAX_STRING_LENGTH] = {
        "Animacion",
        "Aventura",
        "Ciencia ficcion",
        "Cine de autor",
        "Comedia",
        "Crimen",
        "Documental",
        "Drama",
        "Fantasia",
        "Guerra",
        "Historica",
        "Misterio",
        "Musical",
        "Romance",
        "Superheroes",
        "Suspenso",
        "Thriller psicologico",
        "Western"
};


void buscar_usuarios_por_genero(char genero[MAX_STRING_LENGTH]) {
    user_list usuarios = cargar_usuarios_desde_archivo("usuarios.txt");

    user_list usuarios_encontrados;
    usuarios_encontrados.lista_de_usuarios = malloc(usuarios.cantidad_usuarios * sizeof(user));
    usuarios_encontrados.cantidad_usuarios = 0;

    int genero_elegido = atoi(genero);

    for (int i = 0; i < usuarios.cantidad_usuarios; i++) {
        for (int j = 0; j < MAX_GUSTOS; j++) {
            if (strcmp(usuarios.lista_de_usuarios[i].gustos[j], generos_cinematograficos[genero_elegido - 1]) == 0) {
                usuarios_encontrados.lista_de_usuarios[usuarios_encontrados.cantidad_usuarios] = usuarios.lista_de_usuarios[i];
                usuarios_encontrados.cantidad_usuarios++;
                break;
            }
        }
    }

    if (usuarios_encontrados.cantidad_usuarios == 0) {
        printf("No se encontraron usuarios con el género '%s'\n", generos_cinematograficos[genero_elegido - 1]);
    } else {
        printf("Usuarios encontrados con el género '%s':\n", generos_cinematograficos[genero_elegido - 1]);
        for (int i = 0; i < usuarios_encontrados.cantidad_usuarios; i++) {
            user usuario = usuarios_encontrados.lista_de_usuarios[i];
            printf("Nombre: %s\n", usuario.name);
            printf("Edad: %d\n", usuario.age);
            printf("Correo electrónico: %s\n", usuario.mail);
            printf("Ubicación: %s\n", usuario.ubicacion);
            printf("-------------------\n");
        }
    }

    free(usuarios.lista_de_usuarios);
    free(usuarios_encontrados.lista_de_usuarios);
}