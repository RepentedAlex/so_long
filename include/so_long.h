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
t_error	ft_check_items(t_map *map);
t_error	ft_check_map_exists(int *fd, const char *filename);
t_error ft_check_map_is_enclosed(t_map *map);
t_error	ft_check_map_is_rectangular(t_map *map);
t_error	ft_check_sides(t_map *map);
t_error ft_check_top_bottom(t_map *map);
t_error	ft_check_walls(const char *line);
void	ft_free_map(t_map *map);
char	*ft_get_to_last_line(t_map *map);
t_error	ft_is_charset(char c, int *c_count, int *e_count, int *p_count);

#endif
