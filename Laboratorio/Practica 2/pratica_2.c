#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <wchar.h>

void main() {
    setlocale(LC_ALL, "");
    int menu, sizePreguntas = 0, sizeRespuestas = 0;
    int wasError = 0;
    int cantidadPreguntas[12];
    int posPregunta = 0;
    int ok = 0;

    wchar_t preguntas[50][12];
    wchar_t respuestas[100][48];
    wchar_t temporal[50][12];

    int example = 0;
    int pass = 0;

    do {
        system("clear");
        printf(" --- Bienvenido a: 100 Ingenieros Dijeron --- \n");
        printf("\n Que deseas hacer? \n");
        printf("\n 1 .- Editar Banco de Palabras.");
        printf("\n 2 .- Jugar!");
        printf("\n 3 .- Salir \n\n ---> Opcion: ");
        scanf("%i", &menu);
        while (getchar() != '\n') {};

        switch (menu) {
            // Editar Banco de Palabras
            case 1:
                system("clear");
                printf(" --- 100 Ingenieros Dijeron ---> Editar Banco de Palabras ---");
                printf("\n 1 .- Llenar Preguntas");
                printf("\n 2 .- Llenar Respuestas");
                printf("\n 3 .- Eliminar Oración \n\n ---> Opcion: ");
                scanf("%i", &menu);

                switch (menu) {
                    /* Minimo 4 respuestas, maximo 6 respuestas, cada respuesta debe tener 4 sinonimos*/
                    // Llenar preguntas
                    case 1:
                        do {
                            while (getchar() != '\n') {};
                            pass = 0;
                            system("clear");
                            if (wasError) {
                                printf(" Se ingreso un caracter invalido... \n\n");
                                printf("error: %i", example);
                            }
                            printf(" --- 100 Ingenieros Dijeron ---> Editar Banco de Palabras ---> Llenar preguntas ---");
                            if (sizePreguntas < 12) {
                                printf("\n Ingrese una pregunta para el juego: ");
                                scanf("%l[^\n]", preguntas[sizePreguntas]);

                                for (int j = 0; j < sizeof(preguntas[sizePreguntas]); ++j) {
                                    if (preguntas[sizePreguntas][j] != '\0') {
                                        if ((toascii(preguntas[sizePreguntas][j]) >= 65 &&
                                             toascii(preguntas[sizePreguntas][j]) <= 90) ||
                                            toascii(preguntas[sizePreguntas][j]) == 63 ||
                                            toascii(preguntas[sizePreguntas][j]) == 32 ||
                                            (toascii(preguntas[sizePreguntas][j]) >= 97 &&
                                             toascii(preguntas[sizePreguntas][j]) <= 122)) {
                                        } else {
                                            pass = 1;
                                            wasError = 1;
                                            example = toascii(preguntas[sizePreguntas][j]);
                                            break;
                                        }
                                    } else {
                                        sizePreguntas++;
                                        break;
                                    }
                                }

                            } else {
                                printf("\n Ya has alcanzado el maximo de 12 preguntas. \n");
                            }
                        } while (pass);
                        break;

                        // Llenar respuestas
                    case 2:
                        wasError = 0;
                        if (sizePreguntas > 0) {
                            do {
                                pass = 0;
                                ok = 0;
                                while (getchar() != '\n') {};
                                //system("clear");

                                if (wasError == 1) {
                                    printf("No existe la posicion de esa pregunta...\n");
                                } else if (wasError == 2) {
                                    printf("Se ingreso un caracter invalido... \n");
                                } else if (wasError == 3) {
                                    printf("No se ingreso el numero ID de pregunta... \n");
                                }

                                printf(" --- 100 Ingenieros Dijeron ---> Editar Banco de Palabras ---> Llenar preguntas --- \n");
                                printf(" === Preguntas disponibles: %i === \n\n", sizePreguntas);

                                for (int i = 0; i < sizePreguntas; ++i) {
                                    printf(" # Pregunta No. %i: ", (i + 1));
                                    printf("%ls \n", preguntas[i]);
                                }

                                printf("\n Ingrese el numero de la pregunta que desea colocar respuestas: ");
                                scanf("%i", &posPregunta);

                                if (posPregunta > 0 && posPregunta <= sizePreguntas) {
                                    while (getchar() != '\n') {};
                                    printf("\n\n == Se selecciono la pregunta No. %i: == \n", posPregunta);
                                    printf(" Ingresa una respuesta: ");
                                    scanf("%l[^\n]", respuestas[sizeRespuestas]);

                                    printf("%i\n", toascii(respuestas[sizeRespuestas][0]));

                                    if (toascii(respuestas[sizeRespuestas][0]) == 35) {
                                        ok = 1;
                                        if ((toascii(respuestas[sizeRespuestas][1]) >= 48 &&
                                             toascii(respuestas[sizeRespuestas][1]) <= 57) &&
                                            (toascii(respuestas[sizeRespuestas][2]) >= 48 &&
                                             toascii(respuestas[sizeRespuestas][2]) <= 57)) {
                                            if (toascii(respuestas[sizeRespuestas][3]) == 63) {
                                            } else {
                                                ok = 0;
                                            }
                                        } else {
                                            ok = 0;
                                        }
                                    }

                                    if (ok) {
                                        for (int i = 4; i < sizeof(respuestas[sizeRespuestas]); i++) {
                                            if (respuestas[sizeRespuestas] == '\0') {
                                                if (toascii(respuestas[sizeRespuestas][i]) == 44) {
                                                    if (i == 4) {
                                                        wasError = 2;
                                                        pass = 1;
                                                        break;
                                                    }
                                                } else if ((toascii(respuestas[sizeRespuestas][i]) >= 48 &&
                                                            toascii(respuestas[sizeRespuestas][i]) <= 57) &&
                                                           (toascii(respuestas[sizeRespuestas][i]) >= 48 &&
                                                            toascii(respuestas[sizeRespuestas][i]) <= 57)) {
                                                } else {
                                                    if (toascii(respuestas[sizeRespuestas][i]) == 36) {
                                                        if (toascii(respuestas[sizeRespuestas][
                                                                            sizeof(respuestas[sizeRespuestas]) - 1]) >=
                                                            48 &&
                                                            toascii(respuestas[sizeRespuestas][
                                                                            sizeof(respuestas[sizeRespuestas]) - 1]) <=
                                                            57) {
                                                            printf("ok");
                                                        }
                                                    }
                                                    wasError = 2;
                                                    pass = 1;
                                                    break;
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                    } else {
                                        wasError = 2;
                                        pass = 1;
                                    }
                                } else {
                                    pass = 1;
                                    wasError = 1;
                                }
                            } while (pass);
                        } else {
                            printf("\n El banco de preguntas esta vacio... \n");
                            system("sleep 1");
                        }
                        break;
                        // Eliminar oracion
                    case 3:
                        break;
                    default:
                        printf("\n Caracter invalido.... \n");
                        break;
                }
                break;
                // Juego
            case 2:
                system("clear");
                printf(" --- 100 Ingenieros Dijeron. [ _ _ _] \n");
                printf(" Meciona algo opuesto a: \n");
                printf("\n 1. ..............................    ....");
                printf("\n 2. ..............................    ....");
                printf("\n 3. ..............................    ....");
                printf("\n 4. ..............................    ....");
                printf("\n 5. ..............................    ....");
                printf("\n\n Ingrese su respuesta: ");

                break;
                // Salir
            case 3:
                break;
            default:
                printf("\n Caracter invalido.... \n");
                break;
        }
    } while (menu != 3);
}

