#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea {
    int tareaID; //Numerado en ciclo iterativo
    char *descripcion; //
    int duracion; // entre 10 y 100
};

typedef struct Tarea tarea;

struct Nodo{
    Tarea T;
    Nodo *siguiente;
};

typedef struct Nodo nodo;

nodo *crearListaVacia();
nodo *crearNodo(int tareaID, char *cadena, int duracion);
nodo *insertarNodo(nodo **lista, nodo *nodo);
nodo *borrarNodo(nodo **lista);
void cargarTareasCompletadas(nodo **lista1, nodo **lista2);
void mostrarTareas(nodo **lista1, nodo **lista2);

tarea BusquedaPorID(tarea **X, int Y, int ID);


#define MAX 200

int main() {

    srand(time(0));
    
    int cantTareas, ID;
    
    nodo *listaDeTareas = crearListaVacia();
    nodo *tareasCompletadas = crearListaVacia();
    
    nodo *nod;
    
    int completar;
    char cad[MAX];


    printf("Ingrese la cantidad de tareas a realizar: ");
    scanf("%d", &cantTareas);
    fflush(stdout);
    getchar();


    for (int i = 0; i < cantTareas; i++) {
        printf("\nIngrese la descripción de la tarea %d: ", i + 1);
        fgets(cad, MAX, stdin);
        fflush(stdout);
        nod = crearNodo(i + 1, cad, rand() % 91 + 10);
        insertarNodo(&listaDeTareas, nod);
    }

    cargarTareasCompletadas(&listaDeTareas, &tareasCompletadas);
    mostrarTareas(&listaDeTareas, &tareasCompletadas);


    getchar();
    return 0;
}

nodo *crearListaVacia() {
    return NULL;
}

nodo *crearNodo(int tareaID, char *cadena, int duracion) {
    nodo *NNodo = (nodo *)malloc(sizeof(nodo));
    NNodo->T.tareaID = tareaID;
    NNodo->T.descripcion = (char *)malloc(sizeof(char) * strlen(cadena));
    strcpy(NNodo->T.descripcion, cadena);
    NNodo->T.duracion = duracion;
    NNodo->siguiente = NULL;

    return NNodo;
}

nodo *insertarNodo(nodo **lista, nodo *nodo) {
    
    nodo->siguiente = *lista;
    *lista = nodo;

    return *lista;
}

void cargarTareasCompletadas(nodo **lista1, nodo **lista2) {
   int completar;
   nodo *aux = (nodo *)malloc(sizeof(nodo));
   
   printf("\n\n----------Lista de Tareas----------");
   while(*lista1){
    printf("\n\nID de la tarea: %d", (*lista1)->T.tareaID);
    printf("\n\nDescripción de la tarea: %s", (*lista1)->T.descripcion);
    printf("\nDuración de la tarea: %d", (*lista1)->T.duracion);
    printf("\n\n¿Se completó la tarea? Ingrese 1 si se completó, o cualquier otro número entero si NO se completó: ");
    scanf("%d", &completar);
    fflush(stdout);
    getchar();

    if(completar == 1) {
        aux = *lista1;
        *lista1 = borrarNodo(lista1);
        *lista2 = insertarNodo(lista2, aux);
    } else {
        *lista1 = (*lista1)->siguiente;
    }
    }
}

nodo *borrarNodo(nodo **lista) {
    nodo *aux = *lista;
    *lista = (*lista)->siguiente;
    free(aux);

    return *lista;
}

void mostrarTareas(nodo **lista1, nodo **lista2) {
    printf("\n\n----------Tareas pendientes----------");
    
    while(*lista1){
        printf("\n\nID de la tarea: %d", (*lista1)->T.tareaID);
        printf("\nDescripción de la tarea: %s", (*lista1)->T.descripcion);
        printf("\nDuración de la tarea: %d", (*lista1)->T.duracion);
        
        *lista1 = (*lista1)->siguiente;
    }   
    printf("\n\n----------Tareas completadas----------");

    while(*lista2){
        printf("\n\nID de la tarea: %d", (*lista2)->T.tareaID);
        printf("\nDescripción de la tarea: %s", (*lista2)->T.descripcion);
        printf("\nDuración de la tarea: %d", (*lista2)->T.duracion);

        *lista2 = (*lista2)->siguiente;
    }
}

