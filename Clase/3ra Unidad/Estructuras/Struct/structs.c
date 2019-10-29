/*
Hacer uso de struct, apuntador flecha
struct cd* disco1
scanf("%d", &disco1->ID)
*/
#include <stdio.h>

struct cd {
    int ID;
    char artista[50];
    char disco[50];
    int numCancion;
    float tiempo;
    float precio;
};

void imprimir(struct cd discos[5]);

void leer(struct cd discos[5], int size);

int main() {
    int size = 0;
    struct cd discos[5];

    do {
        leer(discos, size);
        size++;
    } while (size != 5);

    int i;
    printf("Agregados: \n");
    imprimir(discos);

    return 0;
}

void imprimir(struct cd discos[5]) {
    int i;
    for (i = 0; i < 5; i++) {
        printf(" ------------- \n");
        printf("ID (%i): %i \n", i, discos[i].ID);
        printf("Nombre (%i): %s\n", i, discos[i].artista);
        printf(" ------------- \n");
    }
}

void leer(struct cd discos[5], int size) {
    printf("ID (%i): ", size + 1);
    scanf("%i", &discos[size].ID);
    while (getchar() != '\n');

    printf("Nombre (%i): ", size + 1);
    scanf("%s", discos[size].artista);
    while (getchar() != '\n');
}
