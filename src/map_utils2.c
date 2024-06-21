/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:05:37 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 15:46:54 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_error	ft_check_map_is_rectangular(t_map *map)
{
	int	n_line;
	int	n1_line;
	int	i;
	int	j;

	n_line = 0;
	n1_line = n_line + 1;
	while (map->map_array[n_line] != 0 && map->map_array[n1_line] != 0)
	{
		i = 0;
		while (map->map_array[n_line][i] != 0)
			i++;
		j = 0;
		while (map->map_array[n1_line][j] != 0)
			j++;
		if (i != j)
			return (printf("Error: Map is not rectangular.\n"), ERROR);
		n_line++;
		n1_line++;
	}
	map->map_width = i;
	map->map_height = n_line;
	if (map->map_array[n1_line - 1] != NULL)
		map->map_height = n1_line;
	return (printf("Map is rectangular!\n"), NO_ERROR);
}

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
