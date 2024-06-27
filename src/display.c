/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:58:05 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/27 15:11:06 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//TOO MANY LINES
void	update_display_after_move(t_game_instance *game_instance, \
t_directions direction)
{
	if (direction == up)
	{
		if (game_instance->game_pos.player_y + 1 == \
		game_instance->game_pos.exit_y && game_instance->game_pos.player_x \
		== game_instance->game_pos.exit_x)
			mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, game_instance->textures.exit_close, \
			game_instance->game_pos.player_x * 32, \
			(game_instance->game_pos.player_y + 1) * 32);
		else
			mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, game_instance->textures.floor, \
			game_instance->game_pos.player_x * 32, \
			(game_instance->game_pos.player_y + 1) * 32);
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, game_instance->textures.player_up, \
		game_instance->game_pos.player_x * 32, \
		game_instance->game_pos.player_y * 32);
	}
	if (direction == down)
	{
		if (game_instance->game_pos.player_y - 1 == \
		game_instance->game_pos.exit_y && game_instance->game_pos.player_x \
		== game_instance->game_pos.exit_x)
			mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, game_instance->textures.exit_close, \
			game_instance->game_pos.player_x * 32, \
			(game_instance->game_pos.player_y - 1) * 32);
		else
			mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, game_instance->textures.floor, \
			game_instance->game_pos.player_x * 32, \
			(game_instance->game_pos.player_y - 1) * 32);
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->textures.player_down, \
		game_instance->game_pos.player_x * 32, \
		game_instance->game_pos.player_y * 32);
	}
	if (direction == left)
	{
		if (game_instance->game_pos.player_y == game_instance->game_pos.exit_y \
		&& game_instance->game_pos.player_x + 1 == \
		game_instance->game_pos.exit_x)
			mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, game_instance->textures.exit_close, \
			(game_instance->game_pos.player_x + 1) * 32, \
			game_instance->game_pos.player_y * 32);
		else
			mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, \
			game_instance->textures.floor, \
			(game_instance->game_pos.player_x + 1) * 32, \
			game_instance->game_pos.player_y * 32);
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->textures.player_left, \
		game_instance->game_pos.player_x * 32, \
		game_instance->game_pos.player_y * 32);
	}
	if (direction == right)
	{
		if (game_instance->game_pos.player_y == game_instance->game_pos.exit_y \
		&& \
		game_instance->game_pos.player_x - 1 == game_instance->game_pos.exit_x)
			mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, \
			game_instance->textures.exit_close, \
			(game_instance->game_pos.player_x - 1) * 32, \
			game_instance->game_pos.player_y * 32);
		else
			mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, \
			game_instance->textures.floor, \
			(game_instance->game_pos.player_x - 1) * 32, \
			game_instance->game_pos.player_y * 32);
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->textures.player_right, \
		game_instance->game_pos.player_x * 32, \
		game_instance->game_pos.player_y * 32);
	}
}

//TOO MANY LINES
void	display_case(t_game_instance *game_instance, int y, int x)
{
	if (game_instance->map.map[y][x] == '0')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->textures.floor, \
		x * game_instance->textures.image_width, \
		y * game_instance->textures.image_height);
	if (game_instance->map.map[y][x] == '1')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->textures.wall, \
		x * game_instance->textures.image_width, \
		y * game_instance->textures.image_height);
	if (game_instance->map.map[y][x] == 'P')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->textures.player_down, \
		x * game_instance->textures.image_width, \
		y * game_instance->textures.image_height);
	if (game_instance->map.map[y][x] == 'C')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->textures.collectible, \
		x * game_instance->textures.image_width, \
		y * game_instance->textures.image_height);
	if (game_instance->map.map[y][x] == 'E')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->textures.exit_close, \
		x * game_instance->textures.image_width, \
		y * game_instance->textures.image_height);
}

void	draw_initial_state(t_game_instance *game_instance)
{
	int	i;
	int	j;

	i = 0;
	while (game_instance->map.map[i])
	{
		j = 0;
		while (game_instance->map.map[i][j])
		{
			mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, \
			game_instance->textures.floor, \
			j * 32, i * 32);
			display_case(game_instance, i, j);
			j++;
		}
		i++;
	}
}
