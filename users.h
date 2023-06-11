#ifndef RED_SOCIAL_PROYECTO_USERS_H
#define RED_SOCIAL_PROYECTO_USERS_H
#include <stdlib.h>
#include <string.h>
#include "amigos.h"

#define MAX_STRING_LENGTH 50
#define MAX_GUSTOS 5
#define MAX_USERS 20
#define MAX_LEN_POSTS 120

#define TRUE 1
#define FALSE 0

#define SUCCESS 0
#define ERROR -1

typedef struct{
    char title[MAX_STRING_LENGTH]; // Título de la publicación
    char post[MAX_LEN_POSTS]; // Contenido de la publicación
    int post_idx; // Índice de la publicación
    Nodo* pilaLikes; // Pila de likes para la publicación
    int totalLikes; // Número total de likes para la publicación
}post;

typedef struct{
    char** lista_amigos; // Arreglo de punteros a cadenas de caracteres que almacena los nombres de los amigos
    int cantidd_amigos; // Cantidad de amigos en la lista
}friends;

typedef struct {
    char name[MAX_STRING_LENGTH]; // Nombre del usuario
    int age; // Edad del usuario
    char mail[MAX_STRING_LENGTH]; // Correo electrónico del usuario
    char ubicacion[MAX_STRING_LENGTH]; // Ubicación del usuario
    char gustos[MAX_GUSTOS][MAX_STRING_LENGTH]; // Arreglo de gustos del usuario
    Queue* solicitudes_amistad; // Cola de solicitudes de amistad para el usuario
    friends amigos; // Lista de amigos del usuario
    post* publi; // Arreglo de publicaciones del usuario
    int cant_post; // Cantidad de publicaciones del usuario
} user;

typedef struct  {
    user *lista_de_usuarios; // Arreglo de usuarios
    int cantidad_usuarios; // Cantidad de usuarios en la lista
} user_list;


int menu(user_list lista_de_usuarios);
// El código comienza definiendo una función llamada menu que recibe como parámetro una lista de usuarios (user_list).
// Luego se declaran variables locales, como choice (la elección del menú), usuario (un objeto de tipo user) y dic
// (un objeto de tipo Dic). Se inicializa el diccionario dic usando la función initializeDic.
// A continuación, se muestra un bucle while que se ejecutará hasta que la variable choice sea igual a 5
// (que corresponde a la opción "Salir" del menú). Este bucle es el encargado de mostrar el menú y manejar las opciones
// seleccionadas por el usuario.
// Dentro del bucle, se muestra el encabezado del menú con un título centrado y decorado con caracteres #. Luego se
// imprimen las opciones del menú y se solicita al usuario que elija una opción ingresando un número.
// La opción seleccionada se almacena en la variable choice usando scanf.
// A continuación, se realizan diferentes comprobaciones utilizando if y else if para determinar qué acción tomar en
// función de la opción seleccionada. A continuación, describiré brevemente cada opción: Opción 1: Si el usuario
// selecciona 1, se llama a la función rellenar_datos para obtener los datos de un nuevo usuario y se agrega a la lista
// de usuarios utilizando lista_usuarios.
// Opción 2: Si el usuario selecciona 2, se llama a la función print_users para imprimir la lista de usuarios.
// Opción 3: Si el usuario selecciona 3, se le solicita el nombre de usuario y se comprueba si existe en la lista de
// usuarios utilizando buscar_usuario. Si el usuario existe, se muestra un submenú con diferentes opciones relacionadas
// con el usuario seleccionado.
// Opción 4: Si el usuario selecciona 4, se muestra una lista de géneros disponibles y se le solicita al usuario que
// ingrese un género. Luego se llama a la función imprimir_usuarios_por_genero para imprimir los usuarios que tienen
// ese género en la lista de usuarios.
// Opción 5: Si el usuario selecciona 5, se muestra un mensaje de salida y se rompe el bucle while, finalizando
// la ejecución del menú.

user rellenar_datos(user user1);
// se encarga de solicitar información al usuario y asignarla a la estructura user1. Realiza validaciones para asegurar
// que los datos ingresados sean correctos. Luego, inicializa las estructuras de datos relacionadas con las solicitudes
// de amistad, amigos y publicaciones. Finalmente, guarda los datos del usuario en un archivo llamado "f_users.txt".

