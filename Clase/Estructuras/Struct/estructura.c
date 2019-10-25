/*
Hacer uso de struct, apuntador flecha
struct cd* disco1
scanf("%d", &disco1->ID)
*/
#include <stdio.h>

struct fecha {
    int dia;
    int mes;
    int anio;
};

struct cd {
    int ID;
    char artista[50];
    char disco[50];
    int numCancion;
    float tiempo;
    float precio;
    struct fecha lanzamiento;
    struct fecha venta;
};

void imprimir(struct cd discos[5]);

void leer(struct cd discos[5], int size);

int main() {
    int size = 0;
    struct cd discos[5];

    do {
        leer(discos, size);
        size++;
    } while (size != 1);

    int i;
    printf("Agregados: \n");
    imprimir(discos);

    return 0;
}

void imprimir(struct cd discos[5]) {
    int i;
    for (i = 0; i < 1; i++) {
        printf(" ------------- \n");
        printf("ID (%i): %i \n", i, discos[i].ID);
        printf("Nombre (%i): %s\n", i, discos[i].artista);
        printf("Disco (%i): %s\n", i, discos[i].disco);
        printf("Numero de canciones (%i): %i\n", i, discos[i].numCancion);
        printf("Duracion (%i): %f\n", i, discos[i].tiempo);
        printf("Precio del disco (%i): %f\n", i, discos[i].precio);
        printf("Fecha de lanzamiento, dia (%i): %i\n", i, discos[i].lanzamiento.dia);
        printf("Fecha de lanzamiento, mes (%i): %i\n", i, discos[i].lanzamiento.mes);
        printf("Fecha de lanzamiento, anio (%i): %i\n", i, discos[i].lanzamiento.anio);
        printf("Fecha de venta, dia (%i): %i\n", i, discos[i].venta.dia);
        printf("Fecha de venta, mes (%i): %i\n", i, discos[i].venta.mes);
        printf("Fecha de venta, anio (%i): %i\n", i, discos[i].venta.anio);
        printf(" ------------- \n");
    }
}

void leer(struct cd discos[5], int size) {
    printf("ID (%i): ", size + 1);
    scanf("%i", &discos[size].ID);
    while (getchar() != '\n');

    printf("Nombre (%i): ", size + 1);
    scanf("%[^\n]", discos[size].artista);
    while (getchar() != '\n');

    printf("Disco (%i): ", size + 1);
    scanf("%[^\n]", discos[size].disco);
    while (getchar() != '\n');

    printf("Numero de canciones (%i): ", size + 1);
    scanf("%i", &discos[size].numCancion);
    while (getchar() != '\n');

    printf("Duracion (%i): ", size + 1);
    scanf("%f", &discos[size].tiempo);

    printf("Precio del disco (%i): ", size + 1);
    scanf("%f", &discos[size].precio);

    printf("Fecha de lanzamiento, dia: ");
    scanf("%i", &discos[size].lanzamiento.dia);

    printf("Fecha de lanzamiento, mes: ");
    scanf("%i", &discos[size].lanzamiento.mes);

    printf("Fecha de lanzamiento, anio: ");
    scanf("%i", &discos[size].lanzamiento.anio);

    printf("Fecha de venta, dia: ");
    scanf("%i", &discos[size].venta.dia);

    printf("Fecha de venta, mes: ");
    scanf("%i", &discos[size].venta.mes);

    printf("Fecha de venta, anio: ");
    scanf("%i", &discos[size].venta.anio);
}














