/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:42:57 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 14:12:29 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "so_long.h"

static t_error	ft_init_game(t_game_instance *current)
{
	current->mlx_ptr = mlx_init();
	if (!current->mlx_ptr)
		return (ERROR);
	current->win_ptr = mlx_new_window(current->mlx_ptr, 600, 400, "hi :)");
	if (!current->win_ptr)
		return (free(current->mlx_ptr), ERROR);
	return (NO_ERROR);
}

static t_error	ft_texture_initialisation(t_textures *textures, t_game_instance * current)
{
	if (ft_load_textures(textures, current))
		return (ERROR);
	return (NO_ERROR);
}

static t_error	ft_map_initialisation(const char *filename, t_map_data *map)
{
	int	fd;

	if (ft_check_map_exists(&fd, filename))
		return (ERROR);
	if (ft_ber_to_array(fd, map))
		return (ERROR);
	if (ft_check_map_is_rectangular(map))
		return (ERROR);
	if (ft_check_map_is_enclosed(map))
		return (ERROR);
	if (ft_check_items(map))
		return (ERROR);
	if (ft_flood_fill_handler(map))
		return (ERROR);
	return (NO_ERROR);
}

int	main(int argc, char *argv[])
{
	t_map_data		map;
	t_textures		textures;
	t_game_instance	current;

	ft_bzero(&map, sizeof(map));
	if (argc != 2)
		return (1);
	if (ft_check_file_is_ber(argv[1]))
		return (ERROR);
	if (ft_map_initialisation(argv[1], &map))
	{
		if (map.map_array)
			ft_free_map(&map);
		return (2);
	}
	if (ft_init_game(&current))
		return (ERROR);
	if (ft_texture_initialisation(&textures, &current))
	{
		if (map.map_array)
			free(map.map_array);
		return (3);
	}
	if (map.map_array)
		ft_free_map(&map);
//	ft_free_textures(&textures);
	mlx_destroy_window(current.mlx_ptr, current.win_ptr);
	mlx_destroy_display(current.mlx_ptr);
	free(current.mlx_ptr);
	return (0);
}
