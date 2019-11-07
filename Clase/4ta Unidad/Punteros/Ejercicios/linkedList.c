#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo {
    char nombre[10];
    int edad;
    float saldo;
    struct nodo *siguiente;
};

int main() {
    char name[10];
    int age;
    float balance;
    struct nodo *nuevo, *nuevo2;

    printf("\nIntroduce el nombre: ");
    scanf("%s", name);
    printf("\nIntroduce la edad: ");
    scanf("%d", &age);
    printf("\nIntroduce el saldo: ");
    scanf("%f", &balance);

    nuevo = (struct nodo *) malloc(sizeof(struct nodo));
    nuevo->edad = age;
    nuevo->saldo = balance;
    strcpy(nuevo->nombre, name);

    printf("\nIntroduce el nombre 2: ");
    scanf("%s", name);
    printf("\nIntroduce la edad 2: ");
    scanf("%d", &age);
    printf("\nIntroduce el saldo 2: ");
    scanf("%f", &balance);

    nuevo2 = (struct nodo *) malloc(sizeof(struct nodo));
    nuevo2->edad = age;
    nuevo2->saldo = balance;
    strcpy(nuevo2->nombre, name);

    nuevo->siguiente = nuevo2;
    nuevo2->siguiente = NULL;

    while (nuevo != NULL) {
        printf("El valor almacenado en nombre es: %s", nuevo2->nombre);
        printf("El valor almacenado en edad es: %d", nuevo2->edad);
        printf("El valor almacenado en saldo es: %.2f", nuevo2->saldo);
        nuevo2 = nuevo2->siguiente;
    }

    free(nuevo);
    free(nuevo2);
    return 0;

    for (int i = 0; i < 10; i++) {
        /* code */
    }

}