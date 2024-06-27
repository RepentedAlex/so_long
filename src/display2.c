/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:09:39 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/27 19:09:39 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_display_after_move(t_game_instance *g_i, t_directions dir)
{
	if (dir == up)
		update_display_up(g_i);
	if (dir == down)
		update_display_down(g_i);
	if (dir == left)
		update_display_left(g_i);
	if (dir == right)
		update_display_right(g_i);
}

void	update_display_left(t_game_instance *g_i)
{
	if (g_i->game_pos.player_y == g_i->game_pos.exit_y \
		&& g_i->game_pos.player_x + 1 == g_i->game_pos.exit_x)
		mlx_put_image_to_window(g_i->mlx_ptr, \
			g_i->win_ptr, g_i->txtrs.exit_close, \
			(g_i->game_pos.player_x + 1) * 32, \
			g_i->game_pos.player_y * 32);
	else
		mlx_put_image_to_window(g_i->mlx_ptr, g_i->win_ptr, \
			g_i->txtrs.floor, (g_i->game_pos.player_x + 1) * 32, \
			g_i->game_pos.player_y * 32);
	mlx_put_image_to_window(g_i->mlx_ptr, g_i->win_ptr, \
		g_i->txtrs.player_left, g_i->game_pos.player_x * 32, \
		g_i->game_pos.player_y * 32);
}

void	update_display_right(t_game_instance *g_i)
{
	if (g_i->game_pos.player_y == g_i->game_pos.exit_y && \
	g_i->game_pos.player_x - 1 == g_i->game_pos.exit_x)
		mlx_put_image_to_window(g_i->mlx_ptr, g_i->win_ptr, \
		g_i->txtrs.exit_close, (g_i->game_pos.player_x - 1) * 32, \
		g_i->game_pos.player_y * 32);
	else
		mlx_put_image_to_window(g_i->mlx_ptr, g_i->win_ptr, \
		g_i->txtrs.floor, (g_i->game_pos.player_x - 1) * 32, \
		g_i->game_pos.player_y * 32);
	mlx_put_image_to_window(g_i->mlx_ptr, g_i->win_ptr, \
	g_i->txtrs.player_right, g_i->game_pos.player_x * 32, \
	g_i->game_pos.player_y * 32);
}
