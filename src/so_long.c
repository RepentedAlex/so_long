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

#include "libft.h"
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
	if (ft_flood_fill_handler(map))
		return (ERROR);
	return (NO_ERROR);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	ft_bzero(&map, sizeof(map));
	if (argc != 2)
		return (1);
	if (ft_check_file_is_ber(argv[1]))
		return (ERROR);
	if (ft_map_initialisation(argv[1], &map))
	{
		if (map.map_array)
			ft_free_map(&map);
		return (2);
	}
	if (map.map_array != NULL)
		ft_free_map(&map);
	return (0);
}
