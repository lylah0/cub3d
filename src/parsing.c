/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:27 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/20 18:35:39 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_map(int fd, t_data *data)
{
	int		y;
	char	*line;
	char	*temp;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL && y < data->count)
	{
		temp = ft_strtrim(line, "\n");
		if (!temp)
		{
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		free(line);
		line = temp;
		data->map[y] = line;
		y++;
		line = get_next_line(fd);
	}
	data->map[data->count] = NULL;
}

// void	map_parser(int fd, t_data *data);
// {

// }
