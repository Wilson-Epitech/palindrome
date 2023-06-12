/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** requirement
*/

#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    if (nb == 0 || nb == 1)
        return 1;
    if (nb < 0 || nb > 12)
        return 0;
    return (nb * my_factrec_synthesis(nb - 1));
}

int my_squareroot_synthesis(int nb)
{
    int x = nb;
    float y = 1;

    if (nb < 0)
        return -1;
    while (x - y > 0) {
        x = (x + y) / 2;
        y = nb / x;
    }
    return x;
}
