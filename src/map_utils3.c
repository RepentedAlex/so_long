/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:27:03 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 14:27:03 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

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

t_error	ft_is_charset(char c, int *c_count, int *e_count, int *p_count)
{
	if (c == 'C')
		*c_count += 1;
	else if (c == 'E')
		*e_count += 1;
	else if (c == 'P')
		*p_count += 1;
	else if (c != '0' && c != '1')
		return (printf("Error: Invalid characters detected on map.\n"), ERROR);
	return (NO_ERROR);
}
