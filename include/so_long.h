/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:59:03 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/12 13:59:03 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../extras/minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>

typedef bool	t_error;

typedef struct	s_map
{
	char		**map_array;
	int 		map_height;
	int 		map_width;
	int 		collectibles;
}				t_map;

#define BUFFER_SIZE 256
#define ERROR 1
#define NO_ERROR 0

t_error ft_ber_to_array(int fd, t_map *map);
t_error	ft_check_map_exists(int *fd, const char *filename);
t_error ft_check_map_is_enclosed(t_map *map);
t_error	ft_check_map_is_rectangular(t_map *map);

#endif
