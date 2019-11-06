# Punteros

## Sintaxis

``` C
tipo *nombreVariable;
```

**tipo**: es el tipo base y especifica el tipo de objeto al que puede apuntar el puntero.

*: Indica al compilador que se esta creando un puntero; 

## Ejemplos:

``` C
int *ptr1; // Apuntador de tipo entero
char *cad1; // Apuntador a dato tipo caracter (char)
int *countPtr, count;
```

## Inicializacion de Punteros

Un apuntador puede ser inicializado a 0, NULL o a una direccion.

``` C
int *punt1 = 0;
float *punt2 = NULL;
int *puntero = 0xbfc5b1c8; 
```

Un apuntador con el valor NULL apunta a nada. NULL es una constante simbolica, definida en el archivo de cabecera _<stdio.h>_.

Inicializar un apuntador a 0 es equialente a inicializar el apuntador a NULL, pero es preferible NULL.

El valor 0 es el unico valor entero que puede ser directamente asignado a una variable de apuntador.

## Operadores de Punteros

El & u operador de direccion, es un operador unario que regresa la direccion de su operando. Por ejemplo, suponiendo las declaraciones:

``` C
int y = 5;
int *yPtr, *x;
```

El enunciado:

``` C
yPtr = &y;
x = yPtr;
```

asigna la direccion de la variable _y_ a la variable de apuntador _yPtr_. La variable _yPtr_ se dice entonces que _**"Apunta a y"**_.

## Operadores de Punteros

El operador de ***"indireccion"*** (o de disreferencia) representado por el asterisco, devuelve el valor almacenado en el apuntador que procede.

Cuando el valor de una variable se referencia a traves de un puntero, al proceso se le llama indireccion.

*Ejemplo 1:*

``` c
#include <stdio.h>
int main(){
    int *p, q, y;
    q = 100;
    p = &q;
    printf("%d", *p);
    y = *p + 3;
}
```

*Ejemplo 2:*

``` c
#include <stdio.h>
int main(){
    int x = 7;
    int *px = &x;

    printf("El valor de x es %d y su direccion es %p", x, &x);
    printf("El valor del puntero de x es %p y su direccion es %p", px, &px);

    return 0;
}
```

## Tipo base de un Puntero

El tipo base de un puntero, es muy importante. Aunque X permite que cualquier puntero apunte a cualquier lugar de memoria, el tipo base es lo que determina como se tratara al objeto apuntado.

En general, el compilador de C utiliza el tipo base para determinar cuantos bytes hay en el objeto que apunta el puntero.

Ejemplo:

``` c
#include <stdio.h>
int main(){
    int q;
    float *fp;
    fp = &q;
    /* Que hace esta linea? */
     *fp = 100.23;
}
```

## Direcciones Invalidas

Normalmente, un apuntador inicializado adecuadamente apunta a alguna posicion especifica de la memoria.

Sin embargo, algunas veces es posible que un apuntador no contenga una direccion valida, en cuyo aso es incorrecto desreferenciarlo (obtener el valor al que apunta) porque el programa tendra un comportamiento impredecible y probablemente erroneo, aunque es posible que funcione bien.

Despues de que un apuntador ha sido incializado, la direccion que posee puede dejar de ser valida si se libera la memori reservada en esa direccion, ya sea porque la variable asociada termina su ambito o porque ese espacio de memoria fue reservado dinamicamente y luego se libero.

* Si se intenta disreferenciar un apuntador que contiene una direccion invalida pueden ocurrir cosas como las siguientes: Se obtiene un valor incorrecto en una o mas variables debido a que no fue debidamente inicializado.

* Si casualmente la direccion es la misma de otra variable utilizada en el programa, o esta dentro del rango de direcciones de una zona de memoria utilizada, existe el riesgo de sobreescribir datos de otras variables.

Existe la posibilidad de que la direccion este fuera de la zona de memoria utilizada para almacenar datos y mas bien este, por ejemplo, en la zona donde se almacenan las instrucciones del programa. Al intentar escribir en dicha zona, facilmente puede ocurrir que el programa genere un error de ejecucion y el sistema operativo lo detenga, o que el programa no responda y deje al sistema operativo inestable.

## Aritmetica de Punteros

Ademas de los operadores *& y *, solamente hay otros 4 operadores que se pueden utilizar con variable de tipos apuntador.

Los tipos aritmeticos son **+, ++, - , --**.

Solamente se pueden sumar o restar cantidades enteras, esto es, no se pueden sumar por ejemplo valores flotantes a un puntero. La aritmetica del puntero difiere de aritmetica normal en que se hace en relacion al tipo base del puntero. Cada vez que se incremente un puntero, apunta al siguiente elemento atendiendo a su tipo base.

Supongamos que ha sido declarado un arreglo *int v[10]* y su primer elemento esta en memoria en la posicion 3000.

Suponga que el apuntador vPtr ha sido inicializado para apuntar a *v[0]*, es decir, el valor de vPtr es 3000. Supongamos que la situacion para una maquina con enteros de 4 bytes.

``` c
int v[10];
int *vPtr;

vPtr = v;
vPtr = &v[0];
```

En aritmetica convencional, la adicion *3000 + 2* da como resultado el valor 3002.

