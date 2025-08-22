/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:27 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/22 15:51:53 by lylrandr         ###   ########.fr       */
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
	int start;
	int k;
	int want_len;
	const char *line;
	const char *want;

	if (!data || !data->map || data->count < 4)
		return (0);

	start = 0;
	while (start + 3 < data->count)   /* fenêtre de 4 lignes */
	{
		k = 0;
		while (k < 4)
		{
			line = data->map[start + k];
			want = expect[k];
			if (!line)
				break;
			want_len = ft_strlen(want);
			if (ft_strncmp(line, want, want_len) != 0 || line[want_len] != '\0')
				break;
			k++;
		}
		if (k == 4)
			return (1);  /* bloc trouvé */
		start++;
	}
	return (0);  /* pas trouvé */
}



int	color_setter(t_data *data)
{
	(void)data;
	return (1);
}

int	map_setter(t_data *data)
{
	(void)data;

	return (1);
}

int	map_parser(t_data *data)
{
	(void)data;
	if (!(spawn_setter(data)) || !(color_setter(data)) || !(map_setter(data)))
		return (1);
	return (0);
}


