#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    setlocale(LC_ALL, "");
    wchar_t respuesta[100][20];
    wchar_t valor[50][20];
    wchar_t id[1][48];

    int resultado;
    int comas = 0;
    int size = 0;

    // #00¿Esclavitud,Sometimiento,Sujeción,Opresión,Servidumbre$49
    wscanf(L"%l[^\n]", respuesta[0]);

    wchar_t palabras[20][20];
    int palabraPoint = 0;
    int letraPoint = 0;

    if (toascii(respuesta[size][0]) == 35 &&
        (iswdigit(respuesta[size][1]) != 0 && iswdigit(respuesta[size][2]) != 0) &&
        toascii(respuesta[size][3]) == 40) {
        id[size][0] = respuesta[size][1];
        id[size][1] = respuesta[size][2];

        for (int i = 4; i < wcslen(respuesta[size]); i++) {
            //printf("Se ingreso: %c \n", respuesta[size][i]);
            //printf("palabraPoint: %i, letraPoint: %i\n", palabraPoint, letraPoint);
            if (iswalpha(respuesta[size][i]) != 0 || toascii(respuesta[size][i]) == 113 ||
                toascii(respuesta[size][i]) == 81 || toascii(respuesta[size][i]) == 97 ||
                toascii(respuesta[size][i]) == 105 || toascii(respuesta[size][i]) == 109 ||
                toascii(respuesta[size][i]) == 115 || toascii(respuesta[size][i]) == 122 ||
                toascii(respuesta[size][i]) == 34 || toascii(respuesta[size][i]) == 32) {
                palabras[palabraPoint][letraPoint] = respuesta[size][i];
                letraPoint++;
            } else {
                if (toascii(respuesta[size][i]) == 44) {
                    comas++;
                    palabraPoint++;
                    letraPoint = 0;
                } else {
                    if (toascii(respuesta[size][i]) == 36) {
                        if (iswdigit(respuesta[size][i + 1]) != 0) {
                            if ((i + 3) == wcslen(respuesta[size]) && iswdigit(respuesta[size][i + 2]) != 0) {
                                valor[0][1] = respuesta[size][i + 2];
                            }
                            valor[0][0] = respuesta[size][i + 1];
                            resultado = 1;
                            i = wcslen(respuesta[size]);
                            break;
                        } else {
                            resultado = 0;
                        }
                    } else {
                        resultado = 0;
                    }
                }
            }
        }
    } else {
        resultado = 0;
    }
    if (comas >= 4 && resultado) {
        printf("Exito\n");
    } else {
        printf("Fracaso\n");
    }

    printf("id: ");
    wprintf(id[0]);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("Palabra: ");
        wprintf(palabras[i]);
        printf("\n");
    }
    printf("valor: ");
    wprintf(valor[0]);
}