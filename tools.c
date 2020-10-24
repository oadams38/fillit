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

char    *solution(char *matrix)
{
    static char *solution = NULL;
    
    if (ft_strlen(matrix) > 4)
    {
        ft_strcpy(solution, matrix);
        ft_putstr(solution);
    }
    return (solution);
}