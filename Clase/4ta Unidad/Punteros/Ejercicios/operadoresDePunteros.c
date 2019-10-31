#include <stdio.h>

int main() {
    int *p, q, y;
    q = 100;
    p = &q;
    printf("%d", *p);
    y = *p + 3;

    return 0;
}