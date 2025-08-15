#ifndef CUB3D_H
# define CUB3D_H

# include "lib/libft.h"
# include <unistd.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>

typedef struct s_map
{
    int N;
    int S;
    int E;
    int W;
}       t_map;

typedef struct  s_data
{
    struct  t_map;
}   t_data;

#endif