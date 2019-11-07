#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>

void displayMenu(int menu);

void pause();

void main()
{
    setlocale(LC_ALL, "");
    int menu, sizePreguntas = 0, sizeRespuestas = 0;
    int sizePreguntaRespuesta = 0;
    int wasError = 0;
    int cantidadPreguntas[12];
    int posPregunta = 0;
    int ok = 0;

    wchar_t preguntas[50][12];
    wchar_t respuesta[100][48];
    wchar_t temporal[50][12];
    wchar_t valor[100][20];
    wchar_t id[1][48];
    int ide = 0;

    int resultado;
    int comas = 0;
    int size = 0;

    wchar_t palabras[20][20];
    wchar_t colectorPalabras[20][20];
    int palabraPoint = 0;
    int letraPoint = 0;

    int tamPreguntas[12][12];

    int example = 0;
    int pass = 0;

    do
    {
        displayMenu(0);
        scanf("%i", &menu);
        while (getchar() != '\n') {};

        switch (menu)
        {
        // Editar Banco de Palabras
        case 1:
            displayMenu(1);
            scanf("%i", &menu);

            switch (menu)
            {
            /* Minimo 4 respuestas, maximo 6 respuestas, cada respuesta debe tener 4 sinonimos*/
            // Llenar preguntas
            case 1:
                do
                {
                    while (getchar() != '\n') {};
                    pass = 0;

                    printf(" --- 100 Ingenieros Dijeron ---> Editar Banco de Palabras ---> Llenar preguntas ---");
                    if (sizePreguntas < 12)
                    {
                        printf("\n Ingrese una pregunta para el juego: ");
                        scanf("%l[^\n]", preguntas[sizePreguntas]);

                        for (int j = 0; j < sizeof(preguntas[sizePreguntas]); ++j)
                        {
                            if (preguntas[sizePreguntas][j] != '\0')
                            {
                                if ((toascii(preguntas[sizePreguntas][j]) >= 65 &&
                                     toascii(preguntas[sizePreguntas][j]) <= 90) ||
                                    toascii(preguntas[sizePreguntas][j]) == 63 ||
                                    toascii(preguntas[sizePreguntas][j]) == 32 ||
                                    (toascii(preguntas[sizePreguntas][j]) >= 97 &&
                                     toascii(preguntas[sizePreguntas][j]) <= 122))
                                {
                                }
                                else
                                {
                                    pass = 1;
                                    wasError = 1;
                                    example = toascii(preguntas[sizePreguntas][j]);
                                    break;
                                }
                            }
                            else
                            {
                                sizePreguntas++;
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("\n Ya has alcanzado el maximo de 12 preguntas. \n");
                    }
                } while (pass);
                break;

                // Llenar respuestas
            case 2:
                wasError = 0;
                if (sizePreguntas > 0)
                {
                    do
                    {
                        pass = 0;
                        while (getchar() != '\n') {};

                        printf(" --- 100 Ingenieros Dijeron ---> Editar Banco de Palabras ---> Llenar preguntas --- \n");
                        printf(" === Preguntas disponibles: %i === \n\n", sizePreguntas);

                        for (int i = 0; i < sizePreguntas; ++i)
                        {
                            printf(" # Pregunta No. %i: ", (i + 1));
                            printf("%ls \n", preguntas[i]);
                        }

                        printf("\n Ingrese el numero de la pregunta que desea colocar respuestas: ");
                        scanf("%i", &posPregunta);

                        if (posPregunta > 0 && posPregunta <= sizePreguntas)
                        {
                            while (getchar() != '\n') {};
                            printf("\n\n == Se selecciono la pregunta No. %i: == \n", posPregunta);
                            printf(" Ingresa una respuesta: ");
                            scanf("%l[^\n]", respuesta[sizeRespuestas]);

                            palabraPoint = 0;
                            if (toascii(respuesta[sizeRespuestas][0]) == 35 &&
                                (iswdigit(respuesta[sizeRespuestas][1]) != 0 &&
                                 iswdigit(respuesta[sizeRespuestas][2]) != 0) &&
                                toascii(respuesta[sizeRespuestas][3]) == 40) {
                                id[sizeRespuestas][0] = respuesta[sizeRespuestas][1];
                                id[sizeRespuestas][1] = respuesta[sizeRespuestas][2];

                                for (int i = 4; i < wcslen(respuesta[size]); i++) {
                                    if (iswalpha(respuesta[sizeRespuestas][i]) != 0 ||
                                        toascii(respuesta[sizeRespuestas][i]) == 113 ||
                                        toascii(respuesta[sizeRespuestas][i]) == 81 ||
                                        toascii(respuesta[sizeRespuestas][i]) == 97 ||
                                        toascii(respuesta[sizeRespuestas][i]) == 105 ||
                                        toascii(respuesta[sizeRespuestas][i]) == 109 ||
                                        toascii(respuesta[sizeRespuestas][i]) == 115 ||
                                        toascii(respuesta[sizeRespuestas][i]) == 122 ||
                                        toascii(respuesta[sizeRespuestas][i]) == 34 ||
                                        toascii(respuesta[sizeRespuestas][i]) == 32) {
                                        palabras[palabraPoint][letraPoint] = respuesta[sizeRespuestas][i];
                                        letraPoint++;
                                    } else {
                                        if (toascii(respuesta[sizeRespuestas][i]) == 44) {
                                            comas++;
                                            palabraPoint++;
                                            int sizeColector = 0;
                                            letraPoint = 0;
                                        } else {
                                            if (toascii(respuesta[sizeRespuestas][i]) == 36) {
                                                if (iswdigit(respuesta[sizeRespuestas][i + 1]) != 0) {
                                                    if ((i + 3) == wcslen(respuesta[sizeRespuestas]) &&
                                                        iswdigit(respuesta[sizeRespuestas][i + 2]) != 0) {
                                                        valor[0][1] = respuesta[sizeRespuestas][i + 2];
                                                    }
                                                    valor[0][0] = respuesta[sizeRespuestas][i + 1];
                                                    resultado = 1;
                                                    i = wcslen(respuesta[sizeRespuestas]);
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
                            if (comas >= 1 && resultado) {
                                printf("Realizado con exito\n");

                                printf("id: ");
                                wprintf(id[ide]);
                                printf("\n");
                                for (int i = 0; i < comas + 1; i++) {
                                    printf("Palabra: ");
                                    wprintf(palabras[i]);
                                    printf("\n");
                                }
                                printf("valor: ");
                                wprintf(valor[ide]);
                                printf("\n");
                                sizeRespuestas++;
                                ide++;
                            } else {
                                printf("Error en la oracion. \n");
                            }
                        }
                        else
                        {
                            pass = 1;
                            wasError = 1;
                        }
                    } while (pass);
                }
                else
                {
                    printf("\n El banco de preguntas esta vacio... \n");
                }
                break;
                // Eliminar oracion
            case 3:
                if (sizePreguntas > 0)
                {
                    printf(" --- 100 Ingenieros Dijeron ---> Editar Banco de Palabras ---> Eliminar preguntas --- \n");
                    printf(" === Total de preguntas: %i === \n\n", sizePreguntas);

                    for (int i = 0; i < sizePreguntas; ++i)
                    {
                        printf(" # Pregunta No. %i: ", (i + 1));
                        printf("%ls \n", preguntas[i]);
                    }

                    while (getchar() != '\n')
                    {
                    };
                    printf("\n Ingrese el numero de la pregunta que desea eliminar (Se borrara junto con las respuestas: ");
                    scanf("%i", &menu);

                    if (menu <= sizePreguntas)
                    {
                        for (int i = 0; i < sizePreguntas; ++i)
                        {
                            if (wcscmp(preguntas[menu - 1], preguntas[i]))
                            {
                                int j = 0;
                                for (j = i; j < sizePreguntas + 1; j++)
                                {
                                    wcscpy(preguntas[j], preguntas[j + 1]);
                                }
                                sizePreguntas--;
                                printf("\n Se ha eliminado correctamente... \n");
                            }
                        }
                    }
                }
                else
                {
                    printf("No hay preguntas que eliminar... \n");
                }
                break;
            default:
                printf("\n Caracter invalido.... \n");
                break;
            }
            break;
            // Juego
        case 2:
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

void displayMenu(int menu)
{
    switch (menu)
    {
    case 0:
        printf(" --- Bienvenido a: 100 Ingenieros Dijeron --- \n");
        printf("\n Que deseas hacer? \n");
        printf("\n 1 .- Editar Banco de Palabras.");
        printf("\n 2 .- Jugar!");
        printf("\n 3 .- Salir \n\n ---> Opcion: ");
        break;
    case 1:
        printf(" --- 100 Ingenieros Dijeron ---> Editar Banco de Palabras ---");
        printf("\n 1 .- Llenar Preguntas");
        printf("\n 2 .- Llenar Respuestas");
        printf("\n 3 .- Eliminar Oración \n\n ---> Opcion: ");
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
}

void pause() {
    printf("Presiona ENTER para continuar... ");
    while (getchar() != '\n') {};
    while (getchar() != '\n') {};
}