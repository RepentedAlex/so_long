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

#include "libft.h"
#include "so_long.h"

int	key_hook_w(int keycode, t_game_instance *game_instance)
{
	(void)keycode;
	(void)game_instance;
	printf("Key pressed: %d\n", keycode);
	return (0);
}

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
		printf("You just pressed the W key!\n");
	if (keycode == XK_s)
		printf("You just pressed the S key!\n");
	if (keycode == XK_a)
		printf("You just pressed the A key!\n");
	if (keycode == XK_d)
		printf("You just pressed the D key!\n");
	return (0);
}
