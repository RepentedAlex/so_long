/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:35:38 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/14 18:14:37 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/examples.h"
#include "../../extras/Libft/include/libft.h"

static void	ft_find_player(t_map *map)
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
				printf("Is this a P ? %c", map->map_array[map->player_y][map->player_x]);
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	ft_map_to_binary(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

bool	ft_flood_fill(t_map *map, t_map *duplicate)
{
	ft_map_to_binary(duplicate->map_array);
	ft_find_player(map);
	return (true);
}

char	**ft_duplicate_map(t_map *source)
{
	int		i;
	char	**tmp;

	if (!source)
		return (NULL);
	tmp = ft_calloc((source->y + 1), sizeof(char *));
	i = 0;
	while (source->map_array[i] && source->map_array[i][0] != '\0')
	{
		tmp[i] = ft_strdup(source->map_array[i]);
		i++;
	}
	return (tmp);
}

void	ft_duplicate_map_data(t_map *source, t_map *duplicate)
{
	duplicate->x = source->x;
	duplicate->y = source->y;
	duplicate->collectibles = source->collectibles;
}

void	ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->y)
	{
		free(map->map_array[i]);
		i++;
	}
	free(map->map_array[i]);
	free(map->map_array);
}

bool	ft_flood_fill_handler(t_map *map)
{
	t_map *duplicate;

	duplicate = malloc(sizeof(duplicate));
	ft_bzero(duplicate, sizeof(duplicate));
	duplicate->map_array = ft_duplicate_map(map);
	ft_duplicate_map_data(map, duplicate);
	ft_flood_fill(map, duplicate);

	ft_free_map(duplicate);
	free(duplicate);
	return (true);
}