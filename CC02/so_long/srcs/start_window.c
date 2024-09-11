#include "../includes/ft_so_long.h"

void set_image_paths(t_img *img)
{
    img->player = "../images/player.xpm";
    img->floor = "../images/floor.xpm";
    img->wall = "../images/wall.xpm";
    img->collect = "../images/collectible.xpm";
    img->exit = "../images/exit.xpm";
}

void init_images(t_img *img, t_data *data)
{
    img->img_floor = mlx_xpm_file_to_image(data -> mlx_ptr, img->floor, &img->width, &img->height);
    img->img_player = mlx_xpm_file_to_image(data -> mlx_ptr, img->player, &img->width, &img->height);
    img->img_exit = mlx_xpm_file_to_image(data -> mlx_ptr, img->exit, &img->width, &img->height);
    img->img_wall = mlx_xpm_file_to_image(data -> mlx_ptr, img->wall, &img->width, &img->height);
    img->img_collect = mlx_xpm_file_to_image(data -> mlx_ptr, img->collect, &img->width, &img->height);
	if (!img->img_floor || !img->img_player || !img->img_exit || 
        !img->img_wall || !img->img_collect)
	{
		cleanup(data);
		ft_error("Error\nCan't load one or more images.\n");
		exit(1);
	}
}

void render_map(t_img *img, t_data *data, int map_width, int map_height)
{
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            if (data -> map[y][x] == '1') // Wall
                mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr, img->img_wall, x * img->width, y * img->height);
            else if (data -> map[y][x] == 'P') // Player
                mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr, img->img_player, x * img->width, y * img->height);
            else if (data -> map[y][x] == 'E') // Exit
                mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr, img->img_exit, x * img->width, y * img->height);
            else if (data -> map[y][x] == 'C') // Collectible
                mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr, img->img_collect, x * img->width, y * img->height);
            else // Floor
                mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr, img->img_floor, x * img->width, y * img->height);
	
        }
    }
}

void cleanup(t_data *data) {
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

    if (data->mlx_ptr) {
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
    }
	if (data -> map)
		ft_freemap(data -> map);
}


void move_player(int new_x, int new_y, t_data *data) {
    if (data->map[new_y][new_x] != '1') { // Check if the new position is not a wall
        if (data->map[new_y][new_x] == 'C') 
		{
		   data -> collectibles--;	// Check if the player collects a collectible
            // Update collectible counter or other logic
        }
        if (data->map[new_y][new_x] == 'E') 
		{
		   if (data -> collectibles == 0)
		   {
			   cleanup(data);
			   write(1, "GG You completed the game in: ", 30);
			   ft_putnbr_fd(data -> moves + 1, 1);
			   write(1, " moves\n",7);
			   exit(0);
		   }
		   else
			   return ;
			   // Check if the player reaches the exit
            // Check if all collectibles are collected and if the player can exit
        }

        // Update the map: move the player
        data->map[data->player_y][data->player_x] = '0'; // Set the old position to empty
        data->map[new_y][new_x] = 'P'; // Set the new position to the player
        data->player_x = new_x; // Update player's x position
        data->player_y = new_y; // Update player's y position
		data -> moves++;
		write(1, "Move count: ", 12);
		ft_putnbr_fd(data -> moves, 1);
		write(1, "\n", 1);

        render_map(&data->images, data, ft_strlen(data->map[0]), data->rows); // Redraw map
    }
}
int handle_keypress(int keycode, t_data *data) {
    if (keycode == KEY_ESC) 
	{
		cleanup(data);
        exit(0);
    } else if (keycode == KEY_W) {
        move_player(data->player_x, data->player_y - 1, data); // Move up
    } else if (keycode == KEY_A) {
        move_player(data->player_x - 1, data->player_y, data); // Move left
    } else if (keycode == KEY_S) {
        move_player(data->player_x, data->player_y + 1, data); // Move down
    } else if (keycode == KEY_D) {
        move_player(data->player_x + 1, data->player_y, data); // Move right
    }
    return 0;
}

int ft_collectibles(t_data data)
{
	int x;
	int y;
	int collectibles;

	x = 0;
	y = 0;
	collectibles = 0;
	while (x < data.rows)
	{
		while(y < data.width)
		{
			if (data.map[x][y] == 'C')
			{
				collectibles++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return collectibles;
}

int handle_close(t_data *data) {
    cleanup(data); // Clean up resources
    exit(0);       // Exit the program
    return (0);
}

void ft_start_window(char **map, int rows)
{
	t_data data;
	t_img images;

	data.map = map;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		ft_freemap(map);
		ft_error("Error\nMiniLibX initialization failed\n");
		exit(1);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, ft_strlen(map[0]) *32 ,rows * 32, "Hearthstone 2");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		ft_freemap(map);
		ft_error("Error\nFailed to create window\n");
		exit(1);
	}
	set_image_paths(&images);
	data.images = images;
	init_images(&images, &data);
	data.images = images;
	data.rows = rows;
	data.moves = 0;
	data.width = ft_strlen(map[0]);
	data.collectibles = ft_collectibles(data);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < data.width; x++) {
            if (map[y][x] == 'P') {
                data.player_x = x;
                data.player_y = y;
                break;
            }
        }
    }
	render_map(&images, &data, ft_strlen(map[0]), rows);
    mlx_hook(data.win_ptr, 2, 1L<<0, handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);
    mlx_loop(data.mlx_ptr);
	//mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	//mlx_destroy_display(data.mlx_ptr);
	//free(data.mlx_ptr);
}
