#include <stdio.h>

int main() {
    int x = 7;
    int *px = &x;

    printf("El valor de x es %d y su direccion es %p", x, &x);
    printf("El valor del puntero de x es %p y su direccion es %p", px, &px);

    return 0;
}