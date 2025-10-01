/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:29:11 by lylrandr          #+#    #+#             */
/*   Updated: 2025/10/01 17:40:43 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// AJOUTER FAILSAFE SI TEXTURE N'EXISTE PAS

int	spawn_check(t_data *data, char *file)
{
	if (ft_strncmp(file, "NO", 2) == 0)
	{
		data->map_info.N = 1;
		data->map_info.dir = 'N';
	}
	if (ft_strncmp(file, "SO", 2) == 0)
	{
		data->map_info.S = 1;
		data->map_info.dir = 'S';
	}
	if (ft_strncmp(file, "WE", 2) == 0)
	{
		data->map_info.W = 1;
		data->map_info.dir = 'W';
	}
	if (ft_strncmp(file, "EA", 2) == 0)
	{
		data->map_info.E = 1;
		data->map_info.dir = 'E';
	}
	if (!data->map_info.N && !data->map_info.S && !data->map_info.W
		&& !data->map_info.E)
		return (1);
	return (0);
}

void	stock_path_texture_no_we(t_data *data, char *file)
{
	int	i;

	i = 2;
	if (ft_strncmp(file, "NO", 2) == 0)
	{
		while (ft_iswhitespace(file[i]))
			i++;
		data->map_info.no_path = ft_strdup(&file[i]);
	}
	if (ft_strncmp(file, "WE", 2) == 0)
	{
		while (ft_iswhitespace(file[i]))
			i++;
		data->map_info.we_path = ft_strdup(&file[i]);
	}
}

void	stock_path_texture_so_ea(t_data *data, char *file)
{
	int	i;

	i = 2;
	if (ft_strncmp(file, "SO", 2) == 0)
	{
		while (ft_iswhitespace(file[i]))
			i++;
		data->map_info.so_path = ft_strdup(&file[i]);
	}
	if (ft_strncmp(file, "EA", 2) == 0)
	{
		while (ft_iswhitespace(file[i]))
			i++;
		data->map_info.ea_path = ft_strdup(&file[i]);
	}
}

int	spawn_setter(t_data *data)
{
	int	i;

	i = 0;
	if (!data || !data->file || data->count < 4)
		return (1);
	while (data->file[i])
	{
		if (spawn_check(data, data->file[i]))
			i++;
		else
		{
			stock_path_texture_no_we(data, data->file[i]);
			stock_path_texture_so_ea(data, data->file[i]);
			i++;
		}
	}
	if (!data->map_info.N || !data->map_info.S || !data->map_info.W
		|| !data->map_info.E)
		return (1);
	return (0);
}
