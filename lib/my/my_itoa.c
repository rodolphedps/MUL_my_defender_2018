/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** my_itoa
*/

#include "../../include/my.h"
#include <stdbool.h>

int getnbrlen(int nbr)
{
    int i = 0;

    if (nbr < 0) {
        nbr *= -1;
        i++;
    }
    while (nbr > 0) {
        nbr /= 10;
        i++;
    }
    return (i);
}

char *check_neg(bool neg, char *str, int i)
{

    if (neg == 1) {
        str[i] = '-';
        str[i + 1] = '\0';
    }
    else
        str[i] = '\0';
    return (my_revstr(str));
}

char *  my_itoa(int nbr)
{
    char *str = malloc(sizeof(char) * (getnbrlen(nbr) + 1));
    int save = 0;
    int i = 0;
    bool negative = 0;

    if (nbr < 0) {
        negative = 1;
        nbr *= -1;
    }
    while (nbr > 0) {
        save = nbr % 10;
        str[i] = save + '0';
        i++;
        nbr /= 10;
    }
    str = check_neg(negative, str, i);
    return (str);
}