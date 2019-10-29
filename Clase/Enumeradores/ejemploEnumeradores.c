#include <stdio.h>
#include <ctype.h>

enum boolean {
    false,
    true
};

enum boolean vocal(char c);

int main() {
    char car;
    int numVocal = 0;
    printf("Introduce un texto: ");

    while ((car = getchar()) != '\n') {
        if (vocal(car))
            numVocal++;
    }

    printf("Total de vocales leidos: %i \n", numVocal);

    return 0;
}

enum boolean vocal(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}