user_list lista_usuarios(user_list usuarios, user nuevo_usuario);
// se encarga de añadir un nuevo usuario a la lista de usuarios existente en la estructura usuarios.
// Si la cantidad de usuarios es 0, se utiliza malloc para asignar memoria para un solo usuario en lista_de_usuarios.
// De lo contrario, se utiliza realloc para ajustar la memoria asignada para lista_de_usuarios y permitir espacio para el nuevo usuario.
// Luego, el nuevo usuario se agrega al final de la lista en lista_de_usuarios[usuarios.cantidad_usuarios].
// Finalmente, se incrementa el contador de cantidad_usuarios y se devuelve la estructura usuarios actualizada.

void print_users(user_list  usuarios);
// La función print_users se encarga de imprimir por pantalla la lista de usuarios almacenada en la estructura usuarios.
// Se muestra el encabezado "Lista de usuarios:" para indicar que se imprimirá la lista.
// Luego, se recorre la lista de usuarios utilizando un bucle for desde i = 0 hasta i < usuarios.cantidad_usuarios.
// En cada iteración, se imprime el número de usuario (i + 1) y el nombre del usuario correspondiente (usuarios.lista_de_usuarios[i].name).
// La función no devuelve ningún valor, simplemente imprime la lista de usuarios por pantalla.

user* buscar_usuario(user_list usuarios, char name[MAX_STRING_LENGTH]);
// busca un usuario en la lista de usuarios almacenada en la estructura usuarios, utilizando el nombre de usuario
// proporcionado como parámetro.
// En primer lugar, se realiza una verificación para comprobar si la lista de usuarios está vacía. Si es así, se muestra
// un mensaje de error y se devuelve NULL.
// A continuación, se verifica si el nombre de usuario proporcionado está vacío. Si es así, se muestra un mensaje de error y se devuelve NULL.
// Luego, se recorre la lista de usuarios con un bucle for desde i = 0 hasta i < usuarios.cantidad_usuarios.
// En cada iteración, se compara el nombre del usuario actual (usuarios.lista_de_usuarios[i].name) con el nombre de
// usuario buscado (name) utilizando la función strcmp. Si se encuentran dos nombres iguales, se devuelve un puntero al
// usuario encontrado (&(usuarios.lista_de_usuarios[i])). Si no se encuentra el usuario en la lista, se muestra un mensaje de error y se devuelve NULL.
// La función retorna un puntero al usuario encontrado o NULL si el usuario no se encuentra en la lista.

user_list actualizar_usuario(user_list lista_usuarios, user usuario_nuevo);
// recorre la lista de usuarios almacenada en la estructura lista_usuarios y busca un usuario con el mismo nombre que
// el usuario nuevo proporcionado como parámetro.
// Dentro del bucle for, se compara el nombre de usuario del usuario actual (lista_usuarios.lista_de_usuarios[i].name)
// con el nombre de usuario del usuario nuevo (usuario_nuevo.name) utilizando la función strcmp. Si se encuentran dos
// nombres iguales, significa que se ha encontrado un usuario existente en la lista.
// En ese caso, se actualiza el usuario existente con los datos del usuario nuevo. La asignación
// lista_usuarios.lista_de_usuarios[i] = usuario_nuevo sobrescribe el usuario existente con los datos del usuario nuevo.
// Por último, se devuelve la lista de usuarios actualizada (lista_usuarios), que ahora incluye el usuario modificado.

user generate_user();
// genera un usuario aleatorio con datos ficticios. Aquí está el proceso paso a paso:
// Los arreglos names, surnames, gustos y ciudades contienen diferentes nombres, apellidos, gustos y ciudades
// respectivamente que se utilizarán para generar usuarios aleatorios.
// Se crea una estructura de usuario llamada usuario.
// Se generan índices aleatorios para seleccionar un nombre, un apellido, un símbolo y una ciudad aleatoria de los arreglos correspondientes.
// Se utiliza la función sprintf para construir la dirección de correo electrónico del usuario concatenando un nombre y un apellido aleatorios.
// Se genera una edad aleatoria y se asigna al campo age del usuario.
// Se utiliza nuevamente la función sprintf para construir el nombre de usuario del usuario concatenando un nombre,
// un símbolo aleatorio y el año actual menos la edad del usuario.
// Se selecciona una ciudad aleatoria y se copia en el campo ubicacion del usuario. Se generan gustos aleatorios
// seleccionando índices aleatorios del arreglo de gustos y copiándolos en los campos de gustos del usuario.
// Se inicializa una cola vacía para las solicitudes de amistad del usuario.
// Se inicializa el campo cantidd_amigos de la estructura amigos del usuario en 0.
// Se asigna memoria para un puntero a puntero a char en el campo lista_amigos de la estructura amigos del usuario.
// Finalmente, se devuelve la estructura de usuario generada.

