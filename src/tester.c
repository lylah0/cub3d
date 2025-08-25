/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:02:51 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/25 18:44:39 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void print_map(t_data *data)
{
	int i;

	if (!data->map)
		printf("no map\n");
	i = 0;
	while (data->map && data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}

