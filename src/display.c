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

void	update_display_up(t_game_instance *g_i)
{
	if (g_i->game_pos.player_y + 1 == g_i->game_pos.exit_y && \
		g_i->game_pos.player_x == g_i->game_pos.exit_x)
		mlx_put_image_to_window(g_i->mlx_ptr, g_i->win_ptr, \
			g_i->txtrs.exit_close, g_i->game_pos.player_x * 32, \
			(g_i->game_pos.player_y + 1) * 32);
	else
		mlx_put_image_to_window(g_i->mlx_ptr, \
			g_i->win_ptr, g_i->txtrs.floor, \
			g_i->game_pos.player_x * 32, (g_i->game_pos.player_y + 1) * 32);
	mlx_put_image_to_window(g_i->mlx_ptr, g_i->win_ptr, \
		g_i->txtrs.player_up, \
		g_i->game_pos.player_x * 32, \
		g_i->game_pos.player_y * 32);
}

void	update_display_down(t_game_instance *g_i)
{
	if (g_i->game_pos.player_y - 1 == g_i->game_pos.exit_y && \
		g_i->game_pos.player_x == g_i->game_pos.exit_x)
		mlx_put_image_to_window(g_i->mlx_ptr, \
			g_i->win_ptr, g_i->txtrs.exit_close, \
			g_i->game_pos.player_x * 32, \
			(g_i->game_pos.player_y - 1) * 32);
	else
		mlx_put_image_to_window(g_i->mlx_ptr, \
			g_i->win_ptr, g_i->txtrs.floor, \
			g_i->game_pos.player_x * 32, \
			(g_i->game_pos.player_y - 1) * 32);
	mlx_put_image_to_window(g_i->mlx_ptr, \
		g_i->win_ptr, \
		g_i->txtrs.player_down, \
		g_i->game_pos.player_x * 32, \
		g_i->game_pos.player_y * 32);
}

//TOO MANY LINES
void	display_case(t_game_instance *game_instance, int y, int x)
{
	if (game_instance->map.map[y][x] == '0')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, game_instance->txtrs.floor, \
		x * game_instance->txtrs.wdth, y * game_instance->txtrs.hght);
	if (game_instance->map.map[y][x] == '1')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, game_instance->txtrs.wall, \
		x * game_instance->txtrs.wdth, y * game_instance->txtrs.hght);
	if (game_instance->map.map[y][x] == 'P')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, game_instance->txtrs.player_down, \
		x * game_instance->txtrs.wdth, y * game_instance->txtrs.hght);
	if (game_instance->map.map[y][x] == 'C')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->txtrs.collectible, \
		x * game_instance->txtrs.wdth, \
		y * game_instance->txtrs.hght);
	if (game_instance->map.map[y][x] == 'E')
		mlx_put_image_to_window(game_instance->mlx_ptr, \
		game_instance->win_ptr, \
		game_instance->txtrs.exit_close, \
		x * game_instance->txtrs.wdth, \
		y * game_instance->txtrs.hght);
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
			game_instance->txtrs.floor, \
			j * 32, i * 32);
			display_case(game_instance, i, j);
			j++;
		}
		i++;
	}
}
