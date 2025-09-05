/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:38 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/05 14:34:06 by lylrandr         ###   ########.fr       */
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
#define WIN_H 650
#define WIN_W 750

typedef	struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
} t_img;

typedef	struct s_map_info
{
	int N;
	int S;
	int E;
	int W;
	int	lenght;
}	t_map_info;

typedef	struct s_game {
	void	*mlx;
	void	*win;
	int		running;
	t_img	img;
}	t_game;

typedef	struct s_data
{
	int		count;
	int		dir;
	char	**map;
	char	**file;
	char	*f_color;
	char	*c_color;
	t_img	img;
	t_game	game;
	t_map_info	map_info;
}	t_data;

int		key_move(int keycode, t_data *data);
void	init_mlx(t_data *data);
int		close_window_x(void);
int		map_parser(t_data *data);
void	fill_map(int fd, t_data *data);
void	init_data(t_data *data, int fd);
int		rgb_to_int(int r, int g, int b);
void	draw_cell(t_data *data, int x, int y, int color);
int		map_check(t_data *data);

void	put_pixel_img(t_img *im, int x, int y, int color);

void	print_map(t_data *data);
void	put_map(t_data *data);

#endif
