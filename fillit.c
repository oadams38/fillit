#include "fillit.h"

int     main(int argc, char **argv)
{
    char *data;

    if (argc == 2)
    {
        if ((data = check_file_valid(argv[1])) != NULL)
        {
            //ft_putstr(data);
            //free((void*)data);
            solve_and_print(data);
        }
        else
            ft_putstr("error\n");
    }
    else
    {
        //USAGE
        //EXIT PROPERLY
    }
    return (0);
}