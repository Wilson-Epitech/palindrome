/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** main
*/

#include <stdio.h>

int error_handling(int ac, char **av)
{
    if (ac == 2 && (av[1][0] != '-' || av[1][1] != 'h'))
        return 84;
    if (ac > 2 && ac <= 6 && (av[1][0] != '-' ||
        (av[1][1] != 'n' && av[1][1] != 'p')))
        return 84;
    return 0;
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

int main(int ac, char **av)
{
    if (ac == 1 || ac > 6)
        return 84;
    if (error_handling(ac, av) == 84)
        return 84;
    if (flag_h(ac, av) == 1)
        return 0;
    printf("ok\n");
    return 0;
}
