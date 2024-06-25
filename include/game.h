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

// Stores all textures
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

// Stores all data that is solely related to the map
typedef struct	s_map
{
	char		**map;
	int 		height;
	int 		width;
	int 		collectibles;
}				t_map;

// Stores all data solely related to in game positions
typedef struct	s_game_positions
{
	int			player_y;
	int			player_x;
	int			exit_y;
	int			exit_x;
}				t_game_positions;


// Stores all data tracking game status
typedef struct	s_game_data
{
	int			exit_status;
	int			collectibles_count;
	int			movements_count;
//	int			player_count;
}				t_game_data;


// Stores all structures as well as the pointers for the minilibx
typedef struct			s_game_instance
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_game_positions	game_pos;
	t_game_data			game_data;
	t_map				map;
	t_textures			textures;
}						t_game_instance;

t_error ft_ber_to_array(int fd, t_map *map);
t_error ft_check_if_finishable(t_map *map);
t_error ft_check_items(t_map *map);
t_error	ft_check_items_internal(t_map *map, int *c_count, int *e_count, int *p_count);
t_error ft_check_map_is_enclosed(t_map *map);
t_error	ft_check_map_is_rectangular(t_map *map);
t_error	ft_check_sides(t_map *map);
t_error ft_check_top_bottom(t_map *map);
t_error ft_find_exit(t_map *map, t_game_positions *game_pos);
t_error ft_find_player(t_map *map, t_game_positions *game_pos);
void	ft_flood_fill(t_map *map, int minotaur_x, int minotaur_y);
t_error ft_flood_fill_handler(t_map *map, t_game_positions *game_pos);
void	ft_free_map(t_map *map);
void	ft_free_textures(t_textures *textures);
char	*ft_get_to_last_line(t_map *map);
t_error	ft_load_textures(t_textures *textures, t_game_instance *current);

#endif