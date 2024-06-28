/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:59:03 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/25 18:04:39 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "errno.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

/*Size of the buffer used to read the .ber file*/
# define BUFFER_SIZE 256

# define XK_LATIN_1

# define ERROR 1
# define NO_ERROR 0

typedef bool	t_error;

// Stores all txtrs
typedef struct s_textures
{
	void		*collectible;
	void		*player_down;
	void		*player_left;
	void		*player_right;
	void		*player_up;
	void		*exit_close;
	void		*exit_open;
	void		*wall;
	void		*floor;
	int			wdth;
	int			hght;
}				t_textures;

// Stores all data that is solely related to the map
typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	int			collectibles;
}				t_map;

// Stores all data solely related to in game positions
typedef struct s_game_positions
{
	int			player_y;
	int			player_x;
	int			exit_y;
	int			exit_x;
}				t_game_positions;

// Stores all data tracking game status
typedef struct s_game_data
{
	int			exit_status;
	int			collectibles_count;
	int			movements_count;
}				t_game_data;

// Stores all structures as well as the pointers for the minilibx
typedef struct s_game_instance
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_game_positions	game_pos;
	t_game_data			game_data;
	t_map				map;
	t_textures			txtrs;
}						t_game_instance;

typedef enum e_directions
{
	up,
	down,
	left,
	right
}	t_directions;

t_error	ft_ber_to_array(int fd, t_map *map);
t_error	ft_check_if_finishable(t_map *map);
t_error	ft_check_items(t_map *map);
t_error	ft_check_items_internal(t_map *map, int *c_count, \
int *e_count, int *p_count);
t_error	ft_check_map_is_enclosed(t_map *map);
t_error	ft_check_map_is_rectangular(t_map *map);
t_error	ft_check_sides(t_map *map);
t_error	ft_check_top_bottom(t_map *map);
t_error	ft_find_exit(t_map *map, t_game_positions *game_pos);
t_error	ft_find_player(t_map *map, t_game_positions *game_pos);
void	ft_flood_fill(t_map *map, int minotaur_x, int minotaur_y);
t_error	ft_flood_fill_handler(t_map *map, t_game_positions *game_pos);
void	ft_free_map(t_map *map);
//void	ft_free_textures(t_textures *txtrs);
char	*ft_get_to_last_line(t_map *map);
t_error	ft_load_textures(t_game_instance *current);

//-----Displaying-----
void	draw_initial_state(t_game_instance *game_instance);
void	update_display_after_move(t_game_instance *g_i, t_directions direction);


void	update_display_up(t_game_instance *g_i);
void	update_display_down(t_game_instance *g_i);
void	update_display_left(t_game_instance *g_i);
void	update_display_right(t_game_instance *g_i);
int		exit_point(t_game_instance *game_instance);

int		controls(int keycode, t_game_instance *game_instance);

void	ft_free_textures(t_game_instance *game_instance);
t_error	ft_init_game(t_game_instance *game_instance);
t_error	ft_texture_initialisation(t_game_instance *current);
t_error	ft_map_initialisation(const char *filename, t_map *map, t_game_positions *game_pos);

t_error	ft_check_file_is_ber(const char *filename);

void check_case_up(t_game_instance *g_i);
void check_case_down(t_game_instance *g_i);
void check_case_left(t_game_instance *g_i);
void check_case_right(t_game_instance *g_i);
t_error	ft_check_map_exists(int *fd, const char *filename);

void	ft_free_texture(void *mlx_pointer, void *texture);
void	free_player_textures(t_game_instance *game_instance);
t_error	ft_check_walls(const char *line);

t_error	ft_is_charset(char c, int *c_count, int *e_count, int *p_count);
void	ft_reset_char(char *c, int *c_count, int *r_exit);

t_error	move_up(t_game_instance *game_instance);
t_error	move_down(t_game_instance *game_instance);
t_error	move_left(t_game_instance *game_instance);
t_error	move_right(t_game_instance *game_instance);
t_error	move_player(t_game_instance *game_instance, t_directions direction);
t_error	is_move_valid(t_game_instance *game_instance, t_directions direction);
void	check_if_special(t_game_instance *g_i, t_directions dir);
t_error	is_walkable(t_game_instance *game_instance, t_directions direction);
void	draw_floor_or_exit(t_game_instance *game_instance);
void	place_new_p(t_game_instance *game_instance, t_directions direction);
void	update_player_pos(int *player_y, int *player_x, t_directions direction);

#endif
