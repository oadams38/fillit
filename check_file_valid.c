#include "fillit.h"

char    *get_tetr(char *buf, int letter)
{
    int     i;
    int     j;
    int     pos[4];
    char    *tetr;
    char    tmp[6];

    i = -1;
    j = -1;
    while (++i < BUFFSIZE)
    {
        if (buf[i] == '#')
            pos[++j] = (i + 1) % 5;
    }
    while (pos[0] > 0 && pos[1] > 0 && pos[2] > 0 && pos[3] > 0)
    {
        i = -1;
        while (++i < 4)
            pos[i]--;
    }
    tetr = ft_strnew(5);
    i = -1;
    while (++i < 4)
        tmp[i] = (char)pos[i] + '0';
    tmp[4] = (char)letter + 'A';
    tmp[5] = '\n';
    return (ft_strcpy(tetr, tmp));
}

int    check_char(char *buf)
{
    int     i;

    i = -1;
    while (++i < BUFFSIZE)
    {
        if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
        {
            if (buf[i] != '\n')
                return (-1);
        }
        else if (buf[i] != '#' && buf[i] != '.')
            return (-1);
    }
    return (1);
}

int     check_tetr(char *buf)
{
    int     i;
    int     touches;
    int     n;

    touches = 0;
    n = 0;
    i = -1;
    while (++i < BUFFSIZE)
    {
        if (buf[i] == '#' && ++n)
        {
            if (i - 5 >= 0 && buf[i - 5] == '#')
                touches++;
            if (i + 5 < 20 && buf[i + 5] == '#')
                touches++;
            if ((i + 1) % 5 != 0 && buf[i + 1] == '#')
                touches++;
            if ((i - 1) % 5 != 0 && i - 1 >= 0 && buf[i - 1] == '#')
                touches++;
        }
    }
    return ((touches > 4 && n == 4) ? 1 : -1);
}

char    *check_get_tetr(int fd)
{
    char    buf[BUFFSIZE + 1];
    int     ret;
    int     i;
    char    *tetrimini;
    char    *tmp;

    ret = 1;
    i = -1;
    if ((tetrimini = ft_strnew(MAX_DATA)) == NULL)  //MALLOC
        return (NULL);
    while (ret != 0 && ++i < 26)
    {
        ret = read(fd, buf, BUFFSIZE);
        buf[BUFFSIZE] = '\0';
        if (ret == 0 || ret == -1)
            return (ret == 0 ? tetrimini : NULL);
        if (check_char(buf) == -1 || check_tetr(buf) == -1)
            return (NULL);
        tmp = get_tetr(buf, i);
        ft_strcat(tetrimini, tmp);
    }
    return (NULL);
}

char     *check_file_valid(char *argv)
{
    char    *tetrimini;
    int     fd;

    if ((fd = open(argv, O_APPEND)) == -1)
        return (NULL);
    tetrimini = check_get_tetr(fd);
    close(fd);
    return (tetrimini);
}