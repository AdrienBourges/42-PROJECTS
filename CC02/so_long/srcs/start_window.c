#include "../includes/ft_so_long.h"

void	init_game_elements(t_data *data, int rows)
{
	set_image_paths(&data->images);
	init_images(&data->images, data);
	data->rows = rows;
	data->moves = 0;
	data->width = ft_strlen(data->map[0]);
	data->collectibles = ft_collectibles(*data);
}

void	locate_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_start_window(char **map, int rows)
{
	t_data	data;

	init_window(&data, map, rows);
	init_game_elements(&data, rows);
	locate_player(&data);
	render_map(&data.images, &data, data.width, rows);
	mlx_hook(data.win_ptr, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);
	mlx_loop(data.mlx_ptr);
}

void	ft_win(t_data *data)
{
	cleanup(data);
	write(1, "GG You completed the game in: ", 30);
	ft_putnbr_fd(data->moves + 1, 1);
	write(1, " moves\n", 7);
	exit(0);
}
