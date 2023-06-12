/*
** PALINDROME PROJECT, 2022
** day06
** File description:
** task3
*/

#include <string.h>

char *my_revstr(char *str)
{
    int i, j;
    char temp;

    j = strlen(str) - 1;
    for (i = 0; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}
