#include "../cub3d.h"

void	init_mlx(t_data *data)
{
	data->game.mlx = mlx_init();
	data->game.win = mlx_new_window(data->game.mlx, 640, 600, "test");
	mlx_key_hook(data->game.win, key_move, data);
}