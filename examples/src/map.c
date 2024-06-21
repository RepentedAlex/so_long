/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:24:11 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/19 17:15:29 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/examples.h"
#include "../../extras/Libft/include/libft.h"

t_error	ft_check_items_internal(t_map_data *map)
{
	int collectibles_count;
	int exit_count;
	int player_count;
	int i;
	int j;

	collectibles_count = 0;
	exit_count = 0;
	player_count = 0;
	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j] != '\0')
		{
			if (map->map_array[i][j] == 'C')
				collectibles_count++;
			else if (map->map_array[i][j] == 'E' && exit_count == 0)
				exit_count++;
			else if (map->map_array[i][j] == 'P' && player_count == 0)
				player_count++;
			else if (map->map_array[i][j] != '0' && map->map_array[i][j] != '1')
			{
				printf("Invalid character detected, must EXTERMINATE\n");
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	map->collectibles = collectibles_count;
	return (NO_ERROR);
}

static t_error	ft_check_sides(t_map_data *map)
{
	int i;
	int j;

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
	return (NO_ERROR);
}

static bool ft_check_wall_line(const char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == '1')
	{
		if (line[i] != '1')
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

static char *ft_get_to_last_line(t_map_data *map)
{
	int i;

	i = 0;
	while (map->map_array[i + 1] != 0)
		i++;
	return map->map_array[i];
}

static t_error	ft_check_top_bottom(t_map_data *map)
{
	char *first;
	char *last;

	first = map->map_array[0];
	last = ft_get_to_last_line(map);
	if (ft_check_wall_line(first) || ft_check_wall_line(last))
		return (ERROR);
	else
		return (NO_ERROR);
}

t_error	ft_check_if_map_is_enclosed(t_map_data *map)
{
	if (ft_check_top_bottom(map) || ft_check_sides(map))
	{
		printf("Map is not enclosed by walls...\n");
		return (ERROR);
	}
	else
	{
		printf("Map is enclosed by walls!\n");
		return (NO_ERROR);
	}
}

/// \brief Checks if the provided map_array is correctly enclosed by walls.
/// \param map The provided map_array to check.
/// \return true if map_array is valid, 0 if invalid.
t_error	ft_check_map_is_rectangular(t_map_data *map)
{
	int	n_line;
	int n1_line;
	int	i;
	int j;

	n_line = 0;
	n1_line = n_line + 1;
	while(map->map_array[n_line] != 0 && map->map_array[n1_line] != 0)
	{
		i = 0;
		while (map->map_array[n_line][i] != 0)
			i++;
		j = 0;
		while (map->map_array[n1_line][j] != 0)
			j++;
		if (i != j)
			return (printf("Map isn't rectangular! :(\n"), ERROR);
		n_line ++;
		n1_line ++;
	}
	map->x = i;
	if (map->map_array[n1_line - 1] != NULL)
		map->y = n1_line;
	else
		map->y = n_line;
	printf("Map is rectangular!\n");
	printf("Map width = %d ; Map height = %d\n", map->x, map->y);
	return (NO_ERROR);
}

t_error	ft_ber_to_array(int fd, t_map_data *map)
{
	static char		buff[BUFFER_SIZE + 1];
	char		*file;
	ssize_t		br;

	ft_bzero(buff, sizeof(buff));
	file = ft_strdup("");
	br = read(fd, buff, BUFFER_SIZE);
	if (br <= 0)
		return (ERROR);
	while (br > 0)
	{
		buff[br] = 0;
		file = ft_strjoin(file, buff);
		br = read(fd, buff, BUFFER_SIZE);
	}
	if (br < 0)
		return (free(file), ERROR);
	map->map_array = ft_split(file, '\n');
	free(file);
	printf("Map converted successfully!\n");
	return (NO_ERROR);
}

t_error	ft_check_map_exists(int *fd, const char *filename)
{
	int ret;

	if (fd == NULL || filename == NULL)
		return (ERROR);
	ret = open(filename, O_RDONLY);
	if (ret == -1)
		return (printf("CPT mec :(((\n"), ERROR);
	printf("Map loaded successfully!\n");
	return (*fd = ret, NO_ERROR);
}

void	ft_test_map(const char *filename)
{
	int	fd;
	t_map_data map;

	ft_bzero(&map, sizeof(map));
	if (ft_check_map_exists(&fd, filename))
		return ;
	if (ft_ber_to_array(fd, &map))
		return ((void)close(fd));
	close(fd);
	if (ft_check_map_is_rectangular(&map))
		return ;
	if (ft_check_if_map_is_enclosed(&map))
		return ;
	if (ft_check_items_internal(&map))
		return ;
	if (ft_flood_fill_handler(&map))
		return ;
	ft_free_map(&map);
}
