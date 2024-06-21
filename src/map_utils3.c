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

void	ft_reset_char(char *c, int *c_count, int *r_exit)
{
	int	tmp;

	tmp = *c * -1;
	*c = (char)tmp;
	if (*c == 'C')
		*c_count += 1;
	if (*c == 'E')
		*r_exit = 1;
}
