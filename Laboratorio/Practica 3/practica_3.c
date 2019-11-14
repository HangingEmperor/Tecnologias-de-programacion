/* Lo que se mostrara en pantalla */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

//generarTablero(char tablero[][], int filas, int columna);
// huehue
void mostrarTablero(char tablero[12][12], int filas, int columnas);

void reiniciarTablero(char tablero[12][12]);

void generarCoordenadas(char tablero[12][12], int filas, int columnas, int size,
                        int barcosTipo[], char coordenadasInicio[12][1],
                        char orientacion[12]);

void mostrarHUD(char nombre[], char coordFalladas, char coordAtinadasm,
                int barcosHundidos, int barcosRestantes);

void dibujarBarcos(char tablero[12][12], int filas, int columnas, int barcosTipos[12],
                   char coordenadasInicio[12][1], char orientacion[12]);

int main(int argc, char *argv[]) {
    if (argc == 3) {
        if (argv[1][0] >= '5' && argv[1][0] <= '9' || ((int) argv[0][1] - 48) == 10) {
            int total;
            int buquesCarga;
            int buquesBatalla;
            int barcosTipos[10];
            int buquesDestructores;
            int movimientosRestantes = 0;
            int barcos = (int) argv[1][0] - 48;

            if (barcos == 1 && ((int) argv[1][1] - 48) == 0)
                barcos = 10;

            buquesCarga = ceil(barcos * .2);
            buquesBatalla = ceil(barcos * .3);
            buquesDestructores = ceil(barcos * .4);

            if ((buquesCarga + buquesBatalla + buquesDestructores) < barcos)
                buquesBatalla++;
            else if ((buquesCarga + buquesBatalla + buquesDestructores) > barcos)
                buquesBatalla--;

            movimientosRestantes =
                    (((buquesDestructores * 3) + (buquesBatalla * 4) + (buquesCarga * 5)) * (barcos)) / 2;

            char tableroJugador[12][12];
            char tableroEnemigo[12][12];

            reiniciarTablero(tableroJugador);
            reiniciarTablero(tableroEnemigo);
            mostrarTablero(tableroJugador, 12, 12);

            char coordenada[2];
            char coordenadaSend[10][1];
            char orientacion[10];

            printf("Jugador: %s \n", argv[2]);
            printf("Coordenadas Falladas: \n");
            printf("Coodernadas Atinadas: \n");
            printf("Oportunidades restantes: %i\n", movimientosRestantes);
            printf("Barcos hundidos: \n");
            printf("Barcos restantes: \n");
            printf("COORDENADA: ");
            scanf("%s", coordenada);
            coordenadaSend[0][0] = coordenada[0];
            coordenadaSend[0][1] = coordenada[2];

            int bB = buquesBatalla, bC = buquesCarga, bD = buquesDestructores;
            for (int i = 0; i < barcos; i++) {
                if (bB != 0) {
                    barcosTipos[i] = 2;
                    bB--;
                } else if (bC != 0) {
                    barcosTipos[i] = 1;
                    bC--;
                } else {
                    barcosTipos[i] = 3;
                    bD--;
                }
            }

            srand(time(NULL));
            int x, y;
            for (int i = 0; i < barcos; i++) {
                x = rand() % (2) + 1;
                if (x == 1)
                    orientacion[i] = 'V';
                else if (x == 2)
                    orientacion[i] = 'H';
            }

            for (int i = 0; i < barcos; i++) {
                x = rand() % (12 + 1);
                y = rand() % (12 + 1);

                // V = ^, H = >
                if (orientacion[i] == 'H') {
                    if (x > 7 && y >= 0)
                        x = x - barcosTipos[i] - 3;
                    for (int j = 0; j < barcos; j++) {
                        if (coordenadaSend[j][0] - 65 == x) {
                            if (y > 0)
                                y--;
                            else
                                y++;
                        }
                    }
                } else if (orientacion[i] == 'V') {
                    if (y < 6 && x >= 0)
                        y = y + barcosTipos[i] + 3;
                }

                x = x + 65;
                y = y + 48;
                coordenadaSend[i][0] = x;
                coordenadaSend[i][1] = y;
            }

            generarCoordenadas(tableroEnemigo, 12, 12, barcos, barcosTipos, coordenadaSend, orientacion);
            mostrarTablero(tableroEnemigo, 12, 12);
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

void generarCoordenadas(char tablero[12][12], int filas, int columnas, int size,
                        int barcosTipo[], char coordenadasInicio[12][1],
                        char orientacion[12]) {
    int y = 0;
    for (int i = 0; i < size; i++) {
        if (coordenadasInicio[i][1] == ':')
            y = 10;
        else if (coordenadasInicio[i][1] == ';')
            y = 11;
        else if (coordenadasInicio[i][1] == '<')
            y = 12;
        else
            y = (int) coordenadasInicio[i][1] - 49;

        switch (barcosTipo[i]) {
            case 1:
                if (orientacion[i] == 'V') {
                    tablero[((int) coordenadasInicio[i][0] - 65)][y] = '-';
                    tablero[((int) coordenadasInicio[i][0] - 65)][y - 1] = '|';
                    tablero[((int) coordenadasInicio[i][0] - 65)][y - 2] = '|';
                    tablero[((int) coordenadasInicio[i][0] - 65)][y - 3] = '|';
                    tablero[((int) coordenadasInicio[i][0] - 65)][y - 4] = '^';
                } else {
                    tablero[((int) coordenadasInicio[i][0] - 65)][y] = '|';
                    tablero[((int) coordenadasInicio[i][0] + 1 - 65)][y] = '-';
                    tablero[((int) coordenadasInicio[i][0] + 2 - 65)][y] = '-';
                    tablero[((int) coordenadasInicio[i][0] + 3 - 65)][y] = '-';
                    tablero[((int) coordenadasInicio[i][0] + 4 - 65)][y] = '>';
                }
                break;
            case 2:
                if (orientacion[i] == 'V') {
                    tablero[((int) coordenadasInicio[i][0] - 65)][y] = '-';
                    tablero[((int) coordenadasInicio[i][0] - 65)][y - 1] = '|';
                    tablero[((int) coordenadasInicio[i][0] - 65)][y - 2] = '|';
                    tablero[((int) coordenadasInicio[i][0] - 65)][y - 3] = '^';
                } else {
                    tablero[((int) coordenadasInicio[i][0] - 65)][y] = '|';
                    tablero[((int) coordenadasInicio[i][0] + 1 - 65)][y] = '-';
                    tablero[((int) coordenadasInicio[i][0] + 2 - 65)][y] = '-';
                    tablero[((int) coordenadasInicio[i][0] + 3 - 65)][y] = '>';
                }
                break;
            case 3:
                if (orientacion[i] == 'V') {
                    tablero[((int) coordenadasInicio[i][0] - 65)][y] = '-';
                    tablero[((int) coordenadasInicio[i][0] - 65)][y - 1] = '|';
                    tablero[((int) coordenadasInicio[i][0] - 65)][y - 2] = '^';
                } else {
                    tablero[((int) coordenadasInicio[i][0] - 65)][y] = '|';
                    tablero[((int) coordenadasInicio[i][0] + 1 - 65)][y] = '-';
                    tablero[((int) coordenadasInicio[i][0] + 2 - 65)][y] = '>';
                }
                break;
        }
    }
}