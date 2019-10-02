/*
agenda electronica, hay que realizarla
numero de telefono
correo electronico
nombre
el programa almacena en vectores, arreglo para
nombree, correeo,
las opciones son dar de alta, ingresar nuevos contactos
dar de baja de contacto en nuestra agenda, la forma
de verificar es por el numero de telefono
otra funcion, consultar toda la informacion de la
agenda electronica y salir
los parametros recibira por fuera, en la linea de comandos
todos los datos ingresados se recibiran como string

name[20][5']
llenar(noombre)

void llenar(char n[][50])
*/
#include <stdio.h>

void alta();

void baja();

void mostrar();

void salir();

/* Agenda electronica */
int main(int argc, char *argv[]) {
    char names[20][50];
    char email[20][50];
    char phone[20][50];
    int size = 0;
    int i;

    printf(" 1.- Dar de alta \n");
    printf(" 2.- Dar de baja \n");
    printf(" 3.- Ver datos \n");
    printf(" 4.- Salir \n");
    int op;
    scanf("%i", &op);

    switch (op) {
        /* Dar de alta */
        case 1:
            break;
            /* Dar de baja */
        case 2:
            break;
            /* Ver datos */
        case 3:
            break;
            /* Salir */
        case 4:
            salir();
            break;
        default:
            salir();
            break;
    }
    return 0;
}

void alta() {

}

void baja() {

}

void mostrar() {

}

void salir() {

}