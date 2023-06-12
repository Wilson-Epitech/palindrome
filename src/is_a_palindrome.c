/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** is_a_palindrome
*/

#include <string.h>

int is_a_palindrome(char const *str)
{
    int len_max = strlen(str) - 1;
    int stop = strlen(str) / 2;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i >= stop)
            return (0);
        if (str[i] != str[len_max])
            return (1);
        len_max -= 1;
    }
    return 0;
}
