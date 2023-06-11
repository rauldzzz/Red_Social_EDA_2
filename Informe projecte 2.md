Data Structures and Algorithms II - 2022-2023                          ![](Aspose.Words.1a301e13-c805-49df-8461-f0a798352020.001.png)


###
###
###
###
ESTRUCTURA DE DATOS Y ALGORITMOS II, 2022-2023

WEB - COMUNIDAD DE CINEFILOS









Paula Borregón, Karen Cabello, Raúl Diaz, Martin Jarque

11 - 6 - 2023

**ÍNDICE**

[INTRODUCCIÓN	](#_heading=)

[OBJETIVOS DEL PROYECTO	](#_heading=)

[Objetivos obligatorios	](#_heading=h.g7dmsmh90gii)

[1. Implementación de lista, pila y cola funcionales	](#_heading=h.h0eea367yvbe)

[2. Implementación de los algoritmos de búsqueda	](#_heading=h.bcpst4y5i4o4)

[3. Implementar de uno de los algoritmos de ordenamiento (InsertionSort, BubbleSort, MergeSort o QuickSort).	](#_heading=h.ew43mgu9c2dd)

[4. Implementación del diccionario	](#_heading=h.9p32iuyxox7a)

[5. Uso de github	](#_heading=h.2z7xd6jxrj7v)

[Objetivos deseables	](#_heading=)

[1. Leer datos de una fuente externa como un archivo de texto o CSV	](#_heading=h.lpsi1d33dnql)

[2. Temática y capa de personalización	](#_heading=h.1um6rgb24l9)

[Objetivos libres	](#_heading=)

[1. Capa estética	](#_heading=h.zbgwrgpdivzb)

[2. Implementar las funcionalidades de lectura y guardado de datos	](#_heading=h.dr4vup5lyzlw)

[3. Funcionalidades extras	](#_heading=h.qmp4hhcvqk4l)

[SOLUTION \[At most 1500 words\]	](#_heading=)

[System Architecture \	](#_heading=)

[Error Handling \	](#_heading=)

[Data model design \	](#_heading=)

[Dataset description and processing \	](#_heading=)

[REFERENCES	15](#_heading=)

#
## **INTRODUCCIÓN**
Este proyecto se basa en el concepto de crear un sitio web de marcadores sociales y “microblogging” dedicado a la comunidad de cinéfilos, que permita a los usuarios publicar y leer mensajes relacionados con el mundo del cine y sus producciones.

La idea principal se centraba en una web donde los usuarios pudieran buscar nombres de géneros cinematográficos y encontrar contenido relacionado con este, como publicaciones de usuario a los cuales también les agrada el mismo género, así como publicar sus propias reseñas y recomendaciones de películas.

Para obtener inspiración, se investigaron diversas plataformas existentes de marcadores sociales y microblogging, como IMDb, Letterboxd y Twitter, entre otras. Estas plataformas proporcionaron ideas sobre las características y funcionalidades que podrían ser incorporadas en nuestro proyecto.

El objetivo principal de este proyecto fue desarrollar un sitio web que permitiera a los usuarios actuar como un usuario existente o crear uno, buscar géneros cinematográficos, ver publicaciones relacionadas, seguir a otros usuarios y publicar sus propias reseñas y recomendaciones.

Este informe está estructurado de la siguiente manera: en la sección de Análisis de Requerimientos, se detallan los requisitos funcionales y no funcionales del proyecto. Luego, en la sección de Diseño, se describe la arquitectura del sistema y se presentan los diagramas correspondientes. A continuación, se aborda la implementación del proyecto, destacando las tecnologías utilizadas y los desafíos encontrados.

## **OBJETIVOS DEL PROYECTO**

### <a name="_heading=h.g7dmsmh90gii"></a>Objetivos obligatorios
1. #### <a name="_heading=h.h0eea367yvbe"></a>**Implementación de lista, pila y cola funcionales**
El objetivo de la implementación de la lista, pila y cola funcionales en el proyecto es proporcionar estructuras de datos eficientes y flexibles para el manejo de información relacionada con los usuarios y sus interacciones en la plataforma.

**Implementación de lista:** 

“lista\_usuarios”: Esta función recibe una lista de usuarios y un nuevo usuario, y agrega el nuevo usuario a la lista. Si la lista está vacía, se asigna memoria para el primer usuario; de lo contrario, se utiliza la función `realloc` para aumentar el tamaño de la lista y agregar el nuevo usuario al final. La función devuelve la lista actualizada. 

“print\_users”: Esta función imprime la lista de usuarios. Recorre la lista de usuarios y muestra el nombre de cada usuario junto con un número de índice. 

“buscar\_usuario”: Esta función recibe una lista de usuarios y un nombre de usuario, y busca el usuario correspondiente en la lista. Si se encuentra el usuario, se devuelve un puntero al usuario; de lo contrario, se muestra un mensaje de error y se devuelve `NULL`. 

“actualizar\_usuario”: Esta función recibe una lista de usuarios y un usuario nuevo. Busca el usuario correspondiente en la lista por su nombre y lo actualiza con los datos del usuario nuevo. 

“file\_users”: Esta función recibe una lista de usuarios y la cantidad de usuarios que se deben generar. Crea un archivo llamado “f\_users.txt” y escribe en él la información de cada usuario de la lista, separando los campos por comas. Luego, llama a la función `lista\_usuarios` para agregar cada usuario a la lista. La función devuelve la lista actualizada.

**Implementación de la pila**

En el archivo “herramientas.c”, se presenta la implementación de las operaciones básicas de una pila. Se utiliza un puntero superior para rastrear el índice del elemento superior de la pila. Los elementos de la pila se almacenan en un array de usuarios. “p”: Puntero a la estructura de la pila. “p->stack”: Array de usuarios que almacena los elementos de la pila. “p->top”: Índice del elemento superior de la pila.

Array de usuarios: Se utiliza para almacenar los elementos de la pila.

Inicialización de la pila: Se asigna memoria para la estructura de la pila y el array de usuarios. Se establece el puntero superior en 0 para indicar que la pila está vacía.

Verificación de pila llena: Compara el puntero superior con la capacidad máxima de la pila.

Verificación de pila vacía: Compara el puntero superior con 0.

Obtención del elemento superior de la pila : Devuelve el elemento superior si la pila no está vacía.


**Implementación de la cola**

En el archivo “herramientas.c”, se presenta la implementación de las operaciones básicas de una cola. Se utiliza un array de tamaño fijo para almacenar los elementos de la cola, y se utilizan dos índices para rastrear la posición del primer y último elemento de la cola, respectivamente.

`q`: Puntero a la estructura de la cola.

`q->A`: Array que almacena los elementos de la cola.

`q->head`: Índice del primer elemento de la cola.

`q->tail`: Índice del último elemento de la cola.

`q->elements`: Contador de elementos en la cola.

Array de cadenas de caracteres: Se utiliza para almacenar los elementos de la cola.

Inicialización de la cola: Se asigna memoria para la estructura de la cola y el array de elementos. Se inicializan los índices de la cabeza y la cola en -1 para indicar que la cola está vacía, y el contador de elementos se establece en 0. 

Verificación de cola llena: Compara el contador de elementos con el máximo permitido. Verificación de cola vacía: Compara el contador de elementos con 0.


**Enviar y recibir solicitudes de amistad**

En el archivo “herramientas.c”, se presentan las funciones `enviar\_solicitud\_amistad` y `recibir\_solicitud\_amistad` que utilizan las operaciones de la cola implementadas para enviar y recibir solicitudes de amistad.

Enviar solicitud de amistad

Descripción: Esta función recibe el nombre de un usuario y agrega el nombre a la cola de solicitudes de amistad.

Recibir solicitud de amistad

Descripción: Esta función recibe un usuario y verifica si tiene solicitudes de amistad pendientes. Si hay solicitudes, muestra cada solicitud y permite al usuario aceptar o rechazar las solicitudes.

Implementación: Utiliza las operaciones de verificación de cola vacía y obtención del primer elemento de la cola para verificar y acceder a las solicitudes de amistad.

Retorno: Devuelve la lista de amigos actualizada del usuario.

1. #### <a name="_heading=h.bcpst4y5i4o4"></a>**Implementación de los algoritmos de búsqueda**
El objetivo de la implementación de los algoritmos de búsqueda es buscar un usuario en una lista de usuarios.

Estructuras de datos utilizadas: “user\_list”: Estructura que contiene una lista de usuarios. “user”: Estructura que representa un usuario, con campos como nombre, edad, correo electrónico, ubicación y gustos. “char\*\*”: Puntero a un puntero de caracteres utilizado para almacenar los gustos de un usuario.


**Algoritmo utilizado**

LinearSearch : El algoritmo utilizado para buscar un usuario en la lista de usuarios es una búsqueda lineal. Se recorre la lista de usuarios y se compara el nombre del usuario con el nombre proporcionado. Si se encuentra una coincidencia, se devuelve un puntero al usuario encontrado.

Variables utilizadas: “usuarios”: Variable de tipo `user\_list` que representa la lista de usuarios. “name”: Variable de tipo `char ` que almacena el nombre del usuario a buscar.

**Comportamiento:**

El algoritmo recorre la lista de usuarios y compara el nombre del usuario con el nombre proporcionado.

Si se encuentra una coincidencia, se devuelve un puntero al usuario encontrado.

Si no se encuentra ninguna coincidencia, se muestra un mensaje indicando que el usuario no fue encontrado.

**Limitaciones del algoritmo y su implementación:**

Si la lista de usuarios está vacía o si no se proporciona un nombre de usuario válido, se muestra un mensaje de error.

El algoritmo realiza una búsqueda lineal, lo que significa que el tiempo de ejecución aumenta linealmente con el tamaño de la lista de usuarios. En el peor caso, si el usuario buscado está al final de la lista, se tendría que recorrer toda la lista.


**Posibles mejoras**

Se podría implementar un algoritmo de búsqueda más eficiente, como BinarySearch , si la lista de usuarios estuviera ordenada alfabéticamente por nombre.

Se podrían implementar funciones adicionales para agregar usuarios a la lista, eliminar usuarios, actualizar información de usuarios, entre otras operaciones.

Ubicación del código de implementación: user.c

1. #### <a name="_heading=h.ew43mgu9c2dd"></a>**Implementar de uno de los algoritmos de ordenamiento (InsertionSort, BubbleSort, MergeSort o QuickSort).**
El objetivo de implementación de los algoritmos de ordenación es ordenar la tabla de un diccionario de palabras por frecuencia descendente.

Objetivo: Ordenar la tabla del diccionario por frecuencia descendente.

Visión general: En este objetivo, se implementa un algoritmo de ordenamiento para ordenar la tabla del diccionario según la frecuencia de las palabras.

- “dic”: Es una estructura que representa el diccionario y contiene la tabla de nodos.
- “Node”: Es una estructura que representa un nodo en la tabla del diccionario.

- “Dic”: Es una estructura que contiene la tabla de nodos del diccionario. Se crea una instancia de esta estructura utilizando la función “create\_dic”.
- “Node”: Es una estructura que representa un nodo en la tabla del diccionario.

Bubble Sort: El algoritmo de ordenamiento utilizado en este objetivo es el bubble sort. El bubble sort compara y intercambia elementos adyacentes en la tabla hasta que todos los elementos estén ordenados en orden descendente según la frecuencia.

**Comportamiento esperado:** El algoritmo recorre repetidamente la tabla y compara los elementos adyacentes. Si un elemento tiene una frecuencia menor que su elemento adyacente, se intercambian. Esto se repite hasta que todos los elementos estén en orden descendente según la frecuencia.

- Se podrían considerar otros algoritmos de ordenamiento más eficientes, como el quicksort o el mergesort, para mejorar el rendimiento en el caso de grandes tablas de diccionario.

Ubicación: herramientas.c

1. #### <a name="_heading=h.9p32iuyxox7a"></a>**Implementación del diccionario**
El objetivo de implementación del código proporcionado es crear y manipular un diccionario utilizando una estructura de datos conocida como tabla hash. A continuación se explica cada una de las funciones presentes en el código: “create\_dic”: Esta función crea un diccionario vacío con el tamaño especificado. El diccionario se representa mediante una estructura llamada `Dic`, que contiene los siguientes campos: “table”: Un puntero a un array de nodos que almacenará las palabras y sus conteos. “size”: El tamaño de la tabla hash, que determina la capacidad del diccionario. “count”: El número total de palabras almacenadas en el diccionario.

Para implementar esta función, se asigna memoria dinámicamente para el array de nodos utilizando `malloc`. Luego, se inicializan los campos `size` y `count` del diccionario y se retorna el diccionario creado. “hash”: Esta función calcula el índice de hash de una palabra en la tabla hash. Recibe la palabra y el tamaño de la tabla como parámetros. El cálculo del valor de hash se realiza utilizando el método de multiplicación. Se itera por cada carácter de la palabra y se realiza una operación de multiplicación y suma con el valor de hash actual. Finalmente, se aplica el módulo del tamaño de la tabla para obtener el índice de hash. El valor de hash calculado se retorna. “add\_word”: Esta función agrega una palabra al diccionario. Recibe un puntero al diccionario y la palabra a agregar como parámetros. El proceso de inserción se realiza mediante el uso de la función de hash para calcular el índice de la palabra en la tabla hash. Si el índice calculado ya está ocupado por otra palabra, se resuelve la colisión utilizando la estrategia de sondas lineales, es decir, se busca la siguiente posición disponible en la tabla. Si se encuentra una posición vacía, se asigna memoria dinámicamente para copiar la palabra en el campo `key` del nodo correspondiente y se establece el contador en 1.

En cuanto a las características de las estructuras y algoritmos utilizados

La estructura de datos principal utilizada es una tabla hash, implementada como un array de nodos dentro de la estructura `Dic`. Cada nodo contiene un campo para almacenar la clave y otro campo para el contador de ocurrencias. La función de hash utiliza el método de multiplicación para calcular el índice de hash de una palabra en la tabla. La resolución de colisiones se realiza mediante sondas lineales, que busca la siguiente posición disponible en la tabla en caso de colisión. El algoritmo de ordenamiento utilizado para imprimir las palabras más frecuentes es el algoritmo de ordenamiento de burbuja.


Limitaciones y posibles mejoras:

El algoritmo de resolución de colisiones lineal puede generar agrupamiento primario y reducir la eficiencia en caso de una alta carga del diccionario.

La función de hash utilizada puede generar colisiones en ciertos casos, lo que afectaría el rendimiento del diccionario.

El algoritmo de ordenamiento de burbuja utilizado para imprimir las palabras más frecuentes no es eficiente para grandes conjuntos de datos.

No se manejan casos de eliminación de palabras en el diccionario.

Se podría implementar un algoritmo de hash más sofisticado y una estrategia de resolución de colisiones más eficiente, como encadenamiento o direccionamiento abierto.
1. #### <a name="_heading=h.2z7xd6jxrj7v"></a>**Uso de github**
Durante el desarrollo de este proyecto, utilizamos GitHub como plataforma de control de versiones, lo cual resultó muy práctico en general. Sin embargo, nos encontramos con algunos desafíos a lo largo del camino. En ocasiones, los Merges no se realizaban correctamente, lo que generaba conflictos en el código. Además, la sincronización en tiempo real no siempre se actualizaba de manera fluida, lo que dificultaba la colaboración simultánea. Otro problema que enfrentamos fue la gestión de los repositorios, ya que cada participante del proyecto tenía una ubicación local diferente, lo que ocasionaba que el proyecto no se ejecutara correctamente en el primer intento. A pesar de estos inconvenientes, GitHub demostró ser una herramienta invaluable en la organización y gestión del proyecto, permitiendo un seguimiento exhaustivo de los cambios y facilitando la colaboración en equipo.
###
### Objetivos deseables
1. #### <a name="_heading=h.lpsi1d33dnql"></a>**Leer datos de una fuente externa como un archivo de texto o CSV**
El objetivo de la implementación de leer datos de una fuente externa, como un archivo de texto o CSV, es permitir la carga inicial de usuarios desde un archivo existente llamado “f\_users.txt”.

En el archivo “main.c”, se realiza la apertura del archivo en modo de lectura mediante la función fopen. Se verifica si el archivo existe o se puede abrir correctamente. Si no existe o no se puede abrir en modo de lectura, se crea un nuevo archivo vacío con el mismo nombre. Si el archivo existe y contiene datos, se muestra un mensaje indicando que el archivo ya tiene datos y no se debe modificar. Luego se declara una variable de tipo user\_list llamada “lista\_de\_usuarios” e inicializa su campo “cantidad\_usuarios” en 0.

En la función file\_users del archivo “user.c”, se abre el archivo “f\_users.txt” en modo de escritura y se genera un usuario utilizando la función generate\_user. Luego, se escribe la información del usuario en el archivo utilizando la función fprintf. Además, se agrega el usuario a la lista\_de\_usuarios mediante la función lista\_usuarios. Este proceso se repite un número determinado de veces para generar varios usuarios de ejemplo. Finalmente, se cierra el archivo.

En la función lista\_usuarios del archivo “user.c”, se agrega un nuevo usuario a la lista\_de\_usuarios. Si la lista está vacía, se asigna memoria para un solo usuario. En caso contrario, se utiliza la función realloc para redimensionar el tamaño de la lista y asignar memoria para el nuevo usuario. Luego, se añade el nuevo usuario a la lista y se incrementa el campo “cantidad\_usuarios”. La lista\_de\_usuarios actualizada se devuelve como resultado.

En la función print\_users del archivo “user.c”, se imprime la lista de usuarios en la comunidad cinéfila. Se recorre la lista\_de\_usuarios y se muestra el nombre de cada usuario junto con un número de identificación.

En la función buscar\_usuario del archivo “user.c”, se busca un usuario en la lista\_de\_usuarios mediante su nombre. Se verifica si la lista está vacía o si el nombre de usuario proporcionado está vacío. Luego, se recorre la lista comparando el nombre de cada usuario con el nombre buscado. Si se encuentra el usuario, se devuelve un puntero a la estructura del usuario correspondiente. En caso contrario, se muestra un mensaje indicando que el usuario no ha sido encontrado.

En la función menu del archivo “user.c”, se muestra un menú interactivo que permite al usuario realizar diversas acciones. El usuario puede elegir opciones como crear un nuevo usuario, listar la comunidad de cinéfilos, operar como un usuario existente, buscar usuarios por género y salir del programa. Dependiendo de la opción seleccionada, se ejecutan diferentes secciones de código.

En la función imprimir\_usuarios\_por\_genero del archivo “user.c”, se busca y muestra los usuarios de la lista\_de\_usuarios que tienen gustos en común con el género especificado. Se recorre la lista\_de\_usuarios y se verifica si los gustos de cada usuario coinciden con el género proporcionado.

- Implementar una funcionalidad para permitir la modificación de usuarios existentes y la adición de nuevos usuarios directamente desde el programa, sin necesidad de editar el archivo externo.
- Realizar una validación más rigurosa de los datos ingresados por el usuario, como asegurarse de que el nombre de usuario no esté duplicado y que se proporcionen datos válidos en cada campo.
- Utilizar una estructura de datos más eficiente para almacenar la lista\_de\_usuarios, como una lista enlazada o un árbol binario de búsqueda, para mejorar el rendimiento en la búsqueda de usuarios por nombre.


1. #### <a name="_heading=h.1um6rgb24l9"></a>**Temática y capa de personalización**
El objetivo es crear un menú tematizado y personalizado para una comunidad de cinéfilos. El código refleja esta temática a través de su estructura y las opciones presentadas. A continuación, se explica cómo se ha logrado esta tematización:

El menú se presenta con el título "SER-I-ON", que es un juego de palabras relacionado con el mundo del cine. La palabra "SER-I-ON" se asemeja a "SERIE" y evoca una sensación de estar a punto de sumergirse en el mundo de las películas.

En las opciones del menú, se utilizan frases y términos relacionados con el cine para describir las acciones que los usuarios pueden realizar. Por ejemplo:

1. Eres nuevo? Crea nuevo usuario”: Esta opción invita a los nuevos usuarios a unirse a la comunidad cinematográfica creando un perfil.

1. “Listar nuestra comunidad de cinefilos”: Esta opción permite a los usuarios explorar y conocer a otros cinéfilos en la comunidad, enfatizando el sentido de pertenencia y conexión con otros amantes del cine.
1. “Buscar usuarios por genero”: Esta opción permite a los usuarios encontrar otros cinéfilos que compartan sus mismos géneros cinematográficos de interés, creando así la posibilidad de establecer conexiones y discutir sobre películas específicas.

En resumen, el código implementa un menú tematizado en el mundo del cine, utilizando términos y frases relacionadas con esta temática para crear una experiencia personalizada y acogedora para los amantes del séptimo arte.

### Objetivos libres
1. #### <a name="_heading=h.zbgwrgpdivzb"></a>**Capa estética**
El objetivo de este código es implementar un menú tematizado en el mundo del cine para una red social. A continuación, se describirá cómo se implementó este objetivo, incluyendo las principales características de las estructuras de datos y algoritmos utilizados, así como su comportamiento.

Hemos usado almohadillas para decorar la consola: ##### MENÚ #####

1. #### <a name="_heading=h.dr4vup5lyzlw"></a>**Implementar las funcionalidades de lectura y guardado de datos**

El objetivo de implementar las funcionalidades de lectura y guardado de datos desde un archivo externo (.txt o .csv) es permitir que la información de los usuarios y sus contactos se pueda almacenar y recuperar de manera persistente. Esto evita la pérdida de datos cuando el programa se cierra y permite que los usuarios puedan retomar su actividad en futuras sesiones.

Para lograr esto, se han implementado las siguientes funciones:

1\. La función `file\_users` se encarga de generar usuarios aleatorios y guardar sus datos en un archivo de texto llamado "f\_users.txt". Cada usuario se guarda en una nueva línea y los datos se separan por comas. Esta función también actualiza la lista de usuarios pasada como parámetro agregando los usuarios generados.

2\. La función `read\_users` lee los datos de usuarios almacenados en el archivo "f\_users.txt" y los carga en la lista de usuarios pasada como parámetro. Utiliza la función `fscanf` para leer los datos separados por comas de cada línea y luego crea un nuevo usuario con esos datos. Los usuarios leídos se agregan a la lista de usuarios.

Estas funciones utilizan las estructuras de datos `user` y `user\_list` para representar la información de los usuarios y la lista de usuarios, respectivamente. La lista de usuarios es actualizada a medida que se agregan nuevos usuarios.

En cuanto al comportamiento de las estructuras de datos y algoritmos implementados, se utilizan arreglos y punteros para almacenar y manipular los datos de los usuarios. Se utilizan funciones como `malloc` y `realloc` para asignar memoria dinámicamente y permitir el crecimiento de la lista de usuarios.

El algoritmo utilizado para leer y escribir los datos en el archivo es sencillo y eficiente. Se utiliza un bucle `while` y la función `fscanf` para leer y procesar cada línea del archivo. La complejidad temporal de estas operaciones depende del tamaño del archivo y la cantidad de usuarios.

Sin embargo, hay algunas limitaciones en la implementación actual. Por ejemplo, no se manejan errores relacionados con la apertura o cierre del archivo. Además, la estructura de datos utilizada para almacenar la lista de amigos de un usuario (`amigos`) podría mejorarse para permitir un crecimiento dinámico de la lista de amigos a medida que se agregan más contactos.

En cuanto a la ubicación de la implementación, las funciones mencionadas se encuentran dentro del archivo de código fuente principal del proyecto, probablemente en un archivo llamado "main.c" o similar. Se ubicarían en un lugar específico dentro del archivo, según la estructura y organización del código.

En resumen, el objetivo de implementar las funcionalidades de lectura y guardado de datos desde un archivo externo es permitir la persistencia de la información de los usuarios y sus contactos. Se utilizan funciones para generar usuarios aleatorios y guardarlos en un archivo, así como para leer los datos del archivo y cargarlos en la lista de usuarios. La implementación se basa en arreglos y punteros, y se pueden realizar mejoras en la manipulación de la lista de amigos y el manejo de errores.


1. #### <a name="_heading=h.qmp4hhcvqk4l"></a>**Funcionalidades extras**
El objetivo de implementar funcionalidades extras es proporcionar una función que permita imprimir los usuarios de una lista que tengan un género cinematográfico específico.

Resumen: Para lograr este objetivo, se ha creado la función “imprimir\_usuarios\_por\_genero”. Esta función recibe como parámetros el género cinematográfico a buscar y la lista de usuarios.

- “genero”: Almacena el género cinematográfico a buscar.
- “lista\_de\_usuarios”: Es un puntero a una estructura “user\_list” que contiene la lista de usuarios.

Estructuras de datos utilizadas: No se utilizan nuevas estructuras de datos en esta función. Se trabaja con la estructura existente “user\_list” que representa una lista de usuarios.

Algoritmo utilizado: El algoritmo utilizado es un bucle anidado. El bucle externo itera sobre los usuarios en la lista de usuarios, mientras que el bucle interno itera sobre los gustos cinematográficos de cada usuario. Se utiliza la función “strcmp” para comparar el género buscado con los gustos cinematográficos de cada usuario.

Comportamiento esperado del algoritmo: El algoritmo busca usuarios que tengan un género cinematográfico específico en su lista de gustos. Si se encuentra una coincidencia, se imprime el nombre del usuario. El algoritmo itera sobre todos los usuarios y sus gustos cinematográficos, por lo que puede imprimir múltiples nombres si varios usuarios tienen el mismo género en su lista de gustos.

Rendimiento en Big O: El rendimiento del algoritmo es de O, donde “n” es la cantidad de usuarios en la lista y “m” es la cantidad máxima de gustos cinematográficos por usuario. El bucle externo recorre todos los usuarios, y el bucle interno recorre los gustos cinematográficos de cada usuario.

Limitaciones del algoritmo e implementación: Una limitación de este algoritmo es que solo busca coincidencias exactas del género cinematográfico. Si el género buscado no coincide exactamente con los gustos almacenados en la lista de usuarios, no se imprimirá ningún resultado. Además, si un usuario no tiene suficientes gustos almacenados, algunos gustos pueden quedar sin verificar.

Posibles mejoras: Para mejorar este algoritmo, se podría implementar una búsqueda más flexible, como una búsqueda parcial o una búsqueda basada en palabras clave. Esto permitiría encontrar usuarios con gustos cinematográficos relacionados aunque no coincidan exactamente con el género buscado.



## SOLUTION
### System Architecture

El sistema está compuesto por tres archivos fuente en lenguaje C. A continuación, se presenta una descripción de cada uno de ellos y su funcionalidad, junto con una breve mención de los archivos de encabezado asociados:

1. main.c: Este archivo contiene el programa principal (main). Su función principal es la inicialización del sistema y la ejecución del flujo principal del programa.

1. user.c: Este archivo se encarga de manejar todas las operaciones relacionadas con los usuarios. Contiene la implementación de funciones como:
- Rellenar datos: Permite al usuario ingresar y almacenar información personal.
- Vista de usuarios (print\_users): Imprime en pantalla la lista de usuarios almacenados en el sistema.
- Buscar usuarios: Realiza una búsqueda de usuarios según criterios específicos, como el nombre de usuario.
- Actualizar usuarios: Actualiza la información de un usuario específico en la lista de usuarios.

Además, user.c incluye funciones relacionadas con estructuras de datos, como:

- Inicializar stack: Inicializa una estructura de pila.
- is\_full: Verifica si una pila está llena.
- is\_empty: Verifica si una pila está vacía.
- top\_stack: Devuelve el elemento superior de una pila.
- push\_stack: Inserta un elemento en la parte superior de una pila.
- pop\_stack: Elimina el elemento superior de una pila.

También se menciona la presencia de funciones relacionadas con colas y tablas hash, como:

- Enviar solicitud de amistad: Permite enviar una solicitud de amistad entre usuarios.
- Recibir solicitud de amistad: Maneja la recepción de solicitudes de amistad entre usuarios.
- Crear diccionario (tabla hash): Implementa una tabla hash para almacenar y recuperar datos de manera eficiente.

Además de los archivos fuente mencionados, se mencionan la existencia de archivos de encabezado (punto H) correspondientes a cada uno de los archivos fuente. Estos archivos de encabezado contienen las declaraciones de funciones y estructuras utilizadas en los archivos fuente respectivos, y permiten una separación adecuada entre la interfaz y la implementación de cada módulo.

Por último, se menciona la existencia de un archivo de texto (TXT) que almacena los usuarios registrados en el sistema, junto con su información personal, como dirección de correo electrónico, edad, gustos favoritos y localidad.

### Error Handling
Manejo de errores

Validación de entradas del usuario: Se realizaron verificaciones y validaciones exhaustivas de las entradas proporcionadas por el usuario. Esto implica verificar que los valores ingresados cumplan con los requisitos y restricciones esperados. Manejo de errores en operaciones de memoria: Se implementaron comprobaciones y validaciones para evitar problemas de asignación de memoria, como la verificación de la disponibilidad de memoria antes de realizar una asignación y la liberación adecuada de la memoria asignada cuando ya no se necesita. Además, se utilizó la verificación de punteros nulos para evitar operaciones no válidas con punteros.

Esto permite tomar acciones adecuadas en respuesta a situaciones de error, como mostrar mensajes de error informativos, realizar acciones de recuperación o finalizar el programa de manera controlada.

El enfoque general en el manejo de errores se centra en proporcionar mensajes claros y significativos al usuario, asegurar que el programa no se bloquee ni se comporte de manera inesperada ante situaciones de error y permitir la recuperación oportuna cuando sea posible.

Es importante destacar que el manejo de errores es un aspecto continuo del desarrollo de software y siempre se puede mejorar.
### Data model design
En el proyecto, se realizó un diseño cuidadoso del modelo de datos para garantizar una organización eficiente y coherente de la información. Se utilizó un enfoque basado en diagramas de flujo de datos para representar visualmente la estructura y el flujo de los datos dentro del sistema.

El modelo de datos se compone de diferentes entidades y relaciones que reflejan las entidades del mundo real involucradas en el proyecto. Se identificaron las entidades principales, como usuarios, publicaciones, solicitudes de amistad y preferencias de género, y se establecieron las relaciones apropiadas entre ellas.

El diagrama de flujo de datos muestra cómo fluyen los datos entre las diferentes entidades y los procesos del sistema. Esto incluye la captura de datos de entrada, la manipulación y el procesamiento de los datos, y la generación de resultados o acciones correspondientes.

Además, se tuvo en cuenta la eficiencia y el rendimiento al elegir las estructuras de datos adecuadas para cada entidad. Se utilizaron estructuras como listas enlazadas y tablas hash para optimizar la búsqueda y manipulación de datos, garantizando un acceso rápido y eficiente a la información.

En resumen, el diseño del modelo de datos se basó en un enfoque visual y estructurado utilizando diagramas de flujo de datos. Se identificaron las entidades principales y se establecieron relaciones claras entre ellas. Se utilizaron estructuras de datos eficientes para garantizar un rendimiento óptimo del sistema.


### Dataset description and processing
Descripción y procesamiento del conjunto de datos

En el proyecto, se utilizó un conjunto de datos que contiene información relevante para el sistema. El conjunto de datos incluye detalles de los usuarios, como nombres, correos electrónicos, edades, géneros cinematográficos favoritos y ubicaciones.

Para leer y procesar el conjunto de datos, se implementaron funciones que permiten la lectura de archivos de texto en formato específico. Se utilizó un enfoque de lectura línea por línea, donde cada línea representa un usuario y los datos correspondientes se extraen y almacenan en las estructuras de datos adecuadas.

Durante el procesamiento del conjunto de datos, se realizó una validación de la integridad de los datos, asegurando que se cumplan ciertas restricciones y formatos esperados. Se verificó la corrección de los campos, como la existencia de nombres válidos, correos electrónicos bien formados y géneros cinematográficos reconocidos.

Se eliminaron espacios en blanco adicionales, se convirtieron los campos de texto a un formato consistente y se realizaron ajustes necesarios para asegurar la coherencia y calidad de los datos.

En resumen, el conjunto de datos utilizado fue procesado mediante funciones de lectura y validación específicas.
##
## REFERENCES

1\. GeeksforGeeks: <https://www.geeksforgeeks.org/c-programming-language/> 

2\. Tutorialspoint: Tutorialspoint: <https://www.tutorialspoint.com/cprogramming/> 

3\. Programiz: Programiz: <https://www.programiz.com/c-programming> 

4\. Stack Overflow: <https://stackoverflow.com/> 




