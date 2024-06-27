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

static void ft_free_texture(void *mlx_pointer, void *texture)
{
	mlx_destroy_image(mlx_pointer, texture);
	texture = NULL;
}

void	ft_free_textures(t_game_instance *game_instance)
{
	if (game_instance->textures.player_up != NULL)
		ft_free_texture(game_instance->mlx_ptr, game_instance->textures.player_up);
	if (game_instance->textures.player_down != NULL)
		ft_free_texture(game_instance->mlx_ptr, game_instance->textures.player_down);
	if (game_instance->textures.player_left != NULL)
		ft_free_texture(game_instance->mlx_ptr, game_instance->textures.player_left);
	if (game_instance->textures.player_right != NULL)
		ft_free_texture(game_instance->mlx_ptr, game_instance->textures.player_right);
	if (game_instance->textures.collectible != NULL)
		ft_free_texture(game_instance->mlx_ptr, game_instance->textures.collectible);
	if (game_instance->textures.wall != NULL)
		ft_free_texture(game_instance->mlx_ptr, game_instance->textures.wall);
	if (game_instance->textures.floor != NULL)
		ft_free_texture(game_instance->mlx_ptr, game_instance->textures.floor);
}

t_error	ft_load_textures(t_game_instance *current)
{
	printf("Loading textures...\n");
	current->textures.player_up = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/back.xpm", &current->textures.image_width, &current->textures.image_height);
	current->textures.player_down = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/front.xpm", &current->textures.image_width, &current->textures.image_height);
	current->textures.player_left = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/left.xpm", &current->textures.image_width, &current->textures.image_height);
	current->textures.player_right = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/right.xpm", &current->textures.image_width, &current->textures.image_height);
	current->textures.collectible = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/collectible.xpm", &current->textures.image_width, &current->textures.image_height);
	current->textures.wall = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/wall.xpm", &current->textures.image_width, &current->textures.image_height);
	current->textures.floor = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/floor.xpm", &current->textures.image_width, &current->textures.image_height);
	if (!current->textures.player_up || !current->textures.player_down || !current->textures.player_left || !current->textures.player_right)
		return (ERROR);
	if (!current->textures.collectible || !current->textures.wall || !current->textures.floor)
		return (ERROR);
	printf("Textures loaded!\n");
	return (NO_ERROR);
}
