/* Lo que se mostrara en pantalla */
#include <stdio.h>
#include <stdlib.h>

//generarTablero(char tablero[][], int filas, int columna);
void mostrarTablero(char tablero[12][12], int filas, int columnas);

void reiniciarTablero(char tablero[12][12]);

void generarCoordenadas(char tablero[12][12], int filas, int columnas,
                        int barcosTipo[12], char coordenadasInicio[12][12],
                        char orientacion[12], char coordenadasFinal[12]);

void mostrarHUD(char nombre[], char coordFalladas, char coordAtinadasm,
                int barcosHundidos, int barcosRestantes);

int main(int argc, char *argv[]) {
    if (argc == 3) {
        if (argv[1][0] >= '5' && argv[1][0] <= '9') {

            printf("Bienvenido %s a Battleship\n", argv[2]);

            int buquesCarga;
            int buquesBatalla;
            int buquesDestructores;

            char tableroJugador[12][12];
            char tableroEnemigo[12][12];

            reiniciarTablero(tableroJugador);
            mostrarTablero(tableroJugador, 12, 12);
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

void reiniciarTablero(char tablero[12][12]) {
    for (int x = 0; x < 12; x++)
        for (int y = 0; y < 12; y++)
            tablero[x][y] = '*';
}

void mostrarTablero(char tablero[12][12], int filas, int columnas) {
    printf("    ");
    for (char abecedario = 'A'; abecedario <= 'L'; abecedario++)
        printf("%c  ", abecedario);

    for (int i = 0; i < filas; i++) {
        if (i > 8)
            printf("\n%i  ", i + 1);
        else
            printf("\n%i   ", i + 1);

        for (int j = 0; j < columnas; j++)
            printf("%c  ", tablero[j][i]);
    }
    printf("\n");
}