/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** error_handling
*/

#include "my.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

int parse_args(int ac, char * const *av, structure_t *flags)
{
    if (av[1][0] == '-' && av[1][1] == 'n')
        flags->flag_n = true;
    if (av[1][0] == '-' && av[1][1] == 'p')
        flags->flag_p = true;
    if (ac > 3 && is_number(av[4]) && strcmp(av[3], "-b") == 0)
        flags->base = atoi(av[4]);
    if (ac == 7 && strcmp(av[5], "-imin") == 0 && is_number(av[6]))
        flags->imin = atoi(av[6]);
    if (ac == 7 && strcmp(av[5], "-imax") == 0 && is_number(av[6]))
        flags->imax = atoi(av[6]);
    return 0;
}

int error_handling(int ac, char **av)
{
    if (ac == 4)
        return 84;
    if (ac == 2 && (av[1][0] != '-' || av[1][1] != 'h'))
        return 84;
    if (ac > 2 && ac <= 6 && (av[1][0] != '-' ||
        (av[1][1] != 'n' && av[1][1] != 'p')))
        return 84;
    if (ac >= 5 && (!is_number(av[2]) || !is_number(av[4])))
        return 84;
    if (ac == 6)
        return 84;
    if (ac == 7 && (strcmp(av[5], "-imax") != 0 && strcmp(av[5], "-imin")))
        return 84;
    if (ac == 7 && !is_number(av[6]))
        return 84;
    return 0;
}
