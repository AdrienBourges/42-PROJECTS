#ifndef FT_SO_LONG_H
#define FT_SO_LONG_H

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../get_next_line//get_next_line.h"
#include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define KEY_W 119    // 'W' key
#define KEY_A 97     // 'A' key
#define KEY_S 115    // 'S' key
#define KEY_D 100    // 'D' key
#define KEY_ESC 65307 // 'ESC' key

typedef struct s_map {
    int rows;        // Number of rows in the map
    int cols;        // Number of columns in the map
    int exits;       // Number of exits (should be 1 for valid maps)
    int collectibles;// Number of collectibles (at least 1 for valid maps)
    int start_pos;   // Number of starting positions (should be 1 for valid maps)
} t_map;
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
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	char		**map;
   	int 		player_x;
	int 		player_y;
	int 		rows;
	int 		width;
	int collectibles;
	int moves;
	t_img 		images;	// Map pointer (contains map details - preferably kept on the stack)
}	t_data;
int check_path(char **map, int rows);
int is_ber_file(char *str);
char **get_map(char *filename, int *rows);
void check_map(char **map, int rows);
void ft_freemap(char **map);
void check_walls(char **map, int rows);
void ft_start_window(char **map, int rows);
void cleanup(t_data *data);
void ft_error(char *str);

#endif
