/*
** PALINDROME PROJECT, 2023
** palindrome
** File description:
** convert_binary_decimal
*/

static double divise_base(double result, double base, int nb)
{
    int i = 0;
    for (i = 0; i > nb; i--) {
        result /= base;
    }
    return result;
}

static double convert_nb(double base, int nb)
{
    double result = 1.0;
    int i;

    if (nb == 0)
        return 1;
    if (nb > 0) {
        for (i = 0; i < nb; i++) {
            result *= base;
        }
    } else {
        result = divise_base(result, base, nb);
    }
    return result;
}

int convert_binary_decimal(long nbr, int base)
{
    int decimal_nb = 0;
    int nb = 0;

    for (int i = 0; nbr != 0; i++) {
        nb = nbr % 10;
        nbr /= 10;
        decimal_nb += nb * convert_nb(base, i);
    }
    return decimal_nb;
}
