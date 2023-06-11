#include <stdio.h>
#include "users.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "time.h"
#include "amigos.c"

int menu(user_list lista_de_usuarios){ //si pones una letra entra en bucle !!!!
    int choice = -1; //La eleccion del menu
    user usuario;
    Dic dic;
    initializeDic(&dic, 100);

    //Centramos la palabra 'MENU' y decoramos con #
    while (choice != 5 ) {
        choice = -1; // Reinicializamos la eleccion del menu en cada iteración

        for (int i = 0; i < 40; ++i) printf("#"); // Imprime una línea de caracteres '#'
        printf("\n");

        char menu[] = "SER-I-ON"; // Título del menú
        int longitud = strlen(menu);
        int espacios = (40 - longitud) / 2;

        for (int i = 0; i < espacios; i++) putchar(' '); // Imprime espacios en blanco para centrar el título
        printf("%s\n", menu); // Imprime el título del menú

        for (int i = 0; i < 40; ++i) printf("#"); // Imprime otra línea de caracteres '#'
        printf("\n");

        printf("1. Eres nuevo? Crea nuevo usuario\n");
        printf("2. Listar nuestra comunidad de cinefilos\n");
        printf("3. Ya tienes usuario? Opera como usuario ya existente\n");
        printf("4. Buscar usuarios por genero\n");
        printf("5. Salir\n");
        printf("Elija el numero de la opcion deseada:");
        scanf("%d", &choice); // Leer la opción seleccionada por el usuario

        // Evaluar la opción seleccionada por el usuario
        if (choice == 1){
            usuario = rellenar_datos(usuario); // Obtener los datos del nuevo usuario
            lista_de_usuarios= lista_usuarios(lista_de_usuarios, usuario); // Agregar el usuario a la lista de usuarios
        }
        else if (choice == 2){
            print_users(lista_de_usuarios); // Imprimir la lista de usuarios
        }
        else if (choice == 3) {
            char u[MAX_STRING_LENGTH];
            int state = FALSE;
            while (state != TRUE) {
                printf("Nombre de usuario:");
                scanf("%s", u); // Leer el nombre de usuario del usuario existente
                if (buscar_usuario(lista_de_usuarios, u) == NULL) {
                    printf("Asegurate de insertar antes tu nombre de usuario en la lista!\n\n");
                    state = FALSE; // Continuar solicitando el nombre de usuario hasta que exista en la lista
                } else {
                    state = TRUE; // El nombre de usuario es válido
                }
            }

            // Submenú para el usuario existente
            int option = -1;
            user usuario_actual = *buscar_usuario(lista_de_usuarios, u);
            while (option != 7) {
                printf("\n1. Envia solicitudes de amistad\n");
                printf("2. Gestiona las solicitudes pendientes\n");
                printf("3. ¿Que se te pasa por tu mente? Publica algo\n");
                printf("4. Ver tus publicaciones :)\n");
                printf("5. Ver los post de tus amigos <3\n");
                printf("6. Tus palabras mas usadas!\n");
                printf("7. Salir\n");
                printf("Elija el numero de la opcion deseada:");
                scanf("%d", &option); // Leer la opción seleccionada por el usuario dentro del submenú

                // Evaluar la opción seleccionada por el usuario dentro del submenú
                if (option == 1) {
                    char usuario_buscado[MAX_STRING_LENGTH];
                    user usuario_amigo;
                    printf("Escribe el nombre de usuario que quieres seguir:");
                    scanf("%s", usuario_buscado); // Leer el nombre de usuario que se desea seguir

                    while (buscar_usuario(lista_de_usuarios, usuario_buscado) == NULL) {
                        printf("Escribe el nombre de usuario que quieres seguir:");
                        scanf("%s", usuario_buscado); // Solicitar nuevamente el nombre de usuario si no existe en la lista
                    }
                    usuario_amigo = *buscar_usuario(lista_de_usuarios, usuario_buscado);
                    usuario_amigo.solicitudes_amistad = enviar_solicitud_amistad(u, usuario_amigo.solicitudes_amistad); // Enviar solicitud de amistad al usuario deseado
                    printf("\nSolicitud enviada a %s\n", usuario_buscado);

                } else if (option == 2) {
                    int old_cant_users = usuario_actual.amigos.cantidd_amigos;
                    usuario_actual.amigos = recibir_solicitud_amistad(&usuario_actual); // Recibir y gestionar solicitudes de amistad pendientes

                    for (int i = old_cant_users; i < usuario_actual.amigos.cantidd_amigos; ++i) {
                        user *usuario_amigo = buscar_usuario(lista_de_usuarios, usuario_actual.amigos.lista_amigos[i]);
                        usuario_amigo->amigos.lista_amigos[usuario_amigo->amigos.cantidd_amigos] = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
                        strcpy(usuario_amigo->amigos.lista_amigos[usuario_amigo->amigos.cantidd_amigos], usuario_actual.name) ;
                        usuario_amigo->amigos.cantidd_amigos++;
                        lista_de_usuarios = actualizar_usuario(lista_de_usuarios, *usuario_amigo); // Actualizar la lista de usuarios con los cambios en la solicitud de amistad
                    }
                    printf("\nTienes %d amigos son:\n", usuario_actual.amigos.cantidd_amigos);
                    for (int i = 0; i < usuario_actual.amigos.cantidd_amigos; ++i) {
                        printf("\n%d) %s\n", i+1, usuario_actual.amigos.lista_amigos[i]); // Imprimir la lista de amigos del usuario
                    }

                } else if (option == 3) {
                    post *publi;
                    // Añadir una publicación al usuario actual
                    publi = add_post(&usuario_actual, dic);
                    // Si la publicación es NULL, significa que no se pudo agregar correctamente
                    if (publi == NULL){
                        free(publi); // Liberar la memoria asignada previamente
                    } else{
                        usuario_actual.publi = publi;
                        usuario_actual.cant_post++;
                    }
                } else if (option == 4) {
                    print_posts(&usuario_actual); // Imprimir las publicaciones del usuario
                } else if (option == 5) {
                    for (int i = 0; i < usuario_actual.amigos.cantidd_amigos; ++i) {
                        user* imprimir_post = buscar_usuario(lista_de_usuarios, usuario_actual.amigos.lista_amigos[i]);
                        for (int j = 0; j < imprimir_post->cant_post; ++j) {
                            printf("\n** %s **\n%s\n", imprimir_post->publi[j].title, imprimir_post->publi[j].post); // Imprime el título y el contenido de cada publicación
                            usuario_actual.publi = sistema_likes(imprimir_post, &usuario_actual, j); // Sistema de likes para las publicaciones de los amigos del usuario
                        }
                    }
                }
                else if(option == 6){
                    print_dictionary(&dic); // Imprimir el diccionario de palabras utilizadas
                    printTopNWords(&dic, 5);// Imprimir las palabras más frecuentes
                } else if (option == 7) {
                    printf("\nSaliendo...\n");
                    break; // Salir del submenú
                }
                else {
                    printf("\nOpcion inexistente.Elija el numero de la opcion deseada\n"); // Opción inválida
                    option = -1;
                }
                lista_de_usuarios = actualizar_usuario(lista_de_usuarios, usuario_actual); // Actualizar la lista de usuarios con los cambios realizados en el submenú

            }
        }
        else if (choice == 4) {
            char genero[MAX_STRING_LENGTH];
            printf("\nGeneros disponibles\n");
            printf("Animacion\n");
            printf("Aventura\n");
            printf("Ciencia ficcion\n");
            printf("Cine de autor\n");
            printf("Comedia\n");
            printf("Crimen\n");
            printf("Documental\n");
            printf("Drama\n");
            printf("Fantasia\n");
            printf("Guerra\n");
            printf("Historica\n");
            printf("Misterio\n");
            printf("Musical\n");
            printf("Romance\n");
            printf("Superheroes\n");
            printf("Suspenso\n");
            printf("Thriller psicologico\n");
            printf("Western\n");
            printf("\nIngrese el genero a buscar:");
            scanf(" %s", genero); // Leer el género deseado
            imprimir_usuarios_por_genero(genero, &lista_de_usuarios); // Imprimir usuarios que tienen el género especificado
            }
        else if (choice == 5) printf("\nSaliendo..."); // Salir del programa
        else {
            printf("\nOpcion inexistente.\n"); // Opción inválida
            scanf("%d\n", &choice); // Leer nuevamente la opción
            fflush(stdin);
        }
    }

}


