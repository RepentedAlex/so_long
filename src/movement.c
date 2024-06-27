/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:32:22 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/27 13:32:22 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_pos(int *player_y, int *player_x, t_directions direction)
{
	if (direction == up)
		*player_y -= 1;
	if (direction == down)
		*player_y += 1;
	if (direction == left)
		*player_x -= 1;
	if (direction == right)
		*player_x += 1;
}

void	place_new_p(t_game_instance *game_instance, t_directions direction)
{
	if (direction == up)
		game_instance->map.map[game_instance->game_pos.player_y - 1] \
		[game_instance->game_pos.player_x] = 'P';
	if (direction == down)
		game_instance->map.map[game_instance->game_pos.player_y + 1] \
		[game_instance->game_pos.player_x] = 'P';
	if (direction == left)
		game_instance->map.map[game_instance->game_pos.player_y] \
		[game_instance->game_pos.player_x - 1] = 'P';
	if (direction == right)
		game_instance->map.map[game_instance->game_pos.player_y] \
		[game_instance->game_pos.player_x + 1] = 'P';
}

void	draw_floor_or_exit(t_game_instance *game_instance)
{
	if (game_instance->game_pos.player_y == game_instance->game_pos.exit_y \
	&& game_instance->game_pos.player_x == game_instance->game_pos.exit_x)
		game_instance->map.map[game_instance->game_pos.player_y] \
		[game_instance->game_pos.player_x] = 'E';
	else
		game_instance->map.map[game_instance->game_pos.player_y] \
		[game_instance->game_pos.player_x] = '0';
}

t_error	move_player(t_game_instance *game_instance, t_directions direction)
{
	if (is_move_valid(game_instance, direction))
		return (ERROR);
	check_if_special(game_instance, direction);
	if (game_instance->game_data.exit_status)
		mlx_put_image_to_window(game_instance->mlx_ptr, \
			game_instance->win_ptr, game_instance->textures.exit_open, \
			game_instance->game_pos.exit_x * 32, \
			game_instance->game_pos.exit_y * 32);
	place_new_p(game_instance, direction);
	draw_floor_or_exit(game_instance);
	update_player_pos(&game_instance->game_pos.player_y, \
	&game_instance->game_pos.player_x, direction);
	printf("Player is on [y]%d, [x]%d\n", \
	game_instance->game_pos.player_y, \
	game_instance->game_pos.player_x);
	update_display_after_move(game_instance, direction);
	game_instance->game_data.movements_count++;
	printf("%d movements\n", game_instance->game_data.movements_count);
	return (NO_ERROR);
}

//TOO MANY LINES
void	check_if_special(t_game_instance *game_instance, t_directions direction)
{
	if (direction == up)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y - 1] \
		[game_instance->game_pos.player_x] == 'C')
			game_instance->game_data.collectibles_count++;
		if (game_instance->game_data.collectibles_count == \
		game_instance->map.collectibles)
			game_instance->game_data.exit_status = 1;
	}
	if (direction == down)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y + 1] \
		[game_instance->game_pos.player_x] == 'C')
			game_instance->game_data.collectibles_count++;
		if (game_instance->game_data.collectibles_count == \
		game_instance->map.collectibles)
			game_instance->game_data.exit_status = 1;
	}
	if (direction == left)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y] \
		[game_instance->game_pos.player_x - 1] == 'C')
			game_instance->game_data.collectibles_count++;
		if (game_instance->game_data.collectibles_count == \
		game_instance->map.collectibles)
			game_instance->game_data.exit_status = 1;
	}
	if (direction == right)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y] \
		[game_instance->game_pos.player_x + 1] == 'C')
			game_instance->game_data.collectibles_count++;
		if (game_instance->game_data.collectibles_count == \
		game_instance->map.collectibles)
			game_instance->game_data.exit_status = 1;
	}
}
