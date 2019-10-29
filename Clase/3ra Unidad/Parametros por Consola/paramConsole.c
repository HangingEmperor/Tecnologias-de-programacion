#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Cantidad de parametros: %i \n", argc);
    int i;
    for (i = 0; i < argc; i++) {
        printf("Parametros: %s\n", argv[i]);
    }
    return 0;
}
