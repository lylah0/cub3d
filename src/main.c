/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:30 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/05 14:57:27 by lylrandr         ###   ########.fr       */
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

int render_frame(void *param)
{
	t_data *d = (t_data *)param;

	ft_memset(d->game.img.addr, 0, d->game.img.line_len * d->game.img.height);
	put_map(d);
	return 0;
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
		if (map_parser(&data))
			return (1);
		// print_map(&data);
		init_mlx(&data);
		put_map(&data);
		mlx_loop_hook(data.game.mlx, render_frame, &data);
		mlx_loop(data.game.mlx);
		return(0);
	}
	printf("too many or too few arguments.\n");
	return (1);
}
