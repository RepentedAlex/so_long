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

#include "libft.h"
#include "so_long.h"

void	ft_find_player(t_map *map)
{
	int	i;
	int j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (map->map_array[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				printf("Player is located on x%d, y%d\n", map->player_x, map->player_y);
				printf("Is this a P ? %c\n", map->map_array[map->player_y][map->player_x]);
				return ;
			}
			j++;
		}
		i++;
	}
}

void ft_flood_fill(t_map *map, int minotaur_x, int minotaur_y)
{
	int tmp;

	if ((minotaur_x < 0 && minotaur_y < 0) || map->map_array[minotaur_y][minotaur_x] < 0 || \
	map->map_array[minotaur_y][minotaur_x] == '1' || minotaur_x >= map->map_width || minotaur_y >= map->map_height)
		return ;
	tmp = map->map_array[minotaur_y][minotaur_x] * -1;
	map->map_array[minotaur_y][minotaur_x] = (char)tmp;
	ft_flood_fill(map, minotaur_x, minotaur_y + 1);
	ft_flood_fill(map, minotaur_x, minotaur_y - 1);
	ft_flood_fill(map, minotaur_x - 1, minotaur_y);
	ft_flood_fill(map, minotaur_x + 1, minotaur_y);
}

t_error	ft_flood_fill_handler(t_map *map)
{
	int mino_x;
	int mino_y;

	ft_find_player(map);
	mino_x = map->player_x;
	mino_y = map->player_y;
	ft_flood_fill(map, mino_x, mino_y);
	if (ft_check_if_finishable(map))
		return (ERROR);
	return (NO_ERROR);
}