//Colocar el rellenar_datos() aqui Paula
user rellenar_datos(user user1) {
    // Validación de nombre
    do {
        printf("\nInserta nombre de usuario: ");
        getchar();
        scanf("%[^,\n]", user1.name);
    } while (!isupper(user1.name[0]) || !islower(user1.name[1]));

    // Validación de edad
    int age;
    char buffer[10];
    do {
        printf("\nInserta tu edad (ej: si tienes 11 anos, escribe 11): ");
        getchar();
        scanf("%[^,\n]", buffer);
        age = atoi(buffer);
    } while (age <= 0 || age > 120);
    user1.age = age;

    //Validación de correo
    do {
        printf("\nInserta tu correo electronico: ");
        getchar();
        scanf("%[^,\n]", user1.mail);
    } while (strchr(user1.mail, '@') == NULL || strchr(user1.mail, '.') == NULL);

    // Validación de ubicación
    char ciudad[50];
    do {
        printf("\nInserta tu ubicacion (ciudad): ");
        getchar();
        scanf("%[^,\n]", ciudad);
    } while (!isupper(ciudad[0]) || !islower(ciudad[1]));
    strcpy(user1.ubicacion, ciudad);

    // Ingreso de gustos
    printf("\nInserta 5 gustos o preferencias:\n");
    printf("\nGeneros disponibles\n");
    printf("Animacion\n");
    printf("Aventura\n");
    printf("Ciencia ficcion\n");
    printf("Cine de autor\n");
    printf("Comedia\n");
    printf("Crimen\n");
    printf("Documental\n");
    printf("Drama\n");
    printf("Fantasia\n");
    printf("Guerra\n");
    printf("Historica\n");
    printf("Misterio\n");
    printf("Musical\n");
    printf("Romance\n");
    printf("Superheroes\n");
    printf("Suspenso\n");
    printf("Thriller psicologico\n");
    printf("Western\n");
    printf("O un gusto singular ;)\n");
    for (int i = 0; i < MAX_GUSTOS; i++) {
        printf("\nGusto %d:", i + 1);
        getchar();
        scanf("%[^\n]", user1.gustos[i]);
    }
    getchar();
    printf("\n");

    // Configuración inicial de solicitudes de amistad, amigos y publicaciones
    user1.solicitudes_amistad = init_queue();
    user1.amigos.cantidd_amigos = 0;
    user1.amigos.lista_amigos = (char**)malloc( sizeof(char*));
    user1.cant_post = 0;

    // Guardar los datos del usuario en un archivo
    FILE* f = fopen("f_users.txt", "r+");
    fseek(f, 0, SEEK_END); //vamos al final del fichero
    fprintf(f, "%s, %d, %s, %s, %s, %s, %s, %s, %s\n", user1.name,  user1.age, user1.mail, user1.ubicacion, user1.gustos[0], user1.gustos[1], user1.gustos[2], user1.gustos[3], user1.gustos[4]);
    fclose(f);
    return user1;
}

