/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** lib
*/

#include <stdbool.h>

#ifndef LIB_H_
    #define LIB_H_

    bool is_delim(char c, char *separators);
    char **my_word_array_delim(char const *str, char *separators);

#endif /* !LIB_H_ */
