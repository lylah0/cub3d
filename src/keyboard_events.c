#include "../cub3d.h"

int	key_move(int keycode, t_data *data)
{
	(void)data;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return (0);
}