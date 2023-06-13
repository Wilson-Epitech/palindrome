/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** find_first_palindrome
*/

#include "lib.h"
#include "my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int convert_loop(structure_t *flags, int nb)
{
    if (flags->base == 2)
        nb = convert_binary_decimal(nb, 2);
    if (flags->base == 5)
        nb = convert_binary_decimal(nb, 5);
    return nb;
}

int find_first_palindrome(char *nb_str, structure_t *flags)
{
    int solution_found = 0; int palindrome = 1;
    int initial_nb = atoi(nb_str); int nb = atoi(nb_str);
    int iterations = 0; char *reverse_nb_str = NULL;

    nb_str = convert_base(nb, flags->base);
    while (palindrome == 1) {
        palindrome = is_palindrome(nb_str);
        if (iterations > flags->imax)
            break;
        if (palindrome == 0 && iterations >= flags->imin
            && iterations <= flags->imax) {
            nb = convert_loop(flags, nb);
            printf("%d leads to %d in %d iteration(s) in base %d\n",
            initial_nb, nb, iterations, flags->base);
            solution_found += 1;
            break;
        }
        iterations += 1; reverse_nb_str = my_revstr(strdup(nb_str));
        nb = atoi(nb_str) + atoi(reverse_nb_str); nb_str = my_int_to_str(nb);
    } return solution_found;
}
