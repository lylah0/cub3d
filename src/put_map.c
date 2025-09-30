/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:31:34 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/30 15:06:21 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// dessiner image dans buffer
void	put_pixel_img(t_img *im, int x, int y, int color)
{
	if ((unsigned)x >= (unsigned)im->width
		|| (unsigned)y >= (unsigned)im->height)
		return ;
	*(unsigned int *)(im->addr + y * im->line_len + x * (im->bpp
				/ 8)) = (unsigned int)color;
}

void	draw_cell(t_data *data, int x, int y, int color)
{
	int	px0;
	int	py0;
	int	py;
	int	px;

	px0 = x * TILE;
	py0 = y * TILE;
	py = 0;
	while (py < TILE)
	{
		px = 0;
		while (px < TILE)
		{
			put_pixel_img(&data->game.img, px0 + px, py0 + py, color);
			px++;
		}
		py++;
	}
}
