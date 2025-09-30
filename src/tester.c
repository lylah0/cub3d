/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:02:51 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/30 15:17:01 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void print_map(t_data *data)
{
	int i;

	if (!data->map)
		printf("no map\n");
	i = 0;
	while (data->map && data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}
// afficher la map en 2d
void put_map(t_data *data)
{
	int  y = 0, x;
	char c;

	if (!data || !data->map || !data->game.mlx || !data->game.win)
		return;

	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			c = data->map[y][x];
			if (c != ' ' && c != '\t')
			{
				if (c == '1')
					draw_cell(data, x, y, rgb_to_int(230, 154, 211)); //mur
				else if (c == '0') //vide
					draw_cell(data, x, y, rgb_to_int(192, 230, 154)); //spawn
				else if (c=='N'||c=='S'||c=='W'||c=='E')
					draw_cell(data, x, y, rgb_to_int(200, 0, 0));
				else //reste
					draw_cell(data, x, y, rgb_to_int(154, 195, 230));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->game.mlx, data->game.win, data->game.img.img, 0, 0);
}

