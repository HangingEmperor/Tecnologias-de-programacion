#Sintaxis
```C
tipo *nombreVariable;
```
**tipo**: es el tipo base y especifica el tipo de objeto al que puede apuntar el puntero.

*: Indica al compilador que se esta creando un puntero;

#Ejemplos:
```C
int *ptr1; // Apuntador de tipo entero
char *cad1; // Apuntador a dato tipo caracter (char)
int *countPtr, count;
```

#Inicializacion de Punteros
Un apuntador puede ser inicializado a 0, NULL o a una direccion.
```C
int *punt1=0;
float *punt2=NULL;
int *puntero=0xbfc5b1c8;
```

Un apuntador con el valor NULL apunta a nada. NULL es una constante simbolica, definida en el archivo de cabecera _<stdio.h>_.

Inicializar un apuntador a 0 es equialente a inicializar el apuntador a NULL, pero es preferible NULL.

El valor 0 es el unico valor entero que puede ser directamente asignado a una variable de apuntador.

#Operadores de Punteros
El & u operador de direccion, es un operador unario que regresa la direccion de su operando. Por ejemplo, suponiendo las declaraciones:
```C
int y = 5;
int *yPtr, *x;
```

El enunciado
```C
yPtr = &y;
x = yPtr;
```
asigna la direccion de la variable _y_ a la variable de apuntador _yPtr_. La variable _yPtr_ se dice entonces que _**"Apunta a y"**_.
