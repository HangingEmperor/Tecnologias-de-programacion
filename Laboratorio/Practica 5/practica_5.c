#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

                int base;
                int altura;
                float area;

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

                        if (dibujar[size].dibujo.triangulo.p1.x >= 0) {
                            base = dibujar[size].dibujo.triangulo.p3.x - dibujar[size].dibujo.triangulo.p1.x;
                        } else {
                            base = abs(dibujar[size].dibujo.triangulo.p1.x) + dibujar[size].dibujo.triangulo.p3.x;
                        }
                        if (dibujar[size].dibujo.triangulo.p1.y >= 0) {
                            altura = dibujar[size].dibujo.triangulo.p2.y - dibujar[size].dibujo.triangulo.p1.y;
                        } else {
                            altura = abs(dibujar[size].dibujo.triangulo.p1.y) + dibujar[size].dibujo.triangulo.p3.y;
                        }
                        area = (base * altura) / 2;
                        dibujar[size].area = area;
                        break;
                    case 2:
                        dibujar[size].seleccionado = 0;
                        dibujar[size].tipoFigura = CUADRADO_TYPE;
                        printf("Coordenada P1 X: ");
                        scanf("%i", dibujar[size].dibujo.cuadrado.p1.x);
                        printf("Coordenada P1 Y: ");
                        scanf("%i", dibujar[size].dibujo.cuadrado.p1.y);
                        printf("Coordenada P2 X: ");
                        scanf("%i", dibujar[size].dibujo.cuadrado.p2.x);
                        printf("Coordenada P2 Y: ");
                        scanf("%i", dibujar[size].dibujo.cuadrado.p2.y);

                        if (dibujar[size].dibujo.cuadrado.p1.x >= 0) {
                            base = dibujar[size].dibujo.cuadrado.p2.x - dibujar[size].dibujo.cuadrado.p1.x;
                        } else {
                            base = abs(dibujar[size].dibujo.cuadrado.p1.x) + dibujar[size].dibujo.cuadrado.p2.x;
                        }
                        if (dibujar[size].dibujo.cuadrado.p1.y >= 0) {
                            altura = abs(dibujar[size].dibujo.cuadrado.p2.y) + dibujar[size].dibujo.cuadrado.p1.y;
                        } else {
                            altura = dibujar[size].dibujo.cuadrado.p1.y + abs(dibujar[size].dibujo.cuadrado.p2.y);
                        }
                        area = base * altura;
                        dibujar[size].area = area;
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
                            strcpy(dibujar[size].color, "Rojo");
                            break;
                        case 2:
                            strcpy(dibujar[size].color, "Azul");
                            break;
                        case 3:
                            strcpy(dibujar[size].color, "Amarillo");
                            break;
                        case 4:
                            strcpy(dibujar[size].color, "Verde");
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
                /*
                Permitirá al usuario mostrar una lista de todos los elementos de la
                colección mostrando para cada elemento el tipo de Figura,Coordenadas
                y área como se muestra a continuación*/
                for (int i = 0; i < size; i++) {
                    if (dibujar[size].tipoFigura == TRIANGULO_TYPE) {
                        printf("FIGURA: Triangulo. \n");
                        printf("Coordenadas: X1 = %i, Y1 = %i; X2 = %i, Y2 = %i; X3 = %i, Y3 = %i\n",
                               dibujar[size].dibujo.triangulo.p1.x, dibujar[size].dibujo.triangulo.p1.y,
                               dibujar[size].dibujo.triangulo.p2.x, dibujar[size].dibujo.triangulo.p2.y,
                               dibujar[size].dibujo.triangulo.p3.x, dibujar[size].dibujo.triangulo.p3.y);
                        printf("Area: %f \n", dibujar[size].area);
                        printf("Color: %s \n", dibujar[size].color);
                        printf("Seleccionado: %i \n", dibujar[size].seleccionado);
                    }
                    if (dibujar[size].tipoFigura == CUADRADO_TYPE) {
                        printf("FIGURA: Cuadrado. \n");
                        printf("Coordenadas: X1 = %i, Y1 = %i; X2 = %i, Y2 = %i\n",
                               dibujar[size].dibujo.cuadrado.p1.x, dibujar[size].dibujo.cuadrado.p1.y,
                               dibujar[size].dibujo.cuadrado.p2.x, dibujar[size].dibujo.cuadrado.p2.y);
                        printf("Area: %f \n", dibujar[size].area);
                        printf("Color: %s \n", dibujar[size].color);
                        printf("Seleccionado: %i \n", dibujar[size].seleccionado);
                    }
                    if (dibujar[size].tipoFigura == CIRCULO_TYPE) {
                    }
                }

                break;
            default:
                printf("Opcion invalida \n");
                break;
        }
    } while (op != 6);

    return 0;
}