Este no es el caso en la aritmetica de punteros. Cuando se añade o se resta un entero de un apuntador, el apuntador no se incremente o decrementa solo por el valor de dicho entero, sino por el entero, multiplicado por el tamaño en bytes.

Por ejemplo, el enunciado:

``` c
vPtr += 2; 
```

produciria 3008 *(3000 + 2 * 4)*, suponiendo un entero almacenado en 4 bytes de memoria, el arreglo *v*, *vPtr*, ahora apunta a v[2].

Si un entero se almacena en dos bytes de memoria, entonces el calculo anterior resultaria en una posicion de memoria 3004 *(3000 + 2x2)*.

Si el arreglo fuera de un tipo de datos diferente, el enunciado precedente incrementaria el apuntador por dos veces el numero de bytes que toma para almacenar un objeto.

Si *vPtr* ha sido incrementado a 3016, apuntado a *v[4]* el enunciado:

``` c
vPtr -=4;
```

definiria a *vPtr* de vuelta a 3000, esto solo es el inicio del puntero.

## Arreglos y Punteros

Existe una relacion estrecha entre los punteros y los arreglos.

En C, un nombre de un arreglo es un indice a la direccion  de comienzo del arreglo. En esencia, el nombre de un arreglo es un puntero al arreglo.

Ejemplo:

``` c
int a[10], x; 
int *ap; 
ap = &a[0]; 
x = *ap; 
*(ap + 1) = 100; 
```

Como se puede observar la setencia a[t] es identica a ap + t.

Se debe tener cuidado ya que C no hace una revision de los limites del arreglo, por lo que se puede ir facilmente mas alla del arreglo en memoria y sobreescribir otras cosas.

El nombre de un arreglo es un puntero al principio del arreglo, por lo tanto es razonable que se pueda asignar ese valor a otro puntero y que se acceda al arreglo utilizando aritmetica de punteros.

Ejemplo:

``` c
#include <stdio.h>

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int *ap;
    ap = a;

    printf("%d %d %d \n", *ap, *(ap + 1), *(ap + 2));
    /* Lo mismo de otra forma... */
    printf("%d %d %d \n", a[0], a[1], a[2]);
}
```

C es mucho mas sutil en su relacion entre arreglos y apuntadores. Por ejemplo se puede teclear solamente: 

``` c
ap = a; en vez de ap = &a[0];
y tambien
*(a + i) en vez de a[i], esto es, &a[i] es equivalente con a + i;
```

por lo tanto, el direccionamiento de apuntadores se puede expresar como:
a[i] que es equivalente a *(ap + i)

Sin embargo los apuntadores y los arreglos son diferentes:

* Un apuntador es una variable: Se puede hacer ap = a y ap++
* Un arreglo NO ES una variable: Hacer a = ap y a++, ES ILEGAL.

## Estructuras y punteros

Ejemplo:

``` c
struct Dato {
    int campo1;
    int campo2;
    char campo3[30];
};

struct Dato x;
struct Dato *ptr;

ptr = &x;
ptr -> campo1 = 33;
strcpy(ptr->campo3, "hola");
```

## Memoria Dinamica

Las variables y vectores en C ocupan un tamaño prefijado, no pueden modificarse durante la ejecucion del programa.

Por medio de punteros, podemos reservar o liberar memoria dinamicamente, es decir, segun se necesite. Para ello existen varias funciones estandares, de la biblioteca <stdlib.h>.

La funcion malloc sirve para solicitar un bloque de memoria del tamaño suministrado como parametro.

La funcion malloc, devuelve un puntero a la zona de memoria asignada y utiliza la siguiente sintaxis:

``` c
void* malloc (unsigned numero_de_bytes);
```

El tamaño se especifica en Bytes. Se garantiza que la zona de memoria concebida no esta ocupada por ninguna otra variable ni otra zona devuelta por malloc.

Si malloc es incapaz de conceder el bloque, devuelve un puntero nulo.

### Punteros void*

La funcion malloc devuelve un puntero inespecifico, esto es, que no apunta a un topo de datos determinado. En C, estos punteros sin tipo se declaran como void*.

### Operador sizeof()

El problema de malloc es conocer cuantos bytes se quieren reservar. Si se quiere reservar una zona para diez enteros, habra que multiplicar diez por el tamaño de un entero.

El tamaño en bytes de un elemento de tipo T se obtiene con la instruccion: sizeof(T); 

### Funcion free()

Cuando una zona de memoria reservada con amlloc ya no se necesita, puede ser liberada mediante la funcion free que tiene la siguiente sintaxis:
void free(void* ptr); 

ptr es un puntero de cualquier tipo que apunta a un area de memoria reservada previamente con malloc.

Si ptr apunta a una zona de memoria indebida, los efectos pueden ser desastrosos.

Ejemplo:

``` c
/* Ejemplo para uso de malloc: generador de una cadena */
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n;
    char* cadena;
    printf("Cuantos caracteres quieres en la cadena?");
    scanf("%d", &i);
    cadena = (char *)malloc(i+1);
    if(cadena == NULL){
        exit(1);
    }

    for(n=0; n<i; n++){
        cadena[n]=rand()%26+'a';
        cadena[i]
    }
}
```

