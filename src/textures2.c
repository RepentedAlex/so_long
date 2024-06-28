/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:42:08 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/27 18:42:08 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_player_textures(t_game_instance *game_instance)
{
	if (game_instance->txtrs.player_up != NULL)
		ft_free_texture(game_instance->mlx_ptr, \
		game_instance->txtrs.player_up);
	if (game_instance->txtrs.player_down != NULL)
		ft_free_texture(game_instance->mlx_ptr, \
		game_instance->txtrs.player_down);
	if (game_instance->txtrs.player_left != NULL)
		ft_free_texture(game_instance->mlx_ptr, \
		game_instance->txtrs.player_left);
	if (game_instance->txtrs.player_right != NULL)
		ft_free_texture(game_instance->mlx_ptr, \
		game_instance->txtrs.player_right);
}
