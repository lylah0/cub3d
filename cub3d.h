#ifndef CUB3D_H
# define CUB3D_H

# include "keys.h"
# include "lib/libft.h"
# include <unistd.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "minilibx-mac/mlx.h"   /* [AJOUT] pour préparer l'usage MLX */

typedef struct s_map
{
    int N;
    int S;
    int E;
    int W;
}   t_map;

typedef struct s_game {
	void *mlx;
	void *win;
	// t_img img;
	int   running;
} t_game;

typedef struct s_data
{
    t_map   map;
    t_game  game;
}   t_data;

#endif
