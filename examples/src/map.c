/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:52:30 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/12 17:30:48 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/examples.h"
#include <string.h>

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

	ft_check_map_exists(&fd, filename);
}