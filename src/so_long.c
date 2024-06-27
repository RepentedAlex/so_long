/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:42:57 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/25 18:14:53 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static t_error	ft_init_game(t_game_instance *game_instance)
{
	game_instance->mlx_ptr = mlx_init();
	if (!game_instance->mlx_ptr)
		return (ERROR);
	game_instance->win_ptr = mlx_new_window(game_instance->mlx_ptr, \
	600, 400, "hi :)");
	if (!game_instance->win_ptr)
		return (free(game_instance->mlx_ptr), ERROR);
	return (NO_ERROR);
}

static t_error	ft_texture_initialisation(t_game_instance *current)
{
	if (ft_load_textures(current))
		return (ERROR);
	return (NO_ERROR);
}

static t_error	ft_map_initialisation(const char *filename, t_map *map, \
t_game_positions *game_pos)
{
	int	fd;

	if (ft_check_map_exists(&fd, filename))
		return (ERROR);
	if (ft_ber_to_array(fd, map))
		return (printf("Error: Couldn't convert map to 2D array.\n"), ERROR);
	if (ft_check_map_is_rectangular(map))
		return (ERROR);
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

void	ft_destroyer(t_game_instance *game_instance)
{
	printf("Exiting...\n");
	ft_free_textures(game_instance);
	if (game_instance->win_ptr)
		mlx_destroy_window(game_instance->mlx_ptr, game_instance->win_ptr);
	mlx_destroy_display(game_instance->mlx_ptr);
	free(game_instance->mlx_ptr);
	ft_free_map(&game_instance->map);
	free(game_instance->map.map);
}

int	main(int argc, char *argv[])
{
	t_game_instance		current;

	(void)argv;
	ft_bzero(&current, sizeof(current));
	if (argc != 2)
		return (1);
	if (ft_check_file_is_ber(argv[1]))
		return (ERROR);
	if (ft_map_initialisation(argv[1], &current.map, &current.game_pos))
	{
		if (current.map.map)
			ft_free_map(&current.map);
		return (2);
	}
	if (ft_init_game(&current))
		return (ERROR);
	if (ft_texture_initialisation(&current))
	{
		if (current.map.map)
			free(current.map.map);
		return (3);
	}
	mlx_key_hook(current.win_ptr, controls, &current);
	mlx_hook(current.win_ptr, 17, 1L << 0, exit_point, &current);
	mlx_loop(current.mlx_ptr);
	ft_destroyer(&current);
	printf("Goodbye! :)\n");
	return (0);
}
//TOO LONG
