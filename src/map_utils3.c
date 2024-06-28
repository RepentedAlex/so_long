/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:27:03 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/25 17:25:01 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_error	ft_check_top_bottom(t_map *map)
{
	char	*first;
	char	*last;

	first = map->map[0];
	last = ft_get_to_last_line(map);
	if (ft_check_walls(first) || ft_check_walls(last))
		return (ERROR);
	return (NO_ERROR);
}

t_error	ft_find_exit(t_map *map, t_game_positions *game_pos)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
			{
				game_pos->exit_x = j;
				game_pos->exit_y = i;
				return (NO_ERROR);
			}
			j++;
		}
		i++;
	}
	return (ERROR);
}

t_error	ft_check_walls(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == '1')
	{
		if (line[i] != '1')
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

void	ft_free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map[i]);
	free(map->map);
	map->map = NULL;
}

char	*ft_get_to_last_line(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i + 1] != 0)
		i++;
	return (map->map[i]);
}
