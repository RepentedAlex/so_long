/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:19:37 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/24 16:36:21 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

//void	ft_free_textures(t_textures *textures)
//{
//	if (textures->player_up)
//		free(textures->player_up);
//	if (textures->player_down)
//		free(textures->player_down);
//	if (textures->player_left)
//		free(textures->player_left);
//	if (textures->player_right)
//		free(textures->player_right);
//	if (textures->collectible)
//		free(textures->collectible);
//	if (textures->wall)
//		free(textures->wall);
//	if (textures->floor)
//		free(textures->floor);
//}

t_error	ft_load_textures(t_textures *textures, t_game_instance *current)
{
	printf("Loading textures...\n");
	textures->player_up = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/back.xpm", &textures->image_width, &textures->image_height);
	textures->player_down = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/front.xpm", &textures->image_width, &textures->image_height);
	textures->player_left = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/left.xpm", &textures->image_width, &textures->image_height);
	textures->player_right = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/right.xpm", &textures->image_width, &textures->image_height);
	textures->collectible = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/collectible.xpm", &textures->image_width, &textures->image_height);
	textures->wall = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/wall.xpm", &textures->image_width, &textures->image_height);
	textures->floor = mlx_xpm_file_to_image(current->mlx_ptr, "./assets/floor.xpm", &textures->image_width, &textures->image_height);
	if (!textures->player_up || !textures->player_down || !textures->player_left || !textures->player_right)
		return (ERROR);
	if (!textures->collectible || !textures->wall || !textures->floor)
		return (ERROR);
	printf("Textures loaded!\n");
	return (NO_ERROR);
}