user_list file_users(user_list lista_usuarios, int cantidad_usuarios);
// se encarga de generar usuarios aleatorios, escribir sus datos en un archivo y actualizar la lista de usuarios.
// Se abre el archivo "f_users.txt" en modo de escritura utilizando la función fopen.
// Se crea una variable usuario para almacenar temporalmente los datos de un usuario.
// Se genera cantidad_usuarios de usuarios aleatorios mediante la función generate_user.
// Se utiliza la función fprintf para escribir los datos del usuario en el archivo en un formato específico.
// Se agrega el usuario a la lista de usuarios llamando a la función lista_usuarios.
// Se repite el proceso para todos los usuarios generados.
// Finalmente, se cierra el archivo utilizando la función fclose.
// Se devuelve la lista de usuarios actualizada.

user_list read_users(user_list lista_de_usuarios);
// se encarga de leer los datos de los usuarios desde un archivo "f_users.txt" y agregarlos a la lista de usuarios.
// Se abre el archivo "f_users.txt" en modo de lectura utilizando la función fopen.
// Se crea una variable usuario para almacenar temporalmente los datos de un usuario.
// Utilizando la función fscanf, se leen los datos del usuario del archivo en un formato específico.
// Se inicializan las estructuras de datos del usuario, como la cola de solicitudes de amistad, la lista de amigos y el contador de publicaciones.
// Se agrega el usuario a la lista de usuarios llamando a la función lista_usuarios.
// Se repite el proceso hasta que se alcance el final del archivo (EOF).
// Finalmente, se cierra el archivo utilizando la función fclose.
// Se devuelve la lista de usuarios actualizada.

Queue* enviar_solicitud_amistad( char* nombre, Queue *cola_solicitudes_amigos);
// recibe el nombre de un usuario (nombre) y una cola de solicitudes de amistad (cola_solicitudes_amigos), y se encarga
// de agregar el nombre a la cola de solicitudes.
// Utiliza la función enqueue para añadir el nombre a la cola de solicitudes cola_solicitudes_amigos.
// Retorna la cola de solicitudes actualizada después de agregar el nombre.

friends recibir_solicitud_amistad(user *usuario);
// permite al usuario recibir y gestionar las solicitudes de amistad que ha recibido.
// Verifica si la cola de solicitudes de amistad usuario->solicitudes_amistad está vacía utilizando la función
// is_empty_q. Si está vacía, muestra un mensaje indicando que no hay solicitudes de amistad.
// En caso contrario, entra en un bucle que permite gestionar las solicitudes de amistad una por una.
// Pide al usuario que elija entre diferentes opciones: '0' para salir, 'Y' para aceptar la solicitud y 'N' para rechazarla.
// Si el usuario elige '0', muestra un mensaje de salida y finaliza el bucle.
// Si el usuario elige 'Y', muestra un mensaje confirmando que se ha aceptado la solicitud de amistad, agrega el nombre
// del solicitante a la lista de amigos usuario->amigos.lista_amigos, incrementa el contador de amigos usuario->amigos.
// cantidd_amigos y retira la solicitud de amistad de la cola utilizando la función dequeue. Si el usuario elige 'N',
// simplemente retira la solicitud de amistad de la cola utilizando la función dequeue y muestra un mensaje indicando que se ha rechazado la solicitud.
// Si el usuario ingresa una opción incorrecta, muestra un mensaje de error y vuelve a solicitar la elección.
// Al finalizar, retorna la lista de amigos usuario->amigos.

post* add_post(user* usuario, Dic dic);
// se encarga de agregar un nuevo post al perfil de un usuario. A continuación, se describen los pasos principales:
// Verifica si el usuario ya tiene publicaciones previas. Si no las tiene, se asigna memoria para el arreglo de
// publicaciones utilizando malloc. En caso contrario, se utiliza realloc para redimensionar el arreglo y agregar
// espacio para la nueva publicación.
// Se solicita al usuario que ingrese el título del post utilizando scanf.
// Se solicita al usuario que ingrese el contenido del post utilizando fgets. Se verifica si el post excede el límite
// de caracteres permitidos y se muestra un mensaje de error en caso afirmativo.
// Se realiza un ajuste en la cadena del contenido del post para eliminar el salto de línea final y se actualizan otros
// campos del nuevo post, como el índice, el total de likes y la pila de likes.
// Se convierte el título del post a mayúsculas por razones est

