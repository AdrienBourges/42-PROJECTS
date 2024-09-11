#include "../includes/ft_so_long.h"

void	set_image_paths(t_img *img)
{
	img->player = "./images/player.xpm";
	img->floor = "./images/floor.xpm";
	img->wall = "./images/wall.xpm";
	img->collect = "./images/collectible.xpm";
	img->exit = "./images/exit.xpm";
}

void	init_images(t_img *img, t_data *data)
{
	img->img_floor = mlx_xpm_file_to_image(data -> mlx_ptr, img->floor, &img->width, &img->height);
	img->img_player = mlx_xpm_file_to_image(data -> mlx_ptr, img->player, &img->width, &img->height);
	img->img_exit = mlx_xpm_file_to_image(data -> mlx_ptr, img->exit, &img->width, &img->height);
	img->img_wall = mlx_xpm_file_to_image(data -> mlx_ptr, img->wall, &img->width, &img->height);
	img->img_collect = mlx_xpm_file_to_image(data -> mlx_ptr, img->collect, &img->width, &img->height);
	if (!img->img_floor || !img->img_player || !img->img_exit || !img->img_wall || !img->img_collect)
	{
		cleanup(data);
		ft_error("Error\nCan't load one or more images.\n");
		exit(1);
	}
}

void	render_map(t_img *img, t_data *data, int map_width, int map_height)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_height)
	{
		x = 0;
		while (x < map_width)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img_wall, x * img->width, y * img->height);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img_player, x * img->width, y * img->height);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img_exit, x * img->width, y * img->height);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img_collect, x * img->width, y * img->height);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->img_floor, x * img->width, y * img->height);
			x++;
		}
		y++;
	}
}

void	cleanup(t_data *data)
{
	if (data->images.img_floor)
		mlx_destroy_image(data->mlx_ptr, data->images.img_floor);
	if (data->images.img_player)
		mlx_destroy_image(data->mlx_ptr, data->images.img_player);
	if (data->images.img_exit)
		mlx_destroy_image(data->mlx_ptr, data->images.img_exit);
	if (data->images.img_wall)
		mlx_destroy_image(data->mlx_ptr, data->images.img_wall);
	if (data->images.img_collect)
		mlx_destroy_image(data->mlx_ptr, data->images.img_collect);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map)
		ft_freemap(data->map);
}

void	ft_win(t_data *data)
{
	cleanup(data);
	write(1, "GG You completed the game in: ", 30);
	ft_putnbr_fd(data->moves + 1, 1);
	write(1, " moves\n", 7);
	exit(0);
}

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

void	init_window(t_data *data, char **map, int rows)
{
	data->map = map;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_freemap(map);
		ft_error("Error\nMiniLibX initialization failed\n");
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, ft_strlen(map[0]) * 32, rows * 32, "Hearthstone 2");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_freemap(map);
		ft_error("Error\nFailed to create window\n");
		exit(1);
	}
}

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
