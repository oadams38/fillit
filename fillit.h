#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFSIZE 21
# define MAX_NB_TETR 26
# define MAX_DATA 206


char        *check_file_valid(char *argv);
void        solve_and_print(char *data);
int         squared(int n);
int         sqrt(int n);

#endif