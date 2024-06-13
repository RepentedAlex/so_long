/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:24:11 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/13 18:24:11 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/examples.h"
#include "../../extras/Libft/include/libft.h"
#include <stdbool.h>

static bool	ft_check_sides(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map_array[i])
	{
		if (map->map_array[i][0] != '1')
			return (false);
		j = 0;
		while (map->map_array[i][j] && map->map_array[i][j + 1] != '\0')
			j++;
		if (map->map_array[i][j] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_check_wall_line(char *line, char c)
{
	int i;

	i = 0;
	while (line[i] && line[i] == c)
	{
		if (line[i] != c)
			return (false);
		i++;
	}
	return (true);
}

static char *ft_get_to_last_line(t_map *map)
{
	int i;

	i = 0;
	while (map->map_array[i + 1] != 0)
		i++;
	return map->map_array[i];
}

static bool	ft_check_top_bottom(t_map *map)
{
	char *first;
	char *last;

	first = map->map_array[0];
	last = ft_get_to_last_line(map);
	if (ft_check_wall_line(first, '1') == false || ft_check_wall_line(last, '1') == false)
		return (false);
	else
		return (true);
}

bool	ft_check_if_map_is_enclosed(t_map *map)
{
	if (ft_check_top_bottom(map) == false || ft_check_sides(map) == false)
	{
		printf("Map is not enclosed by walls...\n");
		return (false);
	}
	else
	{
		printf("Map is enclosed by walls!\n");
		return (true);
	}
}

/// \brief Checks if the provided map_array is correctly enclosed by walls.
/// \param map The provided map_array to check.
/// \return true if map_array is valid, 0 if invalid.
bool	ft_check_map_is_rectangular(t_map *map)
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
			return (printf("Map isn't rectangular! :(\n"), false);
		n_line ++;
		n1_line ++;
	}
	printf("Map is rectangular!\n");
	return (true);
}

void	ft_ber_to_array(int fd, t_map *map)
{
	char		buff[BUFSIZ];
	char		*file;
	ssize_t		br;

	file = ft_strdup("");
	br = read(fd, buff, BUFSIZ);
	if (br <= 0)
		return ;
	while (br > 0)
	{
		buff[br] = 0;
		file = ft_strjoin(file, buff);
		br = read(fd, buff, BUFSIZ);
	}
	if (br < 0)
		return (free(file));
	map->map_array = ft_split(file, '\n');
	free(file);
	printf("Map converted successfully!\n");
}

int	ft_check_map_exists(int *fd, const char *filename)
{
	*fd = 0;
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (printf("CPT mec :(((\n"), 2345);
	printf("Map loaded successfully!\n");
	return (0);
}

void	ft_test_map(const char *filename)
{
	int	fd;
	t_map map;

	ft_bzero(&map, sizeof(map));
	ft_check_map_exists(&fd, filename);
	ft_ber_to_array(fd, &map);
	close(fd);
	if (ft_check_map_is_rectangular(&map) == false)
		return ;
	if (ft_check_if_map_is_enclosed(&map) == false)
		return ;
	for (int i = 0; map.map_array[i] != 0; ++i)
			free(map.map_array[i]);
	free(map.map_array);
}