user_list lista_usuarios(user_list usuarios, user nuevo_usuario){
    if (usuarios.cantidad_usuarios == 0){
        usuarios.lista_de_usuarios = malloc(sizeof(user));
    } else{
        usuarios.lista_de_usuarios = (user*) realloc(usuarios.lista_de_usuarios, (usuarios.cantidad_usuarios+1)*sizeof(user));
    }

    // Agregar el nuevo usuario a la lista
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
    // Verificar si la lista de usuarios está vacía
    if (usuarios.lista_de_usuarios == NULL || usuarios.cantidad_usuarios == 0) {
        printf("\nNo hay usuarios en la lista\n");
        return NULL;
    }

    // Verificar si el nombre de usuario está vacío
    if (name[0] == '\0') {
        printf("\nEl nombre de usuario proporcionado está vacío\n");
        return NULL;
    }

    // Buscar el usuario en la lista
    for (int i = 0; i < usuarios.cantidad_usuarios; ++i) {
        if (strcmp(usuarios.lista_de_usuarios[i].name, name) == 0){
            // Si se encuentra el usuario, se devuelve un puntero a él
            return &(usuarios.lista_de_usuarios[i]);
        }
    }

    // Si no se encuentra el usuario, se muestra un mensaje de error
    printf("\nUsuario %s no encontrado :( \n", name);
    return NULL;
}

user_list actualizar_usuario(user_list lista_usuarios, user usuario_nuevo){
    // Recorrer la lista de usuarios
    for (int i = 0; i < lista_usuarios.cantidad_usuarios; ++i) {
        // Comparar los nombres de usuario
        if (strcmp(lista_usuarios.lista_de_usuarios[i].name, usuario_nuevo.name) == 0){
            // Actualizar el usuario existente con los datos del usuario nuevo
            lista_usuarios.lista_de_usuarios[i] = usuario_nuevo;
            return lista_usuarios;
        }
    }
}

