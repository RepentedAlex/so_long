/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:36:27 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/13 17:21:52 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:52:30 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/13 16:30:28 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/examples.h"
#include "../../extras/Libft/include/libft.h"
#include <stdbool.h>

void	ft_init(t_map *map)
{
	map->map_array = malloc(sizeof(char *));
	if (!map->map_array)
		return ;
	map->map_array[0] = malloc((sizeof(char)));
	if (!map->map_array[0])
		return ;
}

/// \brief Checks if the provided map_array is correctly enclosed by walls.
/// \param map The provided map_array to check.
/// \return true if map_array is valid, 0 if invalid.
bool	ft_check_borders(t_map *map)
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
		if (n_line != n1_line)
			return (false);
	}
	return (true);
}

/*
 * 	char	buffer[2];
	long 	bytes;
	int 	i;

	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	map->map_array = malloc(sizeof(char *));
	map->map_array[0] = malloc(sizeof(char));
	map->map_array[0][0] = 0;
	if (!map->map_array)
		return ;
	map->map_array[1] = NULL;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes == 0)
			return ((void)(map->map_array[++i] = NULL));
		if (bytes != 1)
		{
			printf("Read error\n");
			break;
		}
		if (buffer[0] != '\n' && buffer[0] != '\0')
			map->map_array[i] = ft_strjoin(map->map_array[i], buffer);
		else
		{
			printf("line '%s'\n", map->map_array[i]);
			i++;
//			printf("\n");
//			map->map_array = malloc(sizeof(char *));
			map->map_array[i] = malloc(sizeof(char));
			map->map_array[i][0] = 0;
		}
	}
	map->map_array[i] = 0;
	printf("Map successfully converted to 2D array!\n");

 */
void	ft_ber_to_array(int fd, t_map *map)
{
	char		buff[BUFSIZ];
	char		*file;
	ssize_t 		br;

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
	ft_check_borders(&map);
	for (int j = 0; map.map_array[j] != 0; ++j)
	{
		for (int i = 0; map.map_array[i] != 0; ++i)
		{
			free(map.map_array[i]);
		}
	}
	free(map.map_array);
}