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

#endif