user generate_user(){
    // Arreglos de nombres, apellidos, gustos y ciudades
    const char* names[MAX_USERS] = {"Carmen", "Lucas", "Maria", "Mario", "Jimena", "Carlos", "Albert", "Alba", "Esther", "Hugo", "Mateo", "Leo", "Dani", "Anna", "Alexia", "Sara", "Valentina", "Zoe", "Olivia", "Sergio"};
    const char* surnames[MAX_USERS] = {"García", "Lopez", "Martinez", "Rodriguez", "Gonzalez", "Fernandez", "Sanchez", "Perez", "Gomez", "Martin", "Torres", "Romero", "Morales", "Ortega", "Delgado", "Muñoz", "Navarro", "Vargas", "Jimenez", "Rivas"};
    const char* gustos[MAX_USERS] = {"Acción", "Aventura", "Comedia", "Drama", "Ciencia ficcion", "Terror", "Suspenso", "Romance", "Fantasia", "Animacion", "Documental", "Crimen", "Mistero", "Superheroes", "Guerra", "Western", "Musical", "Històrica", "Thriller psicologico", "Cine de autor"};
    const char* ciudades[MAX_USERS] = {"Madrid", "Barcelona", "Valencia", "Sevilla", "Zaragoza", "Malaga", "Murcia", "Palma de Mallorca", "Bilbao", "Alicante", "Cordoba", "Valladolid", "Vigo", "Gijon", "Hospitalet de Llobregat", "A Coruña", "Granada", "Vitoria", "Elche", "Oviedo"};
    const char* symbol[2] = {".", "_"};

    user usuario;

    // Generar datos aleatorios para el usuario
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
    usuario.amigos.cantidd_amigos = 0;
    usuario.amigos.lista_amigos = (char**)malloc( sizeof(char*));
    usuario.cant_post = 0;

    return usuario;
}

user_list file_users(user_list lista_de_usuarios, int cantidad_usuarios){
    // Abre el archivo "f_users.txt" en modo de escritura
    FILE* f = fopen("f_users.txt", "w");

    // Crea una variable para almacenar un usuario
    user usuario;

    // Genera usuarios aleatorios y escribe sus datos en el archivo
    for (int i = 0; i < cantidad_usuarios; ++i) {
        usuario = generate_user();
        fprintf(f, "%s, %d, %s, %s, %s, %s, %s, %s, %s\n", usuario.name, usuario.age, usuario.mail,
                usuario.ubicacion, usuario.gustos[0], usuario.gustos[1], usuario.gustos[2], usuario.gustos[3],
                usuario.gustos[4]);
        // Agrega el usuario a la lista de usuarios
        lista_de_usuarios = lista_usuarios(lista_de_usuarios, usuario);
    }

    // Cierra el archivo
    fclose(f);

    // Devuelve la lista de usuarios actualizada
    return lista_de_usuarios;
}

user_list read_users(user_list lista_de_usuarios){
    // Abre el archivo "f_users.txt" en modo de lectura
    FILE* f = fopen("f_users.txt", "r");

    // Crea una variable para almacenar un usuario
    user usuario;

    // Lee los datos de los usuarios del archivo
    while (fscanf(f, "%[^,\n], %d, %[^,\n], %[^,\n], %[^,\n], %[^,\n], %[^,\n], %[^,\n], %[^,\n]\n",
                  usuario.name, &usuario.age, usuario.mail, usuario.ubicacion,
                  usuario.gustos[0], usuario.gustos[1], usuario.gustos[2],
                  usuario.gustos[3], usuario.gustos[4]) != EOF){

        // Inicializa las estructuras de datos del usuario
        usuario.solicitudes_amistad = init_queue();
        usuario.amigos.cantidd_amigos = 0;
        usuario.amigos.lista_amigos = (char**)malloc( sizeof(char*));
        usuario.cant_post = 0;

        // Agrega el usuario a la lista de usuarios
        lista_de_usuarios = lista_usuarios(lista_de_usuarios, usuario);
    }

    // Cierra el archivo
    fclose(f);

    // Devuelve la lista de usuarios actualizada
    return lista_de_usuarios;
}

