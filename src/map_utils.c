/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:33:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 14:31:25 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

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
	map->map_array = ft_split(file, '\n');
	free(file);
	printf("Map converted successfully!\n");
	return (close(fd), NO_ERROR);
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
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->map_array[i][j] < 0)
			{
				ft_reset_char(&map->map_array[i][j], &count_collectibles, \
				&reach_exit);
			}
			j++;
		}
		i++;
	}
	if (count_collectibles != map->collectibles || !reach_exit)
		return (printf("Error: Incorrect number of player/exit.\n"), ERROR);
	return (printf("There is a valid number of player/exit!\n"), NO_ERROR);
}

t_error	ft_check_items(t_map *map)
{
	int	collectibles_count;
	int	exit_count;
	int	player_count;
	int	i;
	int	j;

	collectibles_count = 0;
	exit_count = 0;
	player_count = 0;
	i = 1;
	while (i < map->map_height)
	{
		j = 1;
		while (j < map->map_width)
		{
			if (ft_is_charset(map->map_array[i][j], &collectibles_count, \
			&exit_count, &player_count))
				return (ERROR);
			j++;
		}
		i++;
	}
	map->collectibles = collectibles_count;
	return (printf("%d player, %d exit, %d collectibles\n", \
	player_count, exit_count, collectibles_count), NO_ERROR);
}

t_error	ft_check_map_exists(int *fd, const char *filename)
{
	int	ret;

	if (filename == NULL)
		return (ERROR);
	ret = open(filename, O_RDONLY);
	if (ret == -1)
		return (printf("Error : Couldn't open map file.\n"));
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
