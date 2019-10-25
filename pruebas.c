#include <stdio.h>

int main() {
    char tablero[12][12];

    for (int x = 0; x < 12; x++)
        for (int y = 0; y < 12; y++)
            tablero[x][y] = '*';

    printf("    ");
    for (char abecedario = 'A'; abecedario <= 'L'; abecedario++)
        printf("%c  ", abecedario);

    for (int i = 0; i < 12; i++) {
        if (i > 8)
            printf("\n%i  ", i + 1);
        else
            printf("\n%i   ", i + 1);

        for (int j = 0; j < 12; j++)
            printf("%c  ", tablero[j][i]);
    }
    printf("\n");

    return 0;
}