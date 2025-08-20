/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:02:51 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/20 18:30:48 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map(t_data *data)
{
	int	i;
	int	x;

	i = 0;
	while (data->map[i])
	{
		x = 0;
		while (data->map[i][x])
		{
			printf("%c", data->map[i][x]);
			x++;
		}
		printf("\n");
		i++;
	}
	printf("hello\n");
}
