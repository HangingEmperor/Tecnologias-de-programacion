#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int main()
{
    setlocale(LC_ALL, "");
    int result;
    int resultNumber;

    wchar_t string1[] = L"áabcdefg";
    wchar_t string2[] = L"abcdefg";
    wchar_t string3[] = L"23023023";
    wchar_t string4[] = L"59";
    wchar_t string5[] = L"1";
    wchar_t s[2];
    wchar_t string[10];

    s[0] = string4[0];
    s[1] = string5[0];
    s[2] = string3[0];

    int x;

    x = iswdigit(string5[10]);
    printf("%i", x);

    //wprintf(s);

    // wscanf(L"%l[^\n]", string);
    // wprintf(string);
    // printf("%i", resultNumber);
}