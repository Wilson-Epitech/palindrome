/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** convert_base
*/

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int size_to_malloc(int number, int base)
{
    static int size = 0;

    if (number > base - 1) {
        size_to_malloc(number / base, base);
        size_to_malloc(number % base, base);
    }
    if (number <= base - 1)
        size += 1;
    return size;
}

static char *convert_base_rec(int number, int base, char *str)
{
    if (number > base - 1) {
        convert_base_rec(number / base, base, str);
        convert_base_rec(number % base, base, str);
    }
    if (number <= base - 1) {
        char *nb_str = my_int_to_str(number);
        strcat(str, nb_str);
        free(nb_str);
    }
    return str;
}

char *convert_base(int number, int base)
{
    int size = size_to_malloc(number, base);
    char *str = NULL;

    if (base < 2 || base > 10)
        return NULL;
    str = malloc(sizeof(char) * size + 1);
    *str = '\0';
    str = convert_base_rec(number, base, str);
    return str;
}
