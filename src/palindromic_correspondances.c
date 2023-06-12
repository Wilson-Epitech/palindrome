/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** palindromic_correspondances
*/

#include "my.h"
#include "lib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

static int find_correspondance(char *nb_str, int palindromic_nb,
    int solution_found, structure_t *flags)
{
    int palindrome = 1; int initial_nb = atoi(nb_str);
    int nb = atoi(nb_str); int iterations = 0;
    char *reverse_nb_str = NULL;

    while (nb <= palindromic_nb) {
        palindrome = is_palindrome(nb_str);
        if (iterations > flags->imax)
            break;
        if (palindrome == 0 && nb == palindromic_nb && iterations >= flags->imin
            && iterations <= flags->imax) {
            printf("%d leads to %d in %d iteration(s) in base %d\n",
                initial_nb, nb, iterations, flags->base);
            solution_found += 1;
            break;
        }
        iterations += 1; reverse_nb_str = my_revstr(strdup(nb_str));
        nb = atoi(nb_str) + atoi(reverse_nb_str);
        nb_str = my_int_to_str(nb);
    }
    return solution_found;
}

void palindromic_correspondances(char *nb_str, structure_t *flags)
{
    static int solution_found = 0;
    int nb_pal = 1;

    while (nb_pal <= atoi(nb_str)) {
        solution_found = find_correspondance(convert_base(nb_pal, flags->base),
            atoi(nb_str), solution_found, flags);
        nb_pal += 1;
    }
    if (solution_found == 0)
        printf("no solution\n");
}
