/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:33:30 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/25 17:29:54 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Summon mlx_loop_end() in order to wrap up the game correctly
int	exit_point(t_game_instance *game_instance)
{
	mlx_loop_end(game_instance->mlx_ptr);
	return (0);
}

//Handles the different inputs
int	controls(int keycode, t_game_instance *game_instance)
{
	if (keycode == XK_Escape)
		exit_point(game_instance);
	if (keycode == XK_w)
		move_up(game_instance);
	if (keycode == XK_s)
		move_down(game_instance);
	if (keycode == XK_a)
		move_left(game_instance);
	if (keycode == XK_d)
		move_right(game_instance);
	return (0);
}
