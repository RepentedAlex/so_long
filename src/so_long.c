/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:42:57 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 14:12:29 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	ft_map_initialisation(const char *filename, t_map *map)
{
	int	fd;

	if (ft_check_map_exists(&fd, filename))
		return (ERROR);
	if (ft_ber_to_array(fd, map))
		return (ERROR);
	if (ft_check_map_is_rectangular(map))
		return (ERROR);
	if (ft_check_map_is_enclosed(map))
		return (ERROR);
	if (ft_check_items(map))
		return (ERROR);
	return (NO_ERROR);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (ft_map_initialisation(argv[1], &map))
		return (1);
	return (0);
}
