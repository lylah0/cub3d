/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:35 by lylrandr          #+#    #+#             */
/*   Updated: 2025/10/01 19:02:15 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_mlx(t_data *data)
{
	data->game.mlx = mlx_init();
	data->game.win = mlx_new_window(data->game.mlx, WIN_W, WIN_H, "cub3d");
	data->game.img.img = mlx_new_image(data->game.mlx, WIN_W, WIN_H);
	data->game.img.addr = mlx_get_data_addr(data->game.img.img,
			&data->game.img.bpp, &data->game.img.line_len,
			&data->game.img.endian);
	data->game.img.width = WIN_W;
	data->game.img.height = WIN_H;
	mlx_key_hook(data->game.win, key_move, data);
	mlx_hook(data->game.win, 17, 0, close_window_x, data);
}

void	init_data(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	data->count = 0;
	while (line != NULL)
	{
		data->count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->map_info.spawn[0] = -1;
	data->map_info.spawn[1] = -1;
	data->map_info.N = 0;
	data->map_info.S = 0;
	data->map_info.W = 0;
	data->map_info.E = 0;
	data->map_info.lenght = 0;
	data->map = malloc(sizeof(char *) * ((data->count) + 1));
	data->file = malloc(sizeof(char *) * ((data->count) + 1));
	data->c_color = malloc(sizeof(char) * 16);
	data->f_color = malloc(sizeof(char) * 16);
}

// remplir la map
void	fill_map(int fd, t_data *data)
{
	int		y;
	char	*line;
	char	*temp;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL && y < data->count)
	{
		temp = ft_strtrim(line, "\n");
		if (!temp)
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		free(line);
		line = temp;
		data->file[y] = line;
		y++;
		line = get_next_line(fd);
	}
	data->file[data->count] = NULL;
	close(fd);
}
