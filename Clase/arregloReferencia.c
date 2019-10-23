#include<stdio.h>

int llenar(int y[100],

*
int tamano
);

void imprimir(int y[100], int tamano);

void ordenar(int y[100], int tamano);

int main() {
    int arr[100];
    int tamano = 0;

    printf("Llenar \n\n");
    tamano = llenar(arr, tamano);
    printf("\nImprimir \n\n");
    imprimir(arr, tamano);
    printf("\nSe ordena la lista \n");
    ordenar(arr, tamano);
    printf("\nImprimir \n\n");
    imprimir(arr, tamano);
    return 0;
}

int llenar(int y[100], int tamano) {
    int x = -1, espacio = 0, aux;
    tamano = 0;
    do {
        x++;
        printf("Dame un numero de la posicion %i: ", x);
        scanf("%i", &y[x]);
        tamano++;
    } while (y[x] > 0 && tamano < 100);
    return tamano;
}

void imprimir(int y[100], int tamano) {
    int x;
    for (x = 0; x < tamano; x++) {
        printf("Posicion %i: %i\n", x, y[x]);
    }
}

void ordenar(int y[100], int tamano) {
    int i, x, aux = 0;
    for (i = 0; i < tamano; i++) {
        for (x = i + 1; x < tamano; x++) {
            if (y[i] > y[x]) {
                aux = y[i];
                y[i] = y[x];
                y[x] = aux;
            }
        }
    }
}









