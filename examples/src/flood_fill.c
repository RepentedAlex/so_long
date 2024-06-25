/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:35:38 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/20 17:15:26 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/examples.h"
#include "../../extras/Libft/include/libft.h"
#include "game.h"

static void ft_find_player(t_map *map, t_game_positions *game_pos)
{
	int	i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				printf("Player is located on x%d, y%d\n", map->player_x, map->player_y);
				printf("Is this a P ? %c\n", map->map[map->player_y][map->player_x]);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map[i]);
	free(map->map);
}

t_error ft_flood_fill_handler(t_map *map, t_game_positions *game_pos)
{
	int mino_x;
	int mino_y;

	ft_find_player(map, NULL);
	mino_x = map->player_x;
	mino_y = map->player_y;
	ft_flood_fill(map, mino_x, mino_y);
	if (ft_check_if_finishable(map))
		return (ERROR);
	return (NO_ERROR);
}

/*
 * @brief get the tile (char) in the map at the given coordiantes
 * @param map The map to be used
 * @param x, y the coordinates
 * @param[out] out the
 */
t_error get_char_in_map(t_map *map, int x, int y, char *out)
{
	if (map == NULL || out == NULL)
		return (ERROR);
	if (x < 0 || y < 0 || x >= map->x || y >= map->y)
		return (ERROR);
	*out = map->map[y][x];
	return (NO_ERROR);
}

void ft_flood_fill(t_map *map, int minotaur_x, int minotaur_y)
{
	int tmp;

	if ((minotaur_x < 0 && minotaur_y < 0) || map->map[minotaur_y][minotaur_x] < 0 || \
	map->map[minotaur_y][minotaur_x] == '1' || minotaur_x >= map->x || minotaur_y >= map->y)
		return ;
	tmp = map->map[minotaur_y][minotaur_x] * -1;
	map->map[minotaur_y][minotaur_x] = tmp;
	ft_flood_fill(map, minotaur_x, minotaur_y + 1);
	ft_flood_fill(map, minotaur_x, minotaur_y - 1);
	ft_flood_fill(map, minotaur_x - 1, minotaur_y);
	ft_flood_fill(map, minotaur_x + 1, minotaur_y);
}


/*
 * @brief Reset each char to absolute values if needed and check if flood fill got all collectibles and exit.
 * collectibles
 * @param map The map's structure
 */
t_error ft_check_if_finishable(t_map *map)
{
	int i;
	int j;
	int tmp;
	int count_collectibles;
	int reach_exit;

	count_collectibles = 0;
	reach_exit = 0;
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] < 0)
			{
				tmp = map->map[i][j] * -1;
				map->map[i][j] = tmp;
				if (map->map[i][j] == 'C')
					count_collectibles++;
				if (map->map[i][j] == 'E')
					reach_exit = 1;
			}
			j++;
		}
		i++;
	}
	if (count_collectibles != map->collectibles || !reach_exit)
		return (printf("Map is not finishable chef :(\n"), ERROR);
	printf("Map is achievable ! :D\n");
	return (NO_ERROR);
}
