#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    int result;
    int resultNumber;

    wchar_t string1[] = L"áabcdefg";
    wchar_t string2[] = L"abcdefg";
    wchar_t string3[] = L"1";
    wchar_t string[10];

    result = wcscmp(string1, string2);
    resultNumber = iswdigit(string3[0]);
    result = iswalpha(string1[0]);
    result = wcslen(string2);

    wscanf(L"%l[^\n]", string);
    wprintf(string);
    //printf("%i", resultNumber);
}