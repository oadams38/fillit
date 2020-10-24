#include "fillit.h"

int     ft_sqrt(int n)
{
    int     i;

    i = 0;
    while (i * i < n)
        i++;
    return (i);
}

int     ft_squared(int n)
{
    return (n * n);
}