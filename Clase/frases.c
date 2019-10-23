#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union frases {
    char mensajes[50];
    char ayudas[50];
    char lineas[50];
};

struct completa {
    char mensajes[50];
    char ayudas[50];
    char lineas[50];
};

int main() {
    system("clear");
    union frases fras;
    struct completa frasc;

    strcpy(fras.mensajes, "primer mensaje");
    strcpy(fras.ayudas, "una ayuda");

    printf("\n Frases en Union: ");
    printf("\n 1.- %s", fras.mensajes);
    printf("\n 2.- %s", fras.ayudas);
    printf("\n Tamano de union: %ld", sizeof(union frases));
    printf("\n Tamano de variable union: %ld", sizeof(fras));

    strcpy(frasc.mensajes, "primer mensaje");
    strcpy(frasc.ayudas, "una ayuda");

    printf("\n\n Frases en estructura: ");
    printf("\n 1.- %s", frasc.mensajes);
    printf("\n 2.- %s", frasc.ayudas);
    printf("\n Tamano de estructura: %ld", sizeof(struct completa));
    printf("\n Tamano de variable: %ld \n\n", sizeof(frasc));

    return 0;
}
