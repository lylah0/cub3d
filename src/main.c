/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:30 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/22 15:36:18 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		exit(1);
	}
	return (fd);
}

int main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac == 2)
	{
		fd = open_file(av[1]);
		init_data(&data, fd);
		fd = open_file(av[1]);
		fill_map(fd, &data);
		// print_map(&data);
		if (map_parser(&data))
			printf("manque info map\n");
		// init_mlx(&data);
		// mlx_loop(data.game.mlx);
		return(0);
	}
	printf("too many or too few arguments.\n");
	return (1);
}
