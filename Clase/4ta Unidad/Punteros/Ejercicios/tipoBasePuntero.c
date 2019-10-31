#include <stdio.h>

int main() {
    int q = 5;
    float *fp;
    fp = &q;
    printf("%p", fp);
    /* Que hace esta linea? */
    *fp = 100.23;
}