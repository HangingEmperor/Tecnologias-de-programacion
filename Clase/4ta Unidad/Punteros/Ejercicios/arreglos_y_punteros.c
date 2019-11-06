#include <stdio.h>

int main() {
    int a[10], x;
    int *ap;
    ap = &a[0];
    x = *ap;
    *(ap + 1) = 100;

    printf("%i", x);

    return 0;
}