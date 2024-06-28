/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:05:37 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/28 14:35:06 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_error	ft_check_items_internal(t_map *map, int *c_count, int *e_count, \
int *p_count)
{
	int	i;
	int	j;

	*c_count = 0;
	*e_count = 0;
	*p_count = 0;
	i = 1;
	while (i < map->height)
	{
		j = 1;
		while (j < map->width)
		{
			if (ft_is_charset(map->map[i][j], c_count, e_count, p_count))
				return (ERROR);
			j++;
		}
		i++;
	}
	map->collectibles = *c_count;
	return (NO_ERROR);
}

t_error	ft_check_map_exists(int *fd, const char *filename)
{
	int	ret;

	if (filename == NULL)
		return (ERROR);
	ret = open(filename, O_RDONLY);
	if (ret == -1)
		return (printf("Error : Couldn't open map file.\n"), ERROR);
	printf("Map loaded successfully!\n");
	*fd = ret;
	return (NO_ERROR);
}

t_error	ft_check_map_is_enclosed(t_map *map)
{
	if (ft_check_top_bottom(map) || ft_check_sides(map))
		return (printf("Error: Map is not enclose by walls.\n"), ERROR);
	return (printf("Map is enclosed by walls!\n"), NO_ERROR);
}

t_error	ft_check_map_is_rectangular(t_map *map)
{
	int	n_line;
	int	n1_line;
	int	i;
	int	j;

	n_line = 0;
	n1_line = n_line + 1;
	while (map->map[n_line] != 0 && map->map[n1_line] != 0)
	{
		i = 0;
		while (map->map[n_line][i] != 0)
			i++;
		j = 0;
		while (map->map[n1_line][j] != 0)
			j++;
		if (i != j)
			return (printf("Error: Map is not rectangular.\n"), ERROR);
		n_line++;
		n1_line++;
	}
	map->width = i;
	map->height = n_line;
	if (map->map[n1_line - 1] != NULL)
		map->height = n1_line;
	return (printf("Map is rectangular!\n"), NO_ERROR);
}

t_error	ft_check_sides(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i][0] != '1')
			return (ERROR);
		j = 0;
		while (map->map[i][j] && map->map[i][j + 1] != '\0')
			j++;
		if (map->map[i][j] != '1')
			return (ERROR);
		i++;
	}
	map->width = j;
	return (NO_ERROR);
}
