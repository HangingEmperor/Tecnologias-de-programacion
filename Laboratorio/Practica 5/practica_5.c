#include <stdio.h>

#define TRIANGULO_TYPE 1
#define CUADRADO_TYPE 2
#define CIRCULO_TYPE 3

struct punto {
    int x;
    int y;
};

struct triangulo {
    struct punto p1;
    struct punto p2;
    struct punto p3;
};

struct cuadrado {
    struct punto p1;
    struct punto p2;
};

struct circulo {
    struct punto p1;
};

union figuras {
    struct cuadrado cuadrado;
    struct triangulo triangulo;
    struct circulo circulo;
};

struct figura {
    int tipoFigura;
    float area;
    char color[20];
    union figuras dibujo;
    int seleccionado;
};

int main() {
    struct figura dibujar[100];
    int size = 0;
    int op;

    do {
        printf("1.- Agregar una figura geometrica a la lista\n");
        printf("2.- Seleccionar figura\n");
        printf("3.- Borrar figura del dibujo\n");
        printf("4.- Ordenar lista\n");
        printf("5.- Listar\n");
        printf("6.- Salir\n");
        scanf("%i", &op);

        switch (op) {
            case 1:
                printf("Seleccionar tipo de figura:\n");
                printf("1.- Triangulo\n");
                printf("2.- Cuadrado\n");
                printf("3.- Circulo\n");
                printf("4.- Salir\n");
                scanf("%i", &op);

                switch (op) {
                    case 1:
                        dibujar[size].seleccionado = 0;
                        dibujar[size].tipoFigura = TRIANGULO_TYPE;
                        printf("Coordenada P1 X: ");
                        scanf("%i", dibujar[size].dibujo.triangulo.p1.x);
                        printf("Coordenada P1 Y: ");
                        scanf("%i", dibujar[size].dibujo.triangulo.p1.y);
                        printf("Coordenada P2 X: ");
                        scanf("%i", dibujar[size].dibujo.triangulo.p2.x);
                        printf("Coordenada P2 Y: ");
                        scanf("%i", dibujar[size].dibujo.triangulo.p2.y);
                        printf("Coordenada P3 X: ");
                        scanf("%i", dibujar[size].dibujo.triangulo.p3.x);
                        printf("Coordenada P3 Y: ");
                        scanf("%i", dibujar[size].dibujo.triangulo.p3.y);
                        dibujar[size].area;

                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default:
                        break;
                }

                if (op > 0 && op < 4) {
                    printf("¿Que color desea en la figura?: ");
                    printf("1.- Rojo");
                    printf("2.- Azul");
                    printf("3.- Amarillo");
                    printf("4.- Verde");
                    scanf("%i", &op);
                    switch (op) {
                        case 1:

                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                    }
                }
                size++;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Opcion invalida \n");
                break;
        }
    } while (op != 6);

    return 0;
}