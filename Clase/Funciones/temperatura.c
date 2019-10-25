#include <stdio.h>

float lectura();

float calcularCelsius();

float calcularFarenheit();

float calcularKelvin();

int mostrarMenu();

int main() {
    int op;
    float celsius, farenheit;
    do {
        op = mostrarMenu();
        switch (op) {
            case 1:
                celsius = calcularCelsius();
                printf("Temperatura en Celsius: %f \n", celsius);
                break;
            case 2:
                farenheit = calcularFarenheit();
                printf("Temperatura en Farenheit: %f \n", farenheit);
                break;
            case 3:
                calcularKelvin();
                break;
        }
    } while (op != 4);
    return 0;
}

float calcularCelsius() {
    printf("Deme la temperatura en Kelvin \n");
    float temperatura;
    scanf("%f", &temperatura);
    float celsius;
    celsius = temperatura - 273.1;
    return celsius;
}

float calcularFarenheit() {
    printf("Deme la temperatura en Kelvin \n");
    float temperatura;
    scanf("%f", &temperatura);
    float farenheit;
    farenheit = ((temperatura - 273.15) * (9 / 5)) + 32;
    return farenheit;
}

float calcularKelvin() {
    return 0;
}

int mostrarMenu() {
    printf("1 .- Calcular Celsius\n");
    printf("2 .- Calcular Farenheit\n");
    printf("3 .- Calcular Kelvin\n");
    printf("4 .- Salir \n");
    int op;
    scanf("%i", &op);
    return op;
}
