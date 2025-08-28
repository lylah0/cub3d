/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:31:34 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/28 17:17:53 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void draw_cell(t_data *data, int x, int y, int color)
{
	int px0 = x * TILE;
	int py0 = y * TILE;
	int py;
	int px;

	py = 0;
	while (py < TILE)
	{
		px = 0;
		while (px < TILE)
		{
			mlx_pixel_put(data->game.mlx,  data->game.win, px0 + px, py0 + py, color);
			px++;
		}
		py++;
	}
}

// afficher la map en 2d
void put_map(t_data *data)
{
	int		y;
	int		x;
	char	c;

	if (!data || !data->map || !data->game.mlx || !data->game.win)
		return;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			c = data->map[y][x];
			if (c == '\t' || c == ' ')
			{
				x++;
				continue;
			}
			if (c == '1')
				draw_cell(data, x, y, 255);
			else if (c == '0')
				draw_cell(data, x, y, 150);
			else if (c=='N'||c=='S'||c=='W'||c=='E')
				draw_cell(data, x, y, 100);
			else
				draw_cell(data, x, y, 0);
			x++;
		}
		y++;
	}
}

