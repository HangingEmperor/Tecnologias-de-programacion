#include <stdio.h>
#include <string.h>

struct x {
    int ID;
    char nombre[50];
    float precio;
    int total;
};

union y {
    int ID;
    char nombre[50];
    float precio;
    int total;
};

int main() {
    union y equis;
    equis.ID = 10;
    equis.total = 120;

    printf("ID: %d\n", equis.ID);

    return 0;
}
