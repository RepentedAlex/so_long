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
		game_instance->map.map[game_instance->game_pos.player_y - 1][game_instance->game_pos.player_x] = 'P';
	if (direction == down)
		game_instance->map.map[game_instance->game_pos.player_y + 1][game_instance->game_pos.player_x] = 'P';
	if (direction == left)
		game_instance->map.map[game_instance->game_pos.player_y][game_instance->game_pos.player_x - 1] = 'P';
	if (direction == right)
		game_instance->map.map[game_instance->game_pos.player_y][game_instance->game_pos.player_x + 1] = 'P';
}

void	move_player(t_game_instance *game_instance, t_directions direction)
{
	check_if_special(game_instance, direction);
	place_new_p(game_instance, direction);
	game_instance->map.map[game_instance->game_pos.player_y][game_instance->game_pos.player_x] = '0';
	update_player_pos(&game_instance->game_pos.player_y, &game_instance->game_pos.player_x, direction);
	//Update frame
	game_instance->game_data.movements_count++;
	printf("%d movements\n", game_instance->game_data.movements_count);
}

void	check_if_special(t_game_instance *game_instance, t_directions direction)
{
	if (direction == up)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y - 1][game_instance->game_pos.player_x] != 'C')
			game_instance->game_data.collectibles_count++;
		if (game_instance->game_data.collectibles_count == game_instance->map.collectibles && game_instance->map.map[game_instance->game_pos.player_y - 1][game_instance->game_pos.player_x] != 'E')
			game_instance->game_data.exit_status = 1;
	}
	if (direction == down)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y + 1][game_instance->game_pos.player_x] != 'C')
			game_instance->game_data.collectibles_count++;
		if (game_instance->game_data.collectibles_count == game_instance->map.collectibles && game_instance->map.map[game_instance->game_pos.player_y + 1][game_instance->game_pos.player_x] != 'E')
			game_instance->game_data.exit_status = 1;
	}
	if (direction == left)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y][game_instance->game_pos.player_x - 1] != 'C')
			game_instance->game_data.collectibles_count++;
		if (game_instance->game_data.collectibles_count == game_instance->map.collectibles && game_instance->map.map[game_instance->game_pos.player_y][game_instance->game_pos.player_x - 1] != 'E')
			game_instance->game_data.exit_status = 1;
	}
	if (direction == right)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y][game_instance->game_pos.player_x + 1] != 'C')
			game_instance->game_data.collectibles_count++;
		if (game_instance->game_data.collectibles_count == game_instance->map.collectibles && game_instance->map.map[game_instance->game_pos.player_y][game_instance->game_pos.player_x + 1] != 'E')
			game_instance->game_data.exit_status = 1;
	}
}

t_error	is_walkable(t_game_instance *game_instance, t_directions direction)
{
	if (direction == up)
		if (game_instance->map.map[game_instance->game_pos.player_y - 1][game_instance->game_pos.player_x] != '1')
			return (NO_ERROR);
	if (direction == down)
		if (game_instance->map.map[game_instance->game_pos.player_y + 1][game_instance->game_pos.player_x] != '1')
			return (NO_ERROR);
	if (direction == left)
		if (game_instance->map.map[game_instance->game_pos.player_y][game_instance->game_pos.player_x - 1] != '1')
			return (NO_ERROR);
	if (direction == right)
		if (game_instance->map.map[game_instance->game_pos.player_y][game_instance->game_pos.player_x + 1] != '1')
			return (NO_ERROR);
	return (ERROR);
}

t_error	is_move_valid(t_game_instance *game_instance, t_directions direction)
{
	if (direction == up)
		if ((game_instance->game_pos.player_y - 1) >= 0 && \
		(game_instance->game_pos.player_y - 1) <= game_instance->map.height && \
		!is_walkable(game_instance, direction))
			return (NO_ERROR);
	if (direction == down)
		if ((game_instance->game_pos.player_y + 1) >= 0 && \
		(game_instance->game_pos.player_y + 1) <= game_instance->map.height && \
		!is_walkable(game_instance, direction))
			return (NO_ERROR);
	if (direction == left)
		if ((game_instance->game_pos.player_x - 1) >= 0 && \
		(game_instance->game_pos.player_x - 1) <= game_instance->map.width && \
		!is_walkable(game_instance, direction))
			return (NO_ERROR);
	if (direction == right)
		if ((game_instance->game_pos.player_x + 1) >= 0 && \
		(game_instance->game_pos.player_x + 1) <= game_instance->map.width && \
		!is_walkable(game_instance, direction))
			return (NO_ERROR);
	return (ERROR);
}

t_error	move_up(t_game_instance *game_instance)
{
	if (is_move_valid(game_instance, up))
		return (ERROR);
	move_player(game_instance, up);
	return (NO_ERROR);
}

t_error	move_down(t_game_instance *game_instance)
{
	if (is_move_valid(game_instance, down))
		return (ERROR);
	move_player(game_instance, down);
	return (NO_ERROR);
}

t_error	move_left(t_game_instance *game_instance)
{
	if (is_move_valid(game_instance, left))
		return (ERROR);
	move_player(game_instance, left);
	return (NO_ERROR);
}

t_error	move_right(t_game_instance *game_instance)
{
	if (is_move_valid(game_instance, right))
		return (ERROR);
	move_player(game_instance, right);
	return (NO_ERROR);
}
