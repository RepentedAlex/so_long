/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:05:37 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 11:05:41 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_error	ft_check_sides(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		if (map->map_array[i][0] != '1')
			return (ERROR);
		j = 0;
		while (map->map_array[i][j] && map->map_array[i][j + 1] != '\0')
			j++;
		if (map->map_array[i][j] != '1')
			return (ERROR);
		i++;
	}
	map->map_width = j;
	return (NO_ERROR);
}

t_error	ft_check_top_bottom(t_map *map)
{
	char	*first;
	char	*last;

	first = map->map_array[0];
	last = ft_get_to_last_line(map);
	if (ft_check_walls(first) || ft_check_walls(last))
		return (ERROR);
	return (NO_ERROR);
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

	i = 0;
	while (i < map->map_height)
	{
		free(map->map_array[i]);
		i++;
	}
	free(map->map_array[i]);
	free(map->map_array);
}

char	*ft_get_to_last_line(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_array[i + 1] != 0)
		i++;
	return (map->map_array[i]);
}
