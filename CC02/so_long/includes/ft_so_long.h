#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../get_next_line//get_next_line.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_map
{
	int	rows;
	int	cols;
	int	exits;
	int	collectibles;
	int	start_pos;
}	t_map;

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	char		**map;
	int			player_x;
	int			player_y;
	int			rows;
	int			width;
	int			collectibles;
	int			moves;
	t_img		images;
}	t_data;

int		check_path(char **map, int rows);
int		is_ber_file(char *str);
char	**get_map(char *filename, int *rows);
void	check_map(char **map, int rows);
void	ft_freemap(char **map);
void	check_walls(char **map, int rows);
void	ft_start_window(char **map, int rows);
void	cleanup(t_data *data);
void	ft_error(char *str);
int		is_ber_file(char *str);
void	ft_exit2(int *line_lengths, char *str);
int		open_and_count_lines(char *filename, int *line_count);
void	map_info(char *filename, int **line_lengths, int *line_count);
void	allocate_lengths(int fd, int *line_lengths);
void	check_invalid_chars(char **map, t_map *info, int i, int j);
void	ft_initstruct(t_map *info);
char	**get_map(char *filename, int *rows);
void	read_map_from_file(int fd, char **map, int *line_lengths, int rows);
void	allocate_map_memory(char **map, int *line_lengths, int rows);
int		handle_keypress(int keycode, t_data *data);
void	move_player(int new_x, int new_y, t_data *data);
void	check_walls(char **map, int rows);
void	ft_exit_wall(char **map);
void	check_map(char **map, int rows);
void	validate_map_content(char **map, int rows, t_map *info, int frl);
void	check_row_length(char **map, int i, int first_row_length);
void	set_image_paths(t_img *img);
void	init_images(t_img *img, t_data *data);
void	render_map(t_img *img, t_data *data, int map_width, int map_height);
void	ft_win(t_data *data);
void	cleanup(t_data *data);
int		ft_collectibles(t_data data);
void	init_window(t_data *data, char **map, int rows);
int		handle_close(t_data *data);

#endif
