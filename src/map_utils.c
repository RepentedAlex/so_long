/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:33:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 17:10:57 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_error	ft_ber_to_array(int fd, t_map *map)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*file;
	ssize_t	bytes_read;

	ft_bzero(buffer, sizeof(buffer));
	file = ft_strdup("");
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (ERROR);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = 0;
		file = ft_strjoin(file, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(file), ERROR);
	map->map = ft_split(file, '\n');
	free(file);
	printf("Map converted successfully!\n");
	return (close(fd), NO_ERROR);
}

t_error	ft_check_file_is_ber(const char *filename)
{
	if (ft_strncmp(ft_strrchr(filename, '.'), ".ber", 4))
		return (printf("Error: File provided is not a *.ber file.\n"), ERROR);
	return (printf("File provided is correct (*.ber)!\n"), NO_ERROR);
}

t_error	ft_check_if_finishable(t_map *map)
{
	int	i;
	int	j;
	int	count_collectibles;
	int	reach_exit;

	count_collectibles = 0;
	reach_exit = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] < 0)
			{
				ft_reset_char(&map->map[i][j], &count_collectibles, \
				&reach_exit);
			}
			j++;
		}
		i++;
	}
	if (count_collectibles != map->collectibles || !reach_exit)
		return (printf("Error: Map is not completable.\n"), ERROR);
	return (printf("Map is completable!\n"), NO_ERROR);
}

t_error	ft_check_items(t_map *map)
{
	int	collectibles_count;
	int	exit_count;
	int	player_count;

	if (ft_check_items_internal(map, &collectibles_count, \
	&exit_count, &player_count))
		return (printf("Error: Invalid character detected.\n"), ERROR);
	if (exit_count != 1 || player_count != 1)
		return (printf("Error: Too many player.s or exit.s.\n"), ERROR);
	return (printf("Correct number of player and exit!\n"), NO_ERROR);
}
