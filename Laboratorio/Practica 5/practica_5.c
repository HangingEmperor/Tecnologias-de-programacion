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

    dibujar[0].tipoFigura = TRIANGULO_TYPE;
    dibujar[0].dibujo.circulo.p1.x = 19;
    
    printf("El punto dado es: %i", dibujar[0].dibujo.circulo.p1.x);

    return 0;
}