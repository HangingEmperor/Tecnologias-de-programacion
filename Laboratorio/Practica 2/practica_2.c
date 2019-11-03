#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>

int esRespuesta(int size, wchar_t respuesta[100][48]);

void displayMenu(int menu);

void main()
{
    setlocale(LC_ALL, "");
    int menu, sizePreguntas = 0, sizeRespuestas = 0;
    int wasError = 0;
    int cantidadPreguntas[12];
    int posPregunta = 0;
    int ok = 0;

    wchar_t preguntas[50][12], respuestas[100][48], temporal[50][12];
    int tamPreguntas[12][12];

    int example = 0;
    int pass = 0;

    do
    {
        displayMenu(0);
        scanf("%i", &menu);
        while (getchar() != '\n')
        {
        };

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
                    while (getchar() != '\n')
                    {
                    };
                    pass = 0;

                    if (wasError)
                    {
                        printf(" Se ingreso un caracter invalido... \n\n");
                        printf("error: %i", example);
                    }
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
                        while (getchar() != '\n')
                        {
                        };

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
                            while (getchar() != '\n')
                            {
                            };
                            wchar_t aux[100][48];
                            printf("\n\n == Se selecciono la pregunta No. %i: == \n", posPregunta);
                            printf(" Ingresa una respuesta: ");
                            scanf("%l[^\n]", aux);
                            pass = esRespuesta(sizeRespuestas, aux);
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
                    system("sleep 1");
                }
                break;
                // Eliminar oracion
            case 3:
                if (sizePreguntas > 0)
                {
                    system("clear");
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
                                system("sleep 1");
                            }
                        }
                    }
                }
                else
                {
                    printf("No hay preguntas que eliminar... \n");
                    system("sleep 1");
                }
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

int esRespuesta(int size, wchar_t respuesta[100][48])
{
    wchar_t aux[50][20];
    wchar_t valor[50][20];
    int resultado;
    int comas = 0;
    int esPalabra = 0;
    int sizeAux = 0;

    if (toascii(respuesta[size][0]) == 35 &&
        (iswdigit(respuesta[size][1]) != 0 && iswdigit(respuesta[size][2]) != 0) &&
        toascii(respuesta[size][3]) == 168)
    {
        for (int i = 4; i < wcslen(respuesta[size]); i++)
        {
            if (iswalpha(respuesta[size][i]) != 0)
            {
                wcscpy(aux[sizeAux], respuesta[size]);
                sizeAux++;
            } else {
                if (toascii(respuesta[size][i]) == 44)
                {
                    comas++;
                } else {
                    if (toascii(respuesta[size][i]) == 36) {
                        if (iswdigit(respuesta[size][i]) != 0 &&
                            iswdigit(respuesta[size][i + 1])) {
                            wcscpy(valor, wcscat(respuesta[size][i], respuesta[size][i + 1]));
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
    if (comas >= 4) {
        printf("Exito");
    } else {
        printf("Fracaso");
    }
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
        system("clear");
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