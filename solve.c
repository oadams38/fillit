#include "fillit.h"

int     get_len(char *tetr, int side)
{
    int     len;
    int     i;
    int     tmp;

    tmp = 0;
    len = 0;
    i = -1;
    while (++i < 4)
    {
        if (i > 0 && tetr[i - 1] >= tetr[i])
            len += side;
        len = len + (int)(tetr[i]) - '0' - tmp;
        tmp = (int)(tetr[i] - '0');
    }
    return (len);    
}

int     fits(char *matrix, char *tetr, int i, int side)
{
    int     j;
    int     tmp;
    int     y;

    j = -1;
    y = i / side;
    tmp = 0;
    while (++j < 4)
    {
        if (j > 0 && tetr[j - 1] >= tetr[j])
        {
            i += side;
            y++;
        }
        i += ((int)(tetr[j] - '0') - tmp);
        tmp = (int)(tetr[j] - '0');
        if (matrix[i] != '0' || (i / side != y))
            return (-1);
    }
    return (1);
}

char     *fill(char *matrix, char *tetr, int i, int side)
{
    int     j;
    int     tmp;

    j = -1;
    tmp = 0;
    while (++j < 4)
    {
        if (j > 0 && tetr[j - 1] >= tetr[j])
            i += side;
        i += (int)(tetr[j] - '0') - tmp;
        tmp = (int)(tetr[j] - '0');
        matrix[i] = tetr[4];
    }
    return (matrix);
}

int    solve(char **tab, char *matrix, int i, int j)
{
    int         side = 0;
    int         len;
    static int  solved = 0;
    
    if (j == -1)
    {
        solved = 1;
        print_solution(matrix);
    }
    side = ft_sqrt(ft_strlen(matrix));
    if (j >= 0 && solved == 0)
    {
        len = get_len(tab[j], side);
        while (i + len < side * side)
        {
            if (fits(matrix, tab[j], i, side) != -1)
                solve(tab, fill(matrix, tab[j], i, side), 0, j - 1);
            i++;
        }
    }
    return (solved);
}