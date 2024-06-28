/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:20:35 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/27 19:20:35 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	ft_init_game(t_game_instance *game_instance)
{
	int	window_width;
	int	window_height;

	window_width = 32 * (game_instance->map.width + 1);
	window_height = 32 * game_instance->map.height;
	game_instance->mlx_ptr = mlx_init();
	if (!game_instance->mlx_ptr)
		return (ERROR);
	game_instance->win_ptr = mlx_new_window(game_instance->mlx_ptr, \
	window_width, window_height, "MOTOMAMI");
	if (!game_instance->win_ptr)
		return (free(game_instance->mlx_ptr), ERROR);
	return (NO_ERROR);
}

t_error	ft_texture_initialisation(t_game_instance *current)
{
	if (ft_load_textures(current))
		return (ERROR);
	return (NO_ERROR);
}

t_error	ft_map_initialisation(const char *filename, t_map *map, \
t_game_positions *game_pos)
{
	int	fd;

	if (ft_check_map_exists(&fd, filename))
		return (ERROR);
	if (ft_ber_to_array(fd, map))
		return (printf("Error: Couldn't convert map to 2D array.\n"), ERROR);
	if (ft_check_map_is_rectangular(map))
	{
		ft_free_map(map);
		return (ERROR);
	}
	if (ft_check_map_is_enclosed(map))
		return (ERROR);
	if (ft_check_items(map))
		return (ERROR);
	if (ft_flood_fill_handler(map, game_pos))
		return (ERROR);
	if (ft_find_exit(map, game_pos))
		return (ERROR);
	return (NO_ERROR);
}
