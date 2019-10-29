struct fecha {
    int dia;
    int mes;
    int anio;
};

struct alumno {
    int matricula;
    struct fecha nacimiento;
    char nombre[50];
    char carrera[50];
    struct fecha egreso;
    float promedio;
    char titulado;
    struct fecha titulacion;
};

int main() {
    struct alumno x[100];
    x[0].matricula = 2;
    x[0].nacimiento.dia = 18;

    return 0;
}
