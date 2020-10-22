#include "libft.h"

void    importance_sort(char **tab)
{
    /*
    Run the basic program a few times and find which tetrimini seem to be or not be at first position
    */    
}

void    solve_and_print(char *data)
{
    char    **tab;
    int     nb_tetr;
    char    *matrix;
    int     mtrx_size;

    tab = ft_strsplit(data, '\n');
    nb_tetr = -1;
    while (tab[++nb_tetr] != NULL);
    mtrx_size = squared(sqrt(nb_tetr * 4));
    importance_sort(tab);
    matrix = ft_strnew(mtrx_size);  //MALLOC
    ft_memset(matrix, '0', mtrx_size);
    while (solution(" ") == NULL)
    {
        fill(tab, matrix, 0, 0);
        mtrx_size = squared(sqrt(mtrx_size) + 1);
        matrix = ft_memset(ft_realloc(matrix, mtrx_size), '0', mtrx_size); //REALLOC
    }
    print_solution(solution(" "));
}