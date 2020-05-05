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

void cargarTareas(tarea **X, int Y);
void cargarTareasCompletadas(tarea **X, int Y, tarea **Z);
void mostrarTodo(tarea **X, int Y, tarea **Z);
tarea buscarTarea(tarea **X, int Y, int ID);


#define MAX 200

int main() {

    srand(time(0));
    
    int cantTareas;
    tarea **tareasPendientes;
    tarea **tareasRealizadas;
    int ID;


    printf("Ingrese la cantidad de tareas a realizar: ");
    scanf("%d", &cantTareas);
    fflush(stdin);

    tareasPendientes = (tarea **) malloc(sizeof(tarea) * cantTareas);
    tareasRealizadas = (tarea **) malloc(sizeof(tarea) * cantTareas);

    cargarTareas(tareasPendientes, cantTareas);
    
    cargarTareasCompletadas(tareasPendientes, cantTareas, tareasRealizadas);
    
    mostrarTodo(tareasPendientes, cantTareas, tareasRealizadas);

    printf("\n\nIngrese la ID de la tarea a buscar: ");
    scanf("%d", &ID);
    tarea buscar = buscarTarea(tareasPendientes, cantTareas, ID);
    printf("\n\nID de tarea: %d\n", buscar.tareaID);
    printf("Descripción: %s", buscar.descripcion);
    printf("\nDuración: %d", buscar.duracion);




    getchar();
    return 0;
}

void cargarTareas(tarea **X, int Y) {

    for (int i = 0; i < Y; i++) {
        X[i] = (tarea *) malloc(sizeof(tarea));
        X[i]->tareaID = i + 1;
        X[i]->descripcion = (char *) malloc(sizeof(char) * MAX);
        printf("Ingrese la descripción de la tarea %d: ", i + 1);
        scanf("%s", X[i]->descripcion);
        fflush(stdin);
        X[i]->duracion = rand() % 91 + 10;
    }
}

void cargarTareasCompletadas(tarea **X, int Y, tarea **Z) { //X es el vector que contiene las tareas pendientes, Z el vector que contiene las tareas completadas
    printf("------- Listado de tareas ---------");
    int aux;
    int auxZ = 0;
    for (int i = 0; i < Y; i++) {
        printf("\n\nID de tarea: %d\n", X[i]->tareaID);
        printf("Descripción: %s\n", X[i]->descripcion);
        printf("Duración: %d", X[i]->duracion);
       
        printf("\n\n¿Se completó la tarea? Ingrese 1 si se ha completado, y cualquier otro número entero si no se ha completado: ");
        scanf("%d", &aux);
        fflush(stdin);

        if (aux == 1) { //Si la tarea fue completada, cargo el vector Z con los datos de la tarea completada
            Z[auxZ] = (tarea *) malloc(sizeof(tarea));
            Z[auxZ]->tareaID = X[i]->tareaID;
            Z[auxZ]->descripcion = (char *) malloc(sizeof(char) * MAX);
            strcpy(Z[auxZ]->descripcion, X[i]->descripcion);
            Z[auxZ]->duracion = X[i]->duracion;
            X[i] = NULL; //Borro la tarea completada de la lista de tareas pendientes
            auxZ = auxZ + 1;
        }
    }
}

void mostrarTodo(tarea **X, int Y, tarea **Z) {
    printf("\n\n--------------Tareas pendientes--------------");

    for (int i = 0; i < Y; i++) {
        if (X[i] != NULL) {
            printf("\n\nID de tarea: %d\n", X[i]->tareaID);
            printf("Descripción: %s\n", X[i]->descripcion);
            printf("Duración: %d", X[i]->duracion);
        }
    }

    printf("\n\n--------------Tareas completadas--------------");

    for (int i = 0; i < Y; i++) {
        if (Z[i] != NULL) {
            printf("\n\nID de tarea: %d\n", Z[i]->tareaID);
            printf("Descripción: %s", Z[i]->descripcion);
            printf("\nDuración: %d", Z[i]->duracion);
        }
    }
}

tarea buscarTarea(tarea **X, int Y, int ID) {

    tarea *aux = (tarea *) malloc(sizeof(tarea));

    for (int i = 0; i < Y; i++) {
        if (X[i]->tareaID == ID) {
            return *(X[i]);
        }
    }
    return *aux;
}



