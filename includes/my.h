/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** my
*/

#include <stdbool.h>

#ifndef MY_H_
    #define MY_H_

typedef struct structure_s {
    bool flag_n;
    bool flag_p;
    int base;
    int imin;
    int imax;
} structure_t;

    int error_handling(int ac, char **av);
    int parse_args(int ac, char * const *av, structure_t *flags);
    char *convert_base(int number, int base);
    bool is_palindrome(const char* str);
    int find_first_palindrome(char *nb_str, structure_t *flags);
    void palindromic_correspondances(char *nb_str, structure_t *flags);

#endif /* !MY_H_ */
