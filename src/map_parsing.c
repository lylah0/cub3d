/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:21:14 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/05 15:21:53 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floodfill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_info.lenght - 1|| y >= data->count)
		return;
	if (data->map[x][y] != '1' && data->map[x][y] != '2')
	{
		data->map[x][y] = '2';
		floodfill(data, x - 1, y);
		floodfill(data, x + 1, y);
		floodfill(data, x, y - 1);
		floodfill(data, x, y + 1);
	}
}

//lancer le floodfill
int	map_check(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	floodfill(data, x, y);
	return (0);
}
