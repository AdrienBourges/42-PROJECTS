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
	img->img_floor = mlx_xpm_file_to_image(data->mlx_ptr, img->floor,
			&img->width, &img->height);
	img->img_player = mlx_xpm_file_to_image(data->mlx_ptr, img->player,
			&img->width, &img->height);
	img->img_exit = mlx_xpm_file_to_image(data->mlx_ptr, img->exit,
			&img->width, &img->height);
	img->img_wall = mlx_xpm_file_to_image(data->mlx_ptr, img->wall,
			&img->width, &img->height);
	img->img_collect = mlx_xpm_file_to_image(data->mlx_ptr, img->collect,
			&img->width, &img->height);
	if (!img->img_floor || !img->img_player || !img->img_exit
		|| !img->img_wall || !img->img_collect)
	{
		cleanup(data);
		ft_error("Error\nCan't load one or more images.\n");
		exit(1);
	}
}

void	put_image(t_img *img, t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->img_wall, x * img->width, y * img->height);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->img_player, x * img->width, y * img->height);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->img_exit, x * img->width, y * img->height);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->img_collect, x * img->width, y * img->height);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->img_floor, x * img->width, y * img->height);
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
			put_image(img, data, x, y);
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
