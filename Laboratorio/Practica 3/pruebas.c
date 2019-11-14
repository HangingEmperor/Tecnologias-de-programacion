#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    //srand (getpid());
    srand(time(NULL));
    int numero, x, y, z;
    char xd[10];
    numero = rand() % (2) + 1;
    x = rand() % (2) + 1;
    y = rand() % (2) + 1;
    z = rand() % (2) + 1;


    printf("%i, %i, %i, %i", numero, x, y, z);

    return 0;
}