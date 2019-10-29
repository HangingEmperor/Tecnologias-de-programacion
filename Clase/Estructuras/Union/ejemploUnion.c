#include <stdio.h>
#include <stdlib.h>

#define FLOAT_TYPE 1
#define CHAR_TYPE 2
#define INT_TYPE 3

union valor {
    float un_float;
    char un_char;
    int un_int;
};

struct tipo_dato {
    int tipo_en_union;
    union valor dato;
};

int main() {
    struct tipo_dato variable[10];
    int cantidad = 0, op;

    do {
        printf(" 1.- Ingresar valor entero \n");
        printf(" 2.- Ingresar valor flotante \n");
        printf(" 3.- Ingresar valor caracter \n");
        printf(" 4.- Ver valores enteros \n");
        printf(" 5.- Ver valores flotantes \n");
        printf(" 6.- Ver valores caracter \n");
        printf(" 7.- Salir\n");
        scanf("%i", &op);

        while (getchar() != '\n') {
        };
        switch (op) {
            case 1:
                printf("Ingresa un entero: ");
                variable[cantidad].tipo_en_union = INT_TYPE;
                scanf("%i", &variable[cantidad].dato.un_int);
                cantidad++;
                break;
            case 2:
                printf("Ingresa un flotante: ");
                variable[cantidad].tipo_en_union = FLOAT_TYPE;
                scanf("%f", &variable[cantidad].dato.un_float);
                cantidad++;
                break;
            case 3:
                printf("Ingresa un caracter: ");
                variable[cantidad].tipo_en_union = CHAR_TYPE;
                scanf("%c", variable[cantidad].dato.un_char);
                cantidad++;
                break;
            case 4:
                printf(" --- Enteros --- \n");
                for (int i = 0; i < cantidad; i++) {
                    if (variable[i].tipo_en_union == INT_TYPE) {
                        printf("Position %i: %i\n", i, variable[i].dato.un_int);
                    }
                }
                break;
            case 5:
                printf(" --- Flotantes --- \n");
                for (int i = 0; i < cantidad; i++) {
                    if (variable[i].tipo_en_union == FLOAT_TYPE) {
                        printf("Position %i: %f\n", i, variable[i].dato.un_float);
                    }
                }
                break;
            case 6:
                printf("--- Caracteres --- \n");
                for (int i = 0; i < cantidad; i++) {
                    if (variable[i].tipo_en_union == CHAR_TYPE) {
                        printf("Position %i: %c\n", i, variable[i].dato.un_char);
                    }
                }
                break;
            default:
                cantidad--;
                break;
        }
    } while (cantidad < 10 || op != 7);

    return 0;
}
