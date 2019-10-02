#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    /* Declaracion de variables */
    int opcionMenu = 0, size = -1, pass = 1;
    int clave[100], duracion[100], cantidadInventario[100], ano[100], esRenta[100], estaRentado[100];
    /* Clave renta: 0 = Clave de Renta, 1 = Clave de Pelicula, 2 = Numero de copias rentadas, 3 = Precio total*/
    int claveRenta[100], clavePelicula[100], claveCopias[100];
    char claveNombre[50][100];
    char titulo[50][100], director[50][100], genero[7][100];

    int claveTemporal = 0, aux = 0, contador = 0, sizeRentas = 0;
    int topVenta[5], auxi, pointerRentas = 0;
    int auxilar[5][100];
    int rentasTotal = 0;

    do {
        /* Menu principal */
        printf("\n --- Menu BrickBuster --- \n");
        printf(" Seleccione con un numero. \n");
        printf(" 1.- Registro \n"
               " 2.- Eliminacion \n"
               " 3.- Modificacion \n"
               " 4.- Busqueda \n"
               " 5.- Rentas \n"
               " 6.- Premios de la Academia \n"
               " 7.- Salir \n");
        scanf("%i", &opcionMenu);

        switch (opcionMenu) {
            // Registro
            case 1:
                size++;
                printf("\n --- BrickBuster -> Registro ---");

                do {
                    pass = 0;
                    printf("\n Clave numerica: ");
                    scanf("%i", &claveTemporal);

                    int aux = clave[size], contador = 1;

                    while (aux / 10 > 0) {
                        aux = aux / 10;
                        contador++;
                    }
                    if (clave[size] < 0 || contador > 5) {
                        pass = 1;
                        printf("\n La clave ingresada es negativa o mayor a 5 digitos... Ingrese de nuevo los datos.");
                    }

                    for (int i = 0; i < size + 1; ++i) {
                        if (clave[i] == claveTemporal) {
                            pass = 1;
                            printf(" \n Clave existente o invalida... Ingrese de nuevo los datos.");
                            break;
                        }
                    }
                    if (!pass) {
                        clave[size] = claveTemporal;
                    }
                    while (getchar() != '\n') {};
                } while (pass);

                printf(" Titulo: ");
                scanf("%[^\n]", titulo[size]);
                while (getchar() != '\n') {};

                printf(" Director: ");
                scanf("%[^\n]", director[size]);
                while (getchar() != '\n') {};

                do {
                    pass = 0;
                    printf(" Duracion [En minutos]: ");
                    scanf("%i", &duracion[size]);

                    if (duracion[size] < 1) {
                        pass = 1;
                    }
                    while (getchar() != '\n') {};
                } while (pass);

                do {
                    pass = 0;
                    printf(" Año de lanzamiento: ");
                    scanf("%i", &ano[size]);

                    if (ano[size] < 1895 || ano[size] > 2019) {
                        pass = 1;
                    }
                    while (getchar() != '\n') {};
                } while (pass);
                do {
                    pass = 0;
                    printf(" Cantidad en inventario: ");
                    scanf("%i", &cantidadInventario[size]);

                    if (cantidadInventario[size] < 0 || cantidadInventario[size] > 100) {
                        pass = 1;
                        printf("\n La cantidad ingresada es negativa o mayor a 2 digitos... Ingrese de nuevo los datos.");
                    }
                    if (cantidadInventario[size] == 0) {
                        esRenta[size] = 0;
                    } else {
                        estaRentado[size] = 0;
                        esRenta[size] = 1;
                    }
                    while (getchar() != '\n') {};
                } while (pass);

                do {
                    pass = 0;
                    printf("\n Genero");
                    printf("\n Solo se permiten los generos:"
                           "\n - Romance\n - Accion\n - Horror \n");
                    scanf("%s", genero[size]);

                    if (!(strcasecmp(genero[size], "romance") == 0 ||
                          strcasecmp(genero[size], "accion") == 0 ||
                          strcasecmp(genero[size], "horror") == 0)) {
                        pass = 1;
                        printf("\n Genero no admitido... Ingrese de nuevo los datos.");
                    }
                    while (getchar() != '\n') {};
                } while (pass);
                estaRentado[size] = 0;
                break;
            case 2:
                // Eliminacion
                if (size > -1) {
                    int pos = 0;
                    do {
                        pass = 0;
                        printf("\n --- BrickBuster -> Eliminacion ---");
                        printf("\n Ingrese la clave de la pelicula: ");
                        scanf("%i", &claveTemporal);

                        while (aux / 10 > 0) {
                            aux = aux / 10;
                            contador++;
                        }
                        if (clave[size] < 0 || contador > 5) {
                            pass = 1;
                            printf("\nLa clave ingresada es negativa o mayor a 5 digitos... Ingrese de nuevo los datos.");
                            continue;
                        }

                        for (int i = 0; i < size + 1; i++) {
                            if (claveTemporal == clave[i]) {
                                pass = 0;
                                pos = i;
                                break;
                            } else {
                                pass = 1;
                                if (i == size) {
                                    printf("\n No existe la clave... \n");
                                }
                            }
                        }
                        while (getchar() != '\n') {};
                    } while (pass);

                    if (!estaRentado[pos]) {
                        for (int i = 0; i < size + 1; ++i) {
                            if (claveTemporal == clave[i]) {
                                int j = 0;
                                for (j = i; j < size + 1; j++) {
                                    clave[j] = clave[j + 1];
                                    strcpy(titulo[j], titulo[j + 1]);
                                    strcpy(director[j], director[j + 1]);
                                    duracion[j] = duracion[j + 1];
                                    cantidadInventario[j] = duracion[j + 1];
                                    ano[j] = ano[j + 1];
                                    esRenta[j] = esRenta[j + 1];
                                    estaRentado[j] = estaRentado[j + 1];
                                }
                                size--;
                                printf("\n Se ha eliminado correctamente... \n");
                            }
                        }
                    } else {
                        printf("\n No se pudo eliminar la pelicula, actualmente esta en renta... \n");
                    }
                } else {
                    printf("\n No hay datos disponibles...\n");
                }
                break;
            case 3:
                // Modificacion
                if (size > -1) {
                    do {
                        pass = 0;
                        printf("\n --- BrickBuster ---> Edicion ---");
                        printf("\n (Si solo se presiona ENTER, se conservara los valores previos registrados.)");
                        printf("\n Ingrese la clave de la pelicula: ");
                        scanf("%i", &claveTemporal);

                        while (aux / 10 > 0) {
                            aux = aux / 10;
                            contador++;
                        }
                        if (clave[size] < 0 || contador > 5) {
                            pass = 1;
                            printf("\nLa clave ingresada es negativa o mayor a 5 digitos... Ingrese de nuevo los datos.");
                        }
                        for (int i = 0; i < size + 1; i++) {
                            if (claveTemporal == clave[i]) {
                                pass = 0;
                                break;
                            } else {
                                pass = 1;
                                if (i == size) {
                                    printf("\n No existe la clave... \n");
                                }
                            }
                        }
                        while (getchar() != '\n') {};
                    } while (pass);

                    int i = 0;
                    for (i = 0; i < size + 1; i++) {
                        if (claveTemporal == clave[i]) {
                            printf(" Titulo: ");
                            char tituloTemporal[100] = "";
                            scanf("%[^\n]", tituloTemporal);
                            if (tituloTemporal[0] != '\0') {
                                strcpy(titulo[i], tituloTemporal);
                            }
                            while (getchar() != '\n') {};

                            printf(" Director: ");
                            char directorTemporal[100] = "";
                            scanf("%[^\n]", directorTemporal);
                            if (directorTemporal[0] != '\0') {
                                strcpy(director[i], directorTemporal);
                            }
                            while (getchar() != '\n') {};

                            int duracionTemporal = 0;
                            char num[5] = "";
                            do {
                                pass = 0;
                                printf(" Duracion [En minutos]: ");
                                scanf("%[^\n]", num);
                                if (num[0] != '\0') {
                                    for (int j = 0; j < sizeof(num) - 2; j++) {
                                        int a = isdigit(num[j]);
                                        if (a) {
                                            duracionTemporal = atoi(num);
                                            if (duracionTemporal < 1) {
                                                pass = 1;
                                            } else {
                                                pass = 0;
                                                duracion[i] = duracionTemporal;
                                                break;
                                            }
                                        } else {
                                            pass = 1;
                                            printf("\n Ingresa un caracter valido... \n");
                                            break;
                                        }
                                    }
                                }
                                while (getchar() != '\n') {};
                            } while (pass);

                            int anoTemporal = 0;
                            char anoC[4] = "";
                            do {
                                pass = 0;
                                printf(" Año de lanzamiento: ");
                                scanf("%[^\n]", anoC);
                                if (anoC[0] != '\0') {
                                    for (int j = 0; j < sizeof(anoC); j++) {
                                        int a = isdigit(anoC[j]);
                                        if (a) {
                                            anoTemporal = atoi(anoC);
                                            if (anoTemporal < 1895 || anoTemporal > 2019) {
                                                pass = 1;
                                            } else {
                                                pass = 0;
                                                ano[i] = anoTemporal;
                                                break;
                                            }
                                        } else {
                                            pass = 1;
                                            printf("\n Ingresa un caracter valido... \n");
                                            break;
                                        }
                                    }
                                }
                                while (getchar() != '\n') {};
                            } while (pass);

                            int cantidadInventarioTemporal = 0;
                            char cantidadC[2] = "";
                            do {
                                pass = 0;
                                printf(" Cantidad en inventario: ");
                                scanf("%[^\n]", cantidadC);
                                if (cantidadC[0] != '\0') {
                                    for (int j = 0; j < sizeof(cantidadC); j++) {
                                        int a = isdigit(cantidadC[j]);
                                        if (a) {
                                            cantidadInventarioTemporal = atoi(cantidadC);
                                            if (cantidadInventarioTemporal < 0 || cantidadInventarioTemporal > 99) {
                                                pass = 1;
                                                printf("\n La cantidad ingresada es negativa o mayor a 2 digitos... Ingrese de nuevo los datos.");
                                                break;
                                            } else {
                                                cantidadInventario[i] = cantidadInventarioTemporal;
                                                if (cantidadInventario[i] == 0) {
                                                    esRenta[i] = 0;
                                                }
                                                pass = 0;
                                                break;
                                            }
                                        } else {
                                            pass = 1;
                                            printf("\n Ingresa un caracter valido... \n");
                                            break;
                                        }
                                    }
                                }
                                while (getchar() != '\n') {};
                            } while (pass);

                            char generoTemporal[7] = "";
                            do {
                                pass = 0;
                                printf("\n Genero");
                                printf("\n Solo se permiten los generos:"
                                       "\n - Romance\n - Accion\n - Horror \n");
                                scanf("%[^\n]", generoTemporal);

                                if (generoTemporal[0] != '\0') {
                                    if (!(strcasecmp(generoTemporal, "romance") == 0 ||
                                          strcasecmp(generoTemporal, "accion") == 0 ||
                                          strcasecmp(generoTemporal, "horror") == 0)) {
                                        pass = 1;
                                        printf("\n Genero no admitido... Ingrese de nuevo los datos.");
                                    } else {
                                        pass = 0;
                                        strcpy(genero[i], generoTemporal);
                                    }
                                }
                                while (getchar() != '\n') {};
                            } while (pass);
                        }
                    }
                } else {
                    printf("\n No hay datos disponibles...\n");
                }
                break;
                // Busqueda
            case 4:
                if (size > -1) {
                    pass = 0;
                    printf("\n --- BrickBuster -> Busqueda ---");
                    printf("\n 1.- Busqueda General");
                    printf("\n 2.- Busqueda por Clave \n");
                    scanf("%i", &opcionMenu);

                    switch (opcionMenu) {
                        case 1:
                            printf("\n ---- Total de Peliculas: %i ----", (size + 1));
                            for (int k = 0; k < size + 1; k++) {
                                printf("\n --- Pelicula: %i ---", clave[k]);
                                printf("\n Titulo: %s", titulo[k]);
                                printf("\n Director: %s", director[k]);
                                printf("\n Duracion: %i Minutos", duracion[k]);
                                printf("\n Año de lanzamiento: %i", ano[k]);
                                printf("\n Genero: %s", genero[k]);
                                printf("\n Cantidad en el Inventario: %i", cantidadInventario[k]);
                                printf("\n Hay renta (1 si, 0 no): %i \n", esRenta[k]);
                            }
                            break;
                        case 2:
                            do {
                                printf("\n --- BrickBuster -> Busqueda -> Busqueda por Clave ---");
                                printf("\n Ingrese la clave de la pelicula: ");
                                scanf("%i", &claveTemporal);

                                while (aux / 10 > 0) {
                                    aux = aux / 10;
                                    contador++;
                                }
                                if (clave[size] < 0 || contador > 5) {
                                    pass = 1;
                                    printf("\nLa clave ingresada es negativa o mayor a 5 digitos... Ingrese de nuevo los datos.");
                                    break;
                                }

                                for (int i = 0; i < size + 1; i++) {
                                    if (claveTemporal == clave[i]) {
                                        pass = 0;
                                        break;
                                    } else {
                                        pass = 1;
                                        if (i == size) {
                                            printf("\n No existe la clave... \n");
                                        }
                                    }
                                }
                                while (getchar() != '\n') {};
                            } while (pass);
                            for (int k = 0; k < size + 1; k++) {
                                if (claveTemporal == clave[k]) {
                                    printf("\n --- Pelicula: %i ---", clave[k]);
                                    printf("\n Titulo: %s", titulo[k]);
                                    printf("\n Director: %s", director[k]);
                                    printf("\n Duracion: %i Minutos", duracion[k]);
                                    printf("\n Año de lanzamiento: %i", ano[k]);
                                    printf("\n Genero: %s", genero[k]);
                                    printf("\n Cantidad en el Inventario: %i", cantidadInventario[k]);
                                    printf("\n Hay renta (1 si, 0 no): %i \n", esRenta[k]);
                                    break;
                                } else if (k == size) {
                                    printf("\n No se encontro coincidencias...");
                                }
                            }
                    }
                } else {
                    printf("\n No hay datos disponibles...\n");
                }
                break;
                // Rentas
            case 5:
                if (size > -1) {
                    int anteriorCantidad = 0;
                    int posCantidad = 0;
                    int peliculasRentadas = 0;
                    int peliculasRentadasAcum = 0;
                    int claveRentTemp = 0;
                    int cantidadTotal = 0;
                    int mostradas = 0;
                    int rentasAcum = 0;
                    int cantidadPrevia = 0;
                    int posLast = 0;
                    pass = 0;
                    int cantidades[100];

                    printf("\n  --- BrickBuster -> Rentas ---");
                    printf("\n Peliculas disponibles: ");
                    for (int i = 0; i < size + 1; ++i) {
                        cantidades[i] = cantidadInventario[i];
                        if (esRenta[i] == 1) {
                            printf("\n --- Pelicula: %i (Clave) - Copias: %i ---", clave[i], cantidadInventario[i]);
                            printf("\n Titulo: %s", titulo[i]);
                            printf("\n Director: %s", director[i]);
                            printf("\n Duracion: %i Minutos", duracion[i]);
                            printf("\n Año de lanzamiento: %i", ano[i]);
                            printf("\n Genero: %s", genero[i]);
                            printf("\n Cantidad en el Inventario: %i", cantidadInventario[i]);
                            cantidadTotal = cantidadInventario[i];
                            mostradas++;
                        }
                    }
                    if (mostradas > 0) {
                        do {
                            pass = 0;
                            printf("\n Ingrese la clave de la pelicula que desea rentar: ");
                            scanf("%i", &claveTemporal);

                            for (int i = 0; i < size + 1; ++i) {
                                if (claveTemporal == clave[i]) {
                                    posCantidad = i;
                                    if (cantidadInventario[i] <= 0) {
                                        esRenta[i] = 0;
                                        cantidadInventario[i] = 0;
                                        printf("\n No hay mas en el inventario... \n");
                                    } else {
                                        do {
                                            pass = 0;
                                            printf("\n\n Cuantas copias desea? (Se encuentran %i copias): ",
                                                   cantidadInventario[i]);
                                            scanf("%i", &peliculasRentadas);

                                            if (peliculasRentadas > 0 && peliculasRentadas <= cantidadInventario[i]) {
                                                estaRentado[i] = 1;
                                                claveRenta[pointerRentas] = sizeRentas + 1;
                                                claveRentTemp = claveRenta[pointerRentas];

                                                clavePelicula[pointerRentas] = clave[i];
                                                claveCopias[pointerRentas] = peliculasRentadas;


                                                cantidadInventario[i] = cantidadInventario[i] - peliculasRentadas;
                                                peliculasRentadasAcum = peliculasRentadasAcum + peliculasRentadas;
                                                pointerRentas = pointerRentas + 1;
                                                rentasTotal++;
                                                rentasAcum = rentasTotal;
                                                posLast = i;
                                                if (cantidadInventario[i] == 0) {
                                                    esRenta[i] = 0;
                                                }
                                                printf(" \n Se ha completado la renta de %s con exito.", titulo[i]);
                                                pass = 0;
                                                break;
                                            } else {
                                                if (peliculasRentadas <= 0) {
                                                    printf("\n Tiene que ingresarse una cantidad superior a cero... ");
                                                } else {
                                                    printf("\n No hay copias suficientes...\n");
                                                }
                                                pass = 1;
                                            }
                                        } while (pass);
                                    }
                                    break;
                                } else {
                                    pass = 1;
                                }
                            }
                            if (pass) {
                                printf("\n Clave no existente... Vuelva a ingresar.");
                            } else {
                                printf("\n Desea rentar alguna otra pelicula? :");
                                printf("\n 1.- Si \n 2.- No, pasar a pagar. \n");
                                scanf("%i", &opcionMenu);

                                if (opcionMenu == 1) {
                                    pass = 1;
                                    anteriorCantidad = cantidadInventario[posLast];
                                } else if (opcionMenu != 2) {
                                    printf("\n Opcion no valida.");
                                    pass = 1;
                                }
                            }
                        } while (pass);
                        printf("\n El total a pagar es: $%i pesos... \n ENTER para confirmar...",
                               peliculasRentadasAcum * 50);
                        while (getchar() != '\n') {};
                        while (getchar() != '\n') {};
                        printf("\n Se ha completado el pago con exito. \n");
                        sizeRentas++;
                        /*
                        //scanf("%i", &claveTemporal);
                        if (claveTemporal != 1) {
                            peliculasRentadasAcum = 0;
                            pointerRentas--;
                            rentasTotal = rentasTotal - rentasAcum;
                            cantidadInventario[posCantidad] = cantidades[posCantidad];
                            //cantidadInventario[posCantidad] = anteriorCantidad;
                            esRenta[posCantidad] = 1;
                            printf("\n No se pudo completar la ultima renta... \n");
                        } else {

                        }*/
                    } else {
                        printf("\n No hay peliculas en el inventario \n");
                    }
                } else {
                    printf("\n No hay datos disponibles...\n");
                }
                break;
                // Premios de la Academia
            case 6:
                if (rentasTotal > 0) {
                    int contador = 0;
                    int primero = 0, segundo = 0, tercero = 0, cuarto = 0, quinto = 0;
                    int primeroPos = 0, segundoPos = 0, terceroPos = 0, cuartoPos = 0, quintoPos = 0;

                    //1
                    if (rentasTotal >= 1) {
                        for (int l = 0; l < rentasTotal; l++) {
                            if (primero < claveCopias[l]) {
                                primero = claveCopias[l];
                                primeroPos = l;
                            }
                        }
                        printf(" --- Premios de la Academia. ---\n");
                        printf("\n --- 1er Lugar ---");
                        printf("\n Clave renta: %i", claveRenta[primeroPos]);
                        printf("\n Clave pelicula: %i", clavePelicula[primeroPos]);
                        printf("\n Copias rentadas: %i", claveCopias[primeroPos]);
                        printf("\n Se pago: %i \n", claveCopias[primeroPos] * 50);
                    }
                    //2
                    if (rentasTotal >= 2) {
                        for (int m = 0; m < rentasTotal; m++) {
                            if (segundo < claveCopias[m]) {
                                if (primero == claveCopias[m]) {
                                } else {
                                    segundo = claveCopias[m];
                                    segundoPos = m;
                                }
                            }
                        }
                        printf("\n --- 2do Lugar ---");
                        printf("\n Clave renta: %i", claveRenta[segundoPos]);
                        printf("\n Clave pelicula: %i", clavePelicula[segundoPos]);
                        printf("\n Copias rentadas: %i\n", claveCopias[segundoPos]);
                        printf("\n Se pago: %i \n", claveCopias[segundoPos] * 50);
                    }
                    //3
                    if (rentasTotal >= 3) {
                        for (int m = 0; m < rentasTotal; m++) {
                            if (tercero < claveCopias[m]) {
                                if (primero == claveCopias[m]) {
                                } else if (segundo == claveCopias[m]) {
                                } else {
                                    tercero = claveCopias[m];
                                    terceroPos = m;
                                }
                            }
                        }
                        printf("\n --- 3er Lugar ---");
                        printf("\n Clave renta: %i", claveRenta[cuartoPos]);
                        printf("\n Clave pelicula: %i", clavePelicula[cuartoPos]);
                        printf("\n Copias rentadas: %i\n", claveCopias[cuartoPos]);
                        printf("\n Se pago: %i \n", claveCopias[terceroPos] * 50);
                    }
                    //4
                    if (rentasTotal >= 4) {
                        for (int m = 0; m < rentasTotal; m++) {
                            if (tercero < claveCopias[m]) {
                                if (primero == claveCopias[m]) {
                                } else if (segundo == claveCopias[m]) {
                                } else if (tercero == claveCopias[m]) {
                                } else {
                                    cuarto = claveCopias[m];
                                    cuartoPos = m;
                                }
                            }
                        }
                        printf("\n --- 4to Lugar ---");
                        printf("\n Clave renta: %i", claveRenta[cuartoPos]);
                        printf("\n Clave pelicula: %i", clavePelicula[cuartoPos]);
                        printf("\n Copias rentadas: %i\n", claveCopias[cuartoPos]);
                        printf("\n Se pago: %i \n", claveCopias[cuartoPos] * 50);
                    }
                    //5
                    if (rentasTotal >= 5) {
                        for (int m = 0; m < rentasTotal; m++) {
                            if (tercero < claveCopias[m]) {
                                if (primero == claveCopias[m]) {
                                } else if (segundo == claveCopias[m]) {
                                } else if (tercero == claveCopias[m]) {
                                } else if (cuarto == claveCopias[m]) {
                                } else {
                                    quinto = claveCopias[m];
                                    quintoPos = m;
                                }
                            }
                        }
                        printf("\n --- 5to Lugar ---");
                        printf("\n Clave renta: %i", claveRenta[quintoPos]);
                        printf("\n Clave pelicula: %i", clavePelicula[quintoPos]);
                        printf("\n Copias rentadas: %i\n\n", claveCopias[quintoPos]);
                        printf("\n Se pago: %i \n", claveCopias[quintoPos] * 50);
                    }
                } else {
                    printf("\n No hay datos disponibles...\n");
                }
                break;
            case 7:
                break;
            default:
                printf("Caracter no permitido, vuelva a intentarlo");
                break;
        }
    } while (opcionMenu != 7);

    return 0;
}
