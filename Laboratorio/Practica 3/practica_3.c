/* Lo que se mostrara en pantalla */
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <wchar.h>

//generarTablero(char tablero[][], int filas, int columna);

int main(int argc, char *argv[]) {
    printf("%s", argv);
    if (argc == 3) {
        if (1) {

        } else {
            printf("Se ingreso un numero de barcos inferior a 5 o superior a 10. \n");
            printf("Ingrese [nombre programa] [numero de barcos {MIN: 5 - MAX: 10}] [nombre]\n");
        }
    } else {
        printf("No se puede ingresar mas de 3 parametros. \n");
        printf("Ingrese [nombre programa] [numero de barcos {MIN: 5 - MAX: 10}] [nombre]\n");
    }
    return 0;
}