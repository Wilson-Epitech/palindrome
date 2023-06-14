/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** main
*/

#include "my.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

structure_t *init_struct(void)
{
    structure_t *flags = malloc(sizeof(structure_t));
    flags->flag_n = false;
    flags->flag_p = false;
    flags->base = 10;
    flags->imin = 0;
    flags->imax = 100;
    return flags;
}

int flag_h(int ac, char **av)
{
    const char *str = "USAGE\n      ./palindrome -n number -p palindrome "
    "[-b base] [-imin i] [-imax i]\n\n"
    "DESCRIPTION\n      -n n       integer to be transformed (>=0)\n"
    "      -p pal     palindromic number to be obtained (incompatible"
    "with the -n\n"
    "                 option) (>=0)\n"
    "                 if defined, all fitting values of n will be output\n"
    "      -b base base in which the procedure will be executed (1<b<=10)"
    "[def: 10]\n"
    "      -imin i minimum number of iterations, included (>=0) [def: 0]\n"
    "      -imax i maximum number of iterations, included (>=0) [def: 100]";

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        printf("%s\n", str);
        return 1;
    }
    return 0;
}

int error_handling_2(int ac, char **av, structure_t *flags)
{
    if (flags->base > 10 || flags->base < 2)
        return 84;
    if (flags->imin >= flags->imax)
        return 84;
    if (flags->flag_p && is_palindrome(av[2]))
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    structure_t *flags = init_struct();
    if (ac == 1 || ac > 9)
        return 84;
    if (error_handling(ac, av) == 84) {
        printf("invalid argument\n");
        return 84;
    }
    if (flag_h(ac, av) == 1)
        return 0;
    parse_args(ac, av, flags);
    if (error_handling_2(ac, av, flags) == 84)
        return 84;
    if (flags->flag_n) {
        if (find_first_palindrome(av[2], flags) == 0)
            printf("no solution\n");
    } else
        palindromic_correspondances(av[2], flags);
    return 0;
}
