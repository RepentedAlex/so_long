/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:53:13 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 17:53:13 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include "so_long.h"

#define A 97
#define D 100
#define RESTART 114
#define S 115
#define W 119
#define ESC 65307
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

typedef struct	s_textures
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
	int			image_width;
	int			image_height;
}				t_textures;

typedef struct	s_map_data
{
	char		**map_array;
	int 		map_height;
	int 		map_width;
	int			player_x;
	int 		player_y;
	int 		collectibles;
}				t_map_data;

typedef struct	s_game_resolutions
{
	int			map_width;
	int			map_height;
	char		*window_name;
	char		*map_name;
}				t_game_resolutions;

typedef struct	s_game_data
{
	int			collectibles_count;
	int			exit_count;
	int			movement_count;
	int			player_count;
}				t_game_data;

typedef struct	s_game_positions
{
	int			player_row;
	int			player_column;
	int			exit_row;
	int			exit_column;
}				t_game_positions;

typedef struct			s_game_instance
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_game_positions	positions_init;
	t_game_data			game_data;
}						t_game_instance;

t_error ft_ber_to_array(int fd, t_map_data *map);
t_error ft_check_if_finishable(t_map_data *map);
t_error ft_check_items(t_map_data *map);
t_error	ft_check_items_internal(t_map_data *map, int *c_count, int *e_count, int *p_count);
t_error ft_check_map_is_enclosed(t_map_data *map);
t_error	ft_check_map_is_rectangular(t_map_data *map);
t_error	ft_check_sides(t_map_data *map);
t_error ft_check_top_bottom(t_map_data *map);
void	ft_find_player(t_map_data *map);
void	ft_flood_fill(t_map_data *map, int minotaur_x, int minotaur_y);
t_error	ft_flood_fill_handler(t_map_data *map);
void	ft_free_map(t_map_data *map);
char	*ft_get_to_last_line(t_map_data *map);

#endif