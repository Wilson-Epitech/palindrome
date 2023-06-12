/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** is_palindrome
*/

#include <string.h>
#include <stdbool.h>

bool is_palindrome(const char* str)
{
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return true;
        }
    }
    return false;
}
