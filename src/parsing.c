/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:27 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/28 17:37:38 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	spawn_setter(t_data *data)
{
	static const char *expect[4] = {
		"NO ./path_north_texture",
		"SO ./path_south_texture",
		"WE ./path_west_texture",
		"EA ./path_east_texture"
	};
	int i;
	int k;

	if (!data || !data->file || data->count < 4)
		return (0);

	i = 0;
	while (i + 3 < data->count)
	{
		k = 0;
		while (k < 4 && data->file[i + k]
			&& ft_strncmp(data->file[i + k], expect[k], ft_strlen(expect[k])) == 0)
			k++;
		if (k == 4)
			return (1);
		i++;
	}
	return (0);
}

int	color_setter(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->count && data->file[i])
	{
		j = 0;
		if (data->file[i][j] == 'F')
		{
			i++;
			if (i >= data->count || !data->file[i])
				return (0);
			if (data->file[i][j] == 'C')
			{
				data->f_color = ft_strdup(data->file[i - 1]);
				data->c_color = ft_strdup(data->file[i]);
				return (1);
			}
			return (0);
		}
		i++;
	}
	return (0);
}

int map_setter(t_data *data)
{
	int i;
	int y;

	if (!data || !data->file || !data->map)
		return (0);

	i = 0;
	while (data->file[i] && data->file[i][0] != '1'
		&& data->file[i][0] != ' ' && data->file[i][0] != '\t')
		i++;
	if (!data->file[i])
		return (0);
	y = 0;
	while (data->file[i] && (data->file[i][0] == '1'
		|| data->file[i][0] == ' ' || data->file[i][0] == '\t'))
	{
		data->map[y] = ft_strdup(data->file[i]);
		if (!data->map[y])
			return (0);
		i++;
		y++;
	}
	data->map[y] = NULL;
	return (1);
}

int	map_parser(t_data *data)
{
	(void)data;
	if (!spawn_setter(data))
	{
		printf("missing spawn\n");
		return (1);
	}
	if (!color_setter(data))
	{
		printf("missing color\n");
		return(1);
	}
	if (!map_setter(data))
	{
		printf("missing map\n");
		return (1);
	}
	return (0);
}


