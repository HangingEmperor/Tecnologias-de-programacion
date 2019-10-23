#include <stdio.h>

void altas(int *alumnos);

void mostrar(int *alumnos);

void altasChar(char alumnado[10][10]);

void mostrarChar(char alumnado[10][10]);

int main() {
    int alumnos[5];
    char alumnado[10][10];

    altas(alumnos);
    mostrar(alumnos);
    altasChar(alumnado);
    mostrarChar(alumnado);
    return 0;
}

void altas(int *alumnos) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("Dame primer numero: ");
        scanf("%i", &alumnos[i]);
    }
}

void mostrar(int *alumnos) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("Numero %i: %i \n", i, alumnos[i]);
    }
}

void altasChar(char alumnado[10][10]) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("Dame primer nombre: ");
        scanf("%s", alumnado[i]);
    }
}

void mostrarChar(char alumnado[10][10]) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("Nombre %i: %s \n", i, alumnado[i]);
    }
}
