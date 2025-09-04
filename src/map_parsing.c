/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:21:14 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/04 18:37:15 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//lancer le floodfill
void	map_check(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	flood_fill(data, x, y);
}
