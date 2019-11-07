#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x, y, z, total, cantidad = 7;
    x = ceil(cantidad * .2);
    y = ceil(cantidad * .3);
    z = ceil(cantidad * .4);

    total = x + y + z;
    if (total < cantidad) {
        z++;
    } else if (total > cantidad) {
        z--;
    }
    total = x + y + z;


    printf("%i", total);

    return 0;
}