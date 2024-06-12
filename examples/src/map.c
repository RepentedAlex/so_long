/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:52:30 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/12 17:54:43 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/examples.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat_str;
	int		cat_len;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = (int)strlen((char *)s1);
	len_s2 = (int)strlen((char *)s2);
	cat_len = len_s1 + len_s2;
	cat_str = calloc((cat_len) + 1, sizeof(char));
	if (!cat_str)
		return (NULL);
	strlcpy(cat_str, s1, len_s1 + 1);
	strlcat(cat_str, s2, len_s1 + len_s2 + 1);
	return (cat_str);
}

void	ft_ber_to_array(int fd, t_map *map)
{
	char	buffer[2];
	int 	bytes;
	int 	i;

	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	while (bytes == 1)
	{
		bytes = (int)read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
			map->map[i] = ft_strjoin(map->map[i], buffer);
		else
			i++;
	}
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

	ft_check_map_exists(&fd, filename);
	ft_ber_to_array(fd, &map);
	for (int j = 0; map.map[j] != 0; ++j)
	{
		for (int i = 0; map.map[i] != 0; ++i)
		{
			free(map.map[i]);
		}
	}
	free(map.map);
}