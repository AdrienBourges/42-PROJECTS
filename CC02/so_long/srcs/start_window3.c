#include "../includes/ft_so_long.h"

void	move_player(int new_x, int new_y, t_data *data)
{
	if (data->map[new_y][new_x] != '1')
	{
		if (data->map[new_y][new_x] == 'C')
			data->collectibles--;
		if (data->map[new_y][new_x] == 'E')
		{
			if (data->collectibles == 0)
				ft_win(data);
			else
				return ;
		}
		data->map[data->player_y][data->player_x] = '0';
		data->map[new_y][new_x] = 'P';
		data->player_x = new_x;
		data->player_y = new_y;
		data->moves++;
		write(1, "Move count: ", 12);
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
		render_map(&data->images, data, ft_strlen(data->map[0]), data->rows);
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		cleanup(data);
		exit(0);
	}
	else if (keycode == KEY_W)
	{
		move_player(data->player_x, data->player_y - 1, data);
	}
	else if (keycode == KEY_A)
	{
		move_player(data->player_x - 1, data->player_y, data);
	}
	else if (keycode == KEY_S)
	{
		move_player(data->player_x, data->player_y + 1, data);
	}
	else if (keycode == KEY_D)
	{
		move_player(data->player_x + 1, data->player_y, data);
	}
	return (0);
}

int	ft_collectibles(t_data data)
{
	int	x;
	int	y;
	int	collectibles;

	x = 0;
	y = 0;
	collectibles = 0;
	while (x < data.rows)
	{
		while (y < data.width)
		{
			if (data.map[x][y] == 'C')
				collectibles++;
			y++;
		}
		y = 0;
		x++;
	}
	return (collectibles);
}

int	handle_close(t_data *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

void	init_window(t_data *d, char **map, int rows)
{
	d->map = map;
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
	{
		ft_freemap(map);
		ft_error("Error\nMiniLibX initialization failed\n");
		exit(1);
	}
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->width * 32, rows * 32, "Jeu");
	if (!d->win_ptr)
	{
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
		ft_freemap(map);
		ft_error("Error\nFailed to create window\n");
		exit(1);
	}
}
