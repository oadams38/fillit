#include "fillit.h"

void    print_solution(char *solution)
{
    int     side_size;
    int     matrix_size;
    char    *matrix_solution;
    char    *Pmatrix;
    int     i;

    side_size = sqrt(ft_strlen(solution));
    matrix_size = side_size * (side_size + 1) + 1;
    matrix_solution = ft_strnew(matrix_size);
    Pmatrix = matrix_solution;
    i = -1;
    while (solution[++i])
    {
        *Pmatrix++ = solution[i];
        if ((i + 1) % side_size == 0)
            *Pmatrix++ = '\n';
    }
    *Pmatrix = '\n';
    ft_putstr(matrix_solution);
}