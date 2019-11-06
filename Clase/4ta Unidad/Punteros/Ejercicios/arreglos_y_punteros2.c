#include <stdio.h>

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ap;
    ap = a;

    printf("%d %d %d \n", *ap, *(ap + 1), *(ap + 2));
    /* Lo mismo de otra forma... */
    printf("%d %d %d \n", a[0], a[1], a[2]);
}