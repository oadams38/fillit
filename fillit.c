#include "fillit.h"

int     main(int argc, char **argv)
{
    char *data;
    clock_t start, end;
    double runTime;
    
    start = clock();
    if (argc == 2)
    {
        if ((data = check_file_valid(argv[1])) != NULL)
        {
            //ft_putstr(data);
            //free((void*)data);
            //ft_putstr(data);
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
    end = clock();
    runTime = (end - start) / (double) CLOCKS_PER_SEC;
    printf("Solution found in %g seconds\n", runTime);
    return (0);
}