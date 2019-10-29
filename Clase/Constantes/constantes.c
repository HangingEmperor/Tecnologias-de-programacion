/*
	Constantes:
		- Literales
		- Definidas
		- Declaradas
		- Enumeraciones
*/

/* Constantes Definidas */
#define nombre valor
#define PI 3.1416
#define arroba '@'
#define tope 1000;

/* Constantes Declaradas*/
const [tipo]
nombre = valor;
const int TOPE = 100;
const float PI = 3.1416;

/* Constantes Enumeradas*/
enum nombre {
    enumerador, enumerador2, ..., enumerador
};

enum {
    ROJO, VERDE, AZUL
};
/* Si solo los dejo asi hara:
	const int ROJO = 0;
	const int VERDE = 1;
	const int AZUL = 2;
*/

enum lucesTrafico {
    ROJO, AMARILLO = 10, VERDE
};

enum dias_semana {
    LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
};

enum dias-semana,
dia;
for (
dia = LUNES;
dia <=
DOMINGO;
dia++){
printf("%d", dia);
}

enum Interruptor {
    ENCENDIDO,
    APAGADO
};

enum Boolean {
    FALSE,
    TRUE
};














