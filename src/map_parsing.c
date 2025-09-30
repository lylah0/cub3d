/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:21:14 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/30 15:32:11 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// accepter espaces/lignes et map doit etre EOF

static int	is_spawn(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
static int	is_walk(char c)
{
	return (c == '0' || is_spawn(c));
}

static int	leaks_horiz(char **map, int y, int x)
{
	int	len;

	len = (int)ft_strlen(map[y]);
	if (x - 1 < 0)
		return (0);
	if (map[y][x - 1] == ' ')
		return (0);
	if (x + 1 >= len)
		return (0);
	if (map[y][x + 1] == ' ')
		return (0);
	return (1);
}

static int	leaks_vert(char **map, int y, int x)
{
	int	up_len;
	int	dn_len;

	if (y - 1 < 0)
		return (0);
	up_len = (int)ft_strlen(map[y - 1]);
	if (x >= up_len)
		return (0);
	if (map[y - 1][x] == ' ')
		return (0);
	if (map[y + 1] == NULL)
		return (0);
	dn_len = (int)ft_strlen(map[y + 1]);
	if (x >= dn_len)
		return (0);
	if (map[y + 1][x] == ' ')
		return (0);
	return (1);
}

int	map_check(t_data *data)
{
	int		y;
	int		x;
	int		len;
	char	c;

	if (!data || !data->map || !data->map[0])
		return (1);
	y = 0;
	while (data->map[y])
	{
		len = (int)ft_strlen(data->map[y]);
		x = 0;
		while (x < len)
		{
			c = data->map[y][x];
			if (c == '\t')
				c = ' ';
			if (c != '0' && c != '1' && c != ' ' && !is_spawn(c))
				return (1);
			if (is_walk(c))
			{
				if (!leaks_horiz(data->map, y, x))
					return (1);
				if (!leaks_vert(data->map, y, x))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