void print_posts(user *usuario);
// se encarga de imprimir en pantalla todos los posts de un usuario.
// Imprime el nombre del usuario para identificar los posts que le pertenecen.
// Utiliza un bucle for para recorrer todas las publicaciones del usuario.
// En cada iteración, imprime el título y el contenido de la publicación utilizando printf.
// Los posts se imprimen con un formato específico para destacar el título y el contenido.

void imprimir_usuarios_por_genero(char genero[MAX_STRING_LENGTH], user_list* lista_de_usuarios);
// recibe un género como parámetro y busca en la lista de usuarios aquellos que tengan ese género entre sus gustos.
// Utiliza dos bucles for anidados para recorrer todos los usuarios y sus gustos.
// En cada iteración, compara el género proporcionado con cada uno de los gustos del usuario actual utilizando strcmp.
// Si encuentra una coincidencia, imprime el nombre del usuario utilizando printf.
// La función asume que lista_de_usuarios es un puntero a una estructura user_list que contiene la lista de usuarios y su cantidad.

int buscarString(char** lista, int longitud, char* buscar);
/** Esta función no está implementada, es un aspecto a mejorar. La funcionalidad que le dariamos sería la de que no nos
 * podamos mandar solicitud de amistad a nosotros mismos y tampoco podamos mandar solitud a alguien que ya es nuestro amigo */
// recibe una lista de cadenas (lista), su longitud (longitud), y la cadena a buscar (buscar).
// La función itera sobre cada elemento de la lista utilizando un bucle for.
// En cada iteración, compara el elemento actual de la lista con la cadena a buscar utilizando la función strcmp.
// Si se encuentra una coincidencia (es decir, si el resultado de strcmp es 0), la función devuelve TRUE.
// Si se recorren todos los elementos de la lista sin encontrar una coincidencia, la función devuelve FALSE.

post* sistema_likes(user* usuario_post, user* usuario_like, int idx_post);
// permite a un usuario dar o retirar "likes" a un post.
// La función recibe como parámetros el usuario que realizó el post (usuario_post), el usuario que desea dar o retirar
// el like (usuario_like) y el índice del post en el arreglo de publicaciones (idx_post).
// Verifica si el usuario ya ha dado like al post utilizando la función haDadoLike. Si el usuario no ha dado like,
// le permite dar un like ingresando "<3" cuando se le solicita.
// Si el usuario desea dar like, se agrega el like utilizando la función agregarLike y se incrementa el contador total de likes del post.
// Si el usuario ya ha dado like, le permite retirar el like ingresando "Y" cuando se le solicita.
// Si el usuario desea retirar el like, se quita el like utilizando la función quitarLike y se decrementa el contador total de likes del post.
// Finalmente, se imprime el número actualizado de likes del post.

void update_dictionary(Dic* dic, char *text);
// recibe un diccionario (dic) y un texto (text).
// Se inicializa un puntero word con la dirección de memoria del texto.
// Utilizando la función strtok, se extrae la primera palabra del texto utilizando como delimitadores los caracteres " ,.¡!¿?()/:;".
// Se inicia un bucle while que se ejecuta mientras word no sea nulo.
// En cada iteración, se recorre la palabra y se convierte cada carácter a minúscula utilizando la función tolower.
// Se inserta la palabra en el diccionario utilizando la función insert.
// Se utiliza nuevamente strtok con el primer argumento nulo para obtener la siguiente palabra del texto.
// El proceso se repite hasta que no hayan más palabras en el texto.

void print_dictionary(Dic* dic);
// recibe un diccionario (dic) y se encarga de imprimir por pantalla todas las palabras y su número de apariciones en el diccionario.
// Se muestra un encabezado "Diccionario:" para indicar que se imprimirá el contenido del diccionario.
// Se itera sobre cada posición de la tabla hash del diccionario, desde 0 hasta dic->size - 1.
// Si hay un elemento en la posición actual (dic->table[i] != NULL), se imprime la palabra y el número de apariciones en el diccionario utilizando printf.
// El resultado es una lista de palabras con sus respectivas apariciones en el diccionario.

#endif //RED_SOCIAL_PROYECTO_USERS_H
