/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:38 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/02 17:29:05 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <fcntl.h>
# include "minilibx-mac/mlx.h"   /* [AJOUT] pour préparer l'usage MLX */

#define TILE 10

typedef struct s_map
{
	int N;
	int S;
	int E;
	int W;
}	t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	// t_img img;
	int		running;
} t_game;

typedef struct s_data
{
	int		count;
	char	**map;
	char	**file;
	char	*f_color;
	char	*c_color;
	// t_map	map;
	t_game	game;
}	t_data;

int		key_move(int keycode, t_data *data);
void	init_mlx(t_data *data);
int		close_window_x(void);
int		map_parser(t_data *data);
void	fill_map(int fd, t_data *data);
void	init_data(t_data *data, int fd);

void	put_map(t_data *data);

void	print_map(t_data *data);

#endif
