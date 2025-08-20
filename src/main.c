#include "../cub3d.h"

// static int	open_file(char *filename)
// {
// 	int	fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		ft_printf("Error opening file\n");
// 		exit(1);
// 	}
// 	return (fd);
// }



int main(int ac, char **av)
{
    t_data  data;
	(void)av;
	(void)ac;
    // int     fd;

    // fd = open_file(argv[1]);
	init_mlx(&data);
	mlx_loop(data.game.mlx);
	return(0);
}