/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:33:30 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/25 16:33:30 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int key_hook_w(int keycode, t_game_instance *game_instance)
{
	(void)keycode;
	(void)game_instance;
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int exit_point(t_game_instance *game_instance)
{
	printf("Exiting...\n");
	if (game_instance->win_ptr)
		mlx_destroy_window(game_instance->win_ptr, game_instance->win_ptr);
	free(game_instance->mlx_ptr);
	ft_free_map(&game_instance->map);
	free(game_instance->map.map);
//	mlx_destroy_display(game_instance->mlx_ptr);
	return (0);
}

int controls(int keycode, t_game_instance *game_instance)
{
	if (keycode == XK_Escape)
		exit_point(game_instance);
	return (0);
}