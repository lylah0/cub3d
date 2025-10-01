/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:31:01 by lylrandr          #+#    #+#             */
/*   Updated: 2025/10/01 18:40:47 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_dir_from_char(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dirx =  0.0;
		player->diry = -1.0;
	}
	if (c == 'S')
	{
		player->dirx =  0.0;
		player->diry =  1.0;
	}
	if (c == 'E')
	{
		player->dirx =  1.0;
		player->diry =  0.0;
	}
	if (c == 'W')
	{
		player->dirx = -1.0;
		player->diry =  0.0;
	}
}

static void	set_plane_from_dir(t_player *player, double f)
{
	player->planex = -player->diry * f;
	player->planey = player->dirx * f;
}

void	init_player_from_spawn(t_data *data, char spawn_dir)
{
	int	sx;
	int	sy;

	sx = data->map_info.spawn[0]; /* x (colonne) */
	sy = data->map_info.spawn[1]; /* y (ligne) */
	data->player.posx = (double)sx + 0.5;
	data->player.posy = (double)sy + 0.5;
	set_dir_from_char(&data->player, spawn_dir);
	set_plane_from_dir(&data->player, 0.66);
	data->map[sy][sx] = '0'; /* on remplace le spawn par du sol */
}
