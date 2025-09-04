/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:02:51 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/04 15:58:08 by lylrandr         ###   ########.fr       */
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
					draw_cell(data, x, y, rgb_to_int(50, 50, 50));
				else if (c == '0')
					draw_cell(data, x, y, rgb_to_int(200, 200, 200));
				else if (c=='N'||c=='S'||c=='W'||c=='E')
					draw_cell(data, x, y, rgb_to_int(0, 200, 100));
				else
					draw_cell(data, x, y, rgb_to_int(255, 0, 0));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->game.mlx, data->game.win, data->game.img.img, 0, 0);
}

