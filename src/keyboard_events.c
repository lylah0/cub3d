/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:33 by lylrandr          #+#    #+#             */
/*   Updated: 2025/09/30 15:06:13 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_window_x(void)
{
	exit(0);
	return (0);
}

int	key_move(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_ESC)
	{
		// free_all(void);
		exit(0);
	}
	// else if (keycode == KEY_W)
	// else if (keycode == KEY_A)
	// else if (keycode == KEY_S)
	// else if (keycode == KEY_D)
	// else if (keycode == KEY_LEFT)
	// else if (keycode == KEY_RIGHT)
	// else if (keycode == KEY_UP)
	// else if (keycode == KEY_DOWN)
	return (0);
}
