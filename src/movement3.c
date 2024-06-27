/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:23:12 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/27 18:23:12 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	is_walkable(t_game_instance *game_instance, t_directions direction)
{
	if (direction == up)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y - 1] \
		[game_instance->game_pos.player_x] == '1')
			return (ERROR);
	}
	if (direction == down)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y + 1] \
		[game_instance->game_pos.player_x] == '1')
			return (ERROR);
	}
	if (direction == left)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y] \
		[game_instance->game_pos.player_x - 1] == '1')
			return (ERROR);
	}
	if (direction == right)
	{
		if (game_instance->map.map[game_instance->game_pos.player_y] \
		[game_instance->game_pos.player_x + 1] == '1')
			return (ERROR);
	}
	return (NO_ERROR);
}

t_error	is_move_valid(t_game_instance *game_instance, t_directions direction)
{
	if (direction == up)
		if (is_walkable(game_instance, direction))
			return (ERROR);
	if (direction == down)
		if (is_walkable(game_instance, direction))
			return (ERROR);
	if (direction == left)
		if (is_walkable(game_instance, direction))
			return (ERROR);
	if (direction == right)
		if (is_walkable(game_instance, direction))
			return (ERROR);
	return (NO_ERROR);
}
