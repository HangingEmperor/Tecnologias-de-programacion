/*
imprimir notacion arreglo e imprimir informacion notacion puntero
matricula, nombre, promedio, correo
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Alumno {
    int matricula;
    char nombre[20];
    float promedio;
    char correo[20];
};

int main() {
    struct Alumno alumno[10];
    struct Alumno *ptr;
    int x;
    ptr = &alumno;

    for (int i = 0; i < 10; i++) {
        printf("Dame matricula: ");
        scanf("%i", &alumno[i].matricula);

        while (getchar() != '\n') {
        };
        printf("Dame nombre: ");
        scanf("%c", alumno[i].nombre);

        while (getchar() != '\n') {
        };
        printf("Dame promedio: ");
        scanf("%f", &alumno[i].promedio);

        while (getchar() != '\n') {
        };
        printf("Dame correo: ");
        scanf("%c", alumno[i].correo);
    }

    for (int i = 0; i < 10; i++) {
        printf("Matricula: %i", alumno[i].matricula);
        printf("Nombre: %c", alumno[i].nombre);
        printf("Promedio: %f", alumno[i].promedio);
        printf("Correo: %c", alumno[i].correo);
    }

    for (ptr = alumno; ptr < (alumno + 5); ptr++) {
        printf("Matricula: %i", ptr->matricula);
        printf("Nombre: %c", ptr->nombre);
        printf("Promedio: %f", ptr->promedio);
        printf("Correo: %c", ptr->correo);
    }

    //strcpy(ptr->nombre, "hola");
    return 0;
}