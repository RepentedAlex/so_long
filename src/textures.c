/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:19:37 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/25 18:42:42 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	ft_free_texture(void *mlx_pointer, void *texture)
{
	mlx_destroy_image(mlx_pointer, texture);
	texture = NULL;
}

void	ft_free_textures(t_game_instance *game_instance)
{
	ft_free_player_textures(game_instance);
	if (game_instance->txtrs.collectible != NULL)
		ft_free_texture(game_instance->mlx_ptr, \
		game_instance->txtrs.collectible);
	if (game_instance->txtrs.wall != NULL)
		ft_free_texture(game_instance->mlx_ptr, \
		game_instance->txtrs.wall);
	if (game_instance->txtrs.floor != NULL)
		ft_free_texture(game_instance->mlx_ptr, \
		game_instance->txtrs.floor);
	if (game_instance->txtrs.exit_close != NULL)
		ft_free_texture(game_instance->mlx_ptr, \
		game_instance->txtrs.exit_close);
	if (game_instance->txtrs.exit_open != NULL)
		ft_free_texture(game_instance->mlx_ptr, \
		game_instance->txtrs.exit_open);
}

t_error	ft_check_all_textures_loaded(t_game_instance *g_i)
{
	if (!g_i->txtrs.player_up || !g_i->txtrs.player_down \
	|| !g_i->txtrs.player_left || !g_i->txtrs.player_right || \
	!g_i->txtrs.collectible || !g_i->txtrs.wall \
	|| !g_i->txtrs.floor || !g_i->txtrs.exit_close || \
	!g_i->txtrs.exit_open)
		return (ERROR);
	return (NO_ERROR);
}

void	load_player_textures(t_game_instance *gam_ins)
{
	gam_ins->txtrs.player_up = mlx_xpm_file_to_image(gam_ins->mlx_ptr, \
	"./assets/back.xpm", &gam_ins->txtrs.wdth, \
	&gam_ins->txtrs.hght);
	gam_ins->txtrs.player_down = mlx_xpm_file_to_image(gam_ins->mlx_ptr, \
	"./assets/front.xpm", &gam_ins->txtrs.wdth, \
	&gam_ins->txtrs.hght);
	gam_ins->txtrs.player_left = mlx_xpm_file_to_image(gam_ins->mlx_ptr, \
	"./assets/left.xpm", &gam_ins->txtrs.wdth, \
	&gam_ins->txtrs.hght);
	gam_ins->txtrs.player_right = mlx_xpm_file_to_image(gam_ins->mlx_ptr, \
	"./assets/right.xpm", &gam_ins->txtrs.wdth, \
	&gam_ins->txtrs.hght);
}

t_error	ft_load_textures(t_game_instance *current)
{
	load_player_textures(current);
	current->txtrs.collectible = mlx_xpm_file_to_image(current->mlx_ptr, \
	"./assets/collectible.xpm", &current->txtrs.wdth, \
	&current->txtrs.hght);
	current->txtrs.wall = mlx_xpm_file_to_image(current->mlx_ptr, \
	"./assets/wall.xpm", &current->txtrs.wdth, \
	&current->txtrs.hght);
	current->txtrs.floor = mlx_xpm_file_to_image(current->mlx_ptr, \
	"./assets/floor.xpm", &current->txtrs.wdth, \
	&current->txtrs.hght);
	current->txtrs.exit_close = mlx_xpm_file_to_image(current->mlx_ptr, \
	"./assets/exit_close.xpm", &current->txtrs.wdth, \
	&current->txtrs.hght);
	current->txtrs.exit_open = mlx_xpm_file_to_image(current->mlx_ptr, \
	"./assets/exit_open.xpm", &current->txtrs.wdth, \
	&current->txtrs.hght);
	if (ft_check_all_textures_loaded(current))
		return (ft_destroyer(current), ERROR);
	return (NO_ERROR);
}
