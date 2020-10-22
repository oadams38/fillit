#include "fillit.h"

int     sqrt(int n)
{
    int     i;

    i = 0;
    while (i * i < n)
        i++;
    return (i);
}

int     squared(int n)
{
    return (n * n);
}

char    *solution(char *matrix)
{
    static char *solution = NULL;
    
    if (ft_strlen(matrix) > 4)
        solution = ft_strcpy(solution, matrix);
    return (solution);
}