post* add_post(user* usuario, Dic dic){
    // Verifica si el usuario no tiene publicaciones previas
    if(usuario->cant_post==0){
        usuario->publi = malloc(sizeof(post));
    }else{
        usuario->publi = (post*) realloc(usuario->publi, (usuario->cant_post+1)* sizeof(post));
    }

    // Inicializa los campos del nuevo post
    usuario->publi[usuario->cant_post].pilaLikes = NULL;
    printf("\nTitulo del post:");
    getchar();
    scanf("%[^\n]", usuario->publi[usuario->cant_post].title);
    //printf("%s", usuario.publi->title);
    printf("Escribe lo que quieras subir(120):");
    getchar();
    fgets(usuario->publi[usuario->cant_post].post, MAX_LEN_POSTS-1, stdin);


    // Verifica si el post excede el límite de caracteres permitidos
    if (usuario->publi[usuario->cant_post].post[strlen(usuario->publi[usuario->cant_post].post) - 1] != '\n') {
        printf("\nTu post es muuuuuuuuy largo ;(\n");
        // Limpia el búfer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        return NULL;
    }else{
        usuario->publi[usuario->cant_post].post[strcspn(usuario->publi[usuario->cant_post].post, "\n")] = '\0';
        usuario->publi->post_idx = usuario->cant_post;
        usuario->publi[usuario->cant_post].totalLikes = 0;

        // Actualiza el diccionario con el título y contenido del post
        post aux_post = usuario->publi[usuario->cant_post];
        update_dictionary(&dic, aux_post.title); // Pasar el título del post a la función update_dictionary
        update_dictionary(&dic, aux_post.post); // Pasar el contenido del post a la función update_dictionary

        // Convierte el título del post a mayúsculas
        int i = 0;
        while (usuario->publi[usuario->cant_post].title[i] != '\0') {
            usuario->publi[usuario->cant_post].title[i] = toupper(usuario->publi[usuario->cant_post].title[i]);
            i++;
        }
        // Devuelve el puntero al arreglo de publicaciones actualizado
        return usuario->publi;
    }

}

void print_posts(user* usuario){
    printf("\nPost de %s\n", usuario->name);
    for (int i = 0; i < usuario->cant_post; ++i) {
        printf("\n** %s **\n%s\n", usuario->publi[i].title, usuario->publi[i].post); // Imprime el título y el contenido de cada publicación
    }
}

void imprimir_usuarios_por_genero(char genero[MAX_STRING_LENGTH], user_list* lista_de_usuarios) {
    for (int i = 0; i < lista_de_usuarios->cantidad_usuarios; ++i) {
        for (int j = 0; j < MAX_GUSTOS; ++j) {
            if (strcmp(lista_de_usuarios->lista_de_usuarios[i].gustos[j], genero) == 0) {
                printf("\n%s\n", lista_de_usuarios->lista_de_usuarios[i].name);
            }
        }
    }
}

int buscar_string(char** lista, int longitud, char* buscar){
    for (int i = 0; i < longitud; i++) {
        // Compara cada elemento de la lista con la cadena a buscar
        if (strcmp(lista[i], buscar) == 0) {
            return TRUE; // Si se encuentra la cadena, devuelve TRUE
        }
    }
    return FALSE; // Si no se encuentra la cadena, devuelve FALSE
}

post* sistema_likes(user* usuario_post, user* usuario_like, int idx_post){
    char like[3];

    // Verificar si el usuario ya ha dado like al post
    if (haDadoLike(usuario_post->publi[idx_post].pilaLikes, usuario_like->name) == FALSE){
        printf("\nQuieres dar <3 a este post pon '<3' sino teclea 'NO'");
        scanf("%s", like);
        printf("\n");

        // Si el usuario desea dar like, se agrega el like y se incrementa el contador total de likes
        if (strcmp(like, "<3") == 0){
            agregarLike(&usuario_post->publi[idx_post].pilaLikes, usuario_like->name);
            usuario_post->publi[idx_post].totalLikes++;
        }
    } else{
        printf("\nSi quieres retirar el like pulse 'Y' sino teclea 'NO'");
        scanf("%s", like);
        printf("\n");

        // Si el usuario desea retirar el like, se quita el like y se decrementa el contador total de likes
        if (strcmp(like, "Y") == 0){
            quitarLike(&usuario_post->publi[idx_post].pilaLikes, usuario_like->name);
            usuario_post->publi[idx_post].totalLikes--;
        }
    }
    printf("\n<3 %d", usuario_post->publi[idx_post].totalLikes);
    return usuario_post->publi;
}

void update_dictionary(Dic* dic, char *text) {
    char *word = text;
    word = strtok(word, " ,.¡!¿?()/:;"); // Obtener la primera palabra del texto
    while (word != NULL) {
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]); // Pasa las palabras a minúsculas, para que cuente "hola" y "HoLa" como la misma palabra.
        }
        insert(dic, word); // Agregar la palabra al diccionario
        word = strtok(NULL, " ,.¡!¿?()/:;"); // Obtener la siguiente palabra del texto
    }
}

void print_dictionary(Dic* dic) {
    printf("Diccionario:\n");
    for (int i = 0; i < dic->size; i++) {
        if (dic->table[i] != NULL) {
            // Si hay un elemento en la posición i de la tabla hash del diccionario
            printf("Palabra: %s, Apariciones: %d\n", dic->table[i]->key, dic->table[i]->count);
            // Imprimir la palabra y el número de apariciones en el diccionario
        }
    }
}