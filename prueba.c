#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

void al(wchar_t x[100]);

int main()
{
    setlocale(LC_ALL, "");
    int result;
    int resultNumber;

    wchar_t string1[100];

    string1[0] = 'l';
    printf("%c", string1[0]);
    al(string1);
    printf("%c", string1[0]);

    //wprintf(s);
    // wscanf(L"%l[^\n]", string);
    // wprintf(string);
    // printf("%i", resultNumber);
}

void al(wchar_t x[100]) {
    x[0] = 'x';
}