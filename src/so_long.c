/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:42:57 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/28 14:15:48 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "so_long.h"

t_error	ft_big_init(t_game_instance *g_i, char *argv[])
{
	if (ft_check_file_is_ber(argv[1]))
		return (ERROR);
	if (ft_map_init(argv[1], &g_i->map, &g_i->game_pos))
	{
		if (g_i->map.map)
			ft_free_map(&g_i->map);
		return (2);
	}
	if (ft_init_game(g_i))
		return (ERROR);
	if (ft_texture_initialisation(g_i))
	{
		if (g_i->map.map)
			free(g_i->map.map);
		return (3);
	}
	draw_initial_state(g_i);
	return (NO_ERROR);
}

void	ft_destroyer(t_game_instance *game_instance)
{
	ft_free_textures(game_instance);
	if (game_instance->win_ptr)
		mlx_destroy_window(game_instance->mlx_ptr, game_instance->win_ptr);
	mlx_destroy_display(game_instance->mlx_ptr);
	free(game_instance->mlx_ptr);
	ft_free_map(&game_instance->map);
	free(game_instance->map.map);
}

//TOO MANY LINES
int	main(int argc, char *argv[])
{
	t_game_instance		current;

	(void)argv;
	ft_bzero(&current, sizeof(current));
	if (argc != 2)
		return (1);
	if (ft_big_init(&current, argv))
		return (2);
	mlx_key_hook(current.win_ptr, controls, &current);
	mlx_hook(current.win_ptr, 17, 1L << 0, exit_point, &current);
	mlx_loop(current.mlx_ptr);
	ft_destroyer(&current);
	ft_printf("Goodbye! :)\n");
	return (0);
}
