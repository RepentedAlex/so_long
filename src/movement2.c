/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:24:20 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/27 18:24:20 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	move_up(t_game_instance *game_instance)
{
	if (move_player(game_instance, up))
		return (ERROR);
	if (game_instance->game_data.exit_status && \
	game_instance->game_pos.player_x == game_instance->game_pos.exit_x && \
	game_instance->game_pos.player_y == game_instance->game_pos.exit_y)
		exit_point(game_instance);
	return (NO_ERROR);
}

t_error	move_down(t_game_instance *game_instance)
{
	if (move_player(game_instance, down))
		return (ERROR);
	if (game_instance->game_data.exit_status && \
	game_instance->game_pos.player_x == game_instance->game_pos.exit_x && \
	game_instance->game_pos.player_y == game_instance->game_pos.exit_y)
		exit_point(game_instance);
	return (NO_ERROR);
}

t_error	move_left(t_game_instance *game_instance)
{
	if (move_player(game_instance, left))
		return (ERROR);
	if (game_instance->game_data.exit_status && \
	game_instance->game_pos.player_x == game_instance->game_pos.exit_x \
	&& game_instance->game_pos.player_y == game_instance->game_pos.exit_y)
		exit_point(game_instance);
	return (NO_ERROR);
}

t_error	move_right(t_game_instance *game_instance)
{
	if (move_player(game_instance, right))
		return (ERROR);
	if (game_instance->game_data.exit_status && \
	game_instance->game_pos.player_x == game_instance->game_pos.exit_x && \
	game_instance->game_pos.player_y == game_instance->game_pos.exit_y)
		exit_point(game_instance);
	return (NO_ERROR);
}

void	check_case_up(t_game_instance *g_i)
{
	if (g_i->map.map[g_i->game_pos.player_y - 1][g_i->game_pos.player_x] \
		== 'C')
		g_i->game_data.collectibles_count++;
	if (g_i->game_data.collectibles_count == g_i->map.collectibles)
		g_i->game_data.exit_status = 1;
}
