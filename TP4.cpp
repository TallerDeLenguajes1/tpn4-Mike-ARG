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

void cargarTareas(tarea *X, int Y);
void mostrarTareas(tarea *X, int Y);


#define MAX 200

int main() {

    srand(time(0));
    int cantTareas;
    tarea *tareasPendientes;
    tarea *tareasRealizadas;


    printf("Ingrese la cantidad de tareas a realizar: ");
    scanf("%d", &cantTareas);
    fflush(stdin);

    tareasPendientes = (tarea *) malloc(sizeof(tarea) * cantTareas);
    tareasRealizadas = (tarea *) malloc(sizeof(tarea) * cantTareas);

    cargarTareas(tareasPendientes, cantTareas);
    mostrarTareas(tareasPendientes, cantTareas);


    getchar();
    return 0;
}

void cargarTareas(tarea *X, int Y) {
    
    for (int i = 0; i < Y; i++) {
        X[i].tareaID = i + 1;
        X[i].descripcion = (char *) malloc(sizeof(char) * MAX);
        printf("Ingrese la descripción de la tarea: ");
        gets(X[i].descripcion);
        fflush(stdin);
        X[i].duracion = rand() % 91 + 10;
    }
}

void mostrarTareas(tarea *X, int Y) {
    printf("------- Listado de tareas ---------");
    for (int i = 0; i < Y; i++) {
        printf("\n\nID de tarea: %d\n", X[i].tareaID);
        printf("Descripción: %s\n", X[i].descripcion);
        printf("Duración: %d", X[i].duracion);
    }
}