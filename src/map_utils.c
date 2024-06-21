/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:33:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 10:33:17 by apetitco         ###   ########.fr       */
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
	return (NO_ERROR);
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
	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j] != '\0')
		{
			if (ft_is_charset(map->map_array[i][j], &collectibles_count, \
			&exit_count, &player_count))
				return (ERROR);
			j++;
		}
		i++;
	}
	map->collectibles = collectibles_count;
	return (NO_ERROR);
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
