/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:38:35 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 15:38:35 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "so_long.h"

t_error ft_find_player(t_map *map, t_game_positions *game_pos)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				game_pos->player_x = j;
				game_pos->player_y = i;
				printf("Player is located on [y]%d, [x]%d\n", \
				game_pos->player_y, game_pos->player_x);
				printf("Is this a P-> %c ?\n", \
				map->map[game_pos->player_y][game_pos->player_x]);
				return (NO_ERROR);
			}
			j++;
		}
		i++;
	}
	return (ERROR);
}

void	ft_flood_fill(t_map *map, int minotaur_x, int minotaur_y)
{
	int	tmp;

	if ((minotaur_x < 0 && minotaur_y < 0) \
 || map->map[minotaur_y][minotaur_x] < 0 \
 || map->map[minotaur_y][minotaur_x] == '1' \
 || minotaur_x >= map->width \
 || minotaur_y >= map->height)
		return ;
	tmp = map->map[minotaur_y][minotaur_x] * -1;
	map->map[minotaur_y][minotaur_x] = (char)tmp;
	ft_flood_fill(map, minotaur_x, minotaur_y + 1);
	ft_flood_fill(map, minotaur_x, minotaur_y - 1);
	ft_flood_fill(map, minotaur_x - 1, minotaur_y);
	ft_flood_fill(map, minotaur_x + 1, minotaur_y);
}

t_error ft_flood_fill_handler(t_map *map, t_game_positions *game_pos)
{
	int	mino_x;
	int	mino_y;

	if (ft_find_player(map, game_pos))
		return (ERROR);
	mino_x = game_pos->player_x;
	mino_y = game_pos->player_y;
	ft_flood_fill(map, mino_x, mino_y);
	if (ft_check_if_finishable(map))
		return (ERROR);
	return (NO_ERROR);
}
