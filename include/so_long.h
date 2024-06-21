/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:59:03 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 15:42:10 by apetitco         ###   ########.fr       */
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
	int			player_x;
	int 		player_y;
	int 		collectibles;
}				t_map;

/*Size of the buffer used to read the .ber file*/
#define BUFFER_SIZE 256
#define ERROR 1
#define NO_ERROR 0

t_error ft_ber_to_array(int fd, t_map *map);
t_error ft_check_file_is_ber(const char *filename);
t_error ft_check_if_finishable(t_map *map);
t_error ft_check_items(t_map *map);
t_error	ft_check_items_internal(t_map *map, int *c_count, int *e_count, int *p_count);
t_error	ft_check_map_exists(int *fd, const char *filename);
t_error ft_check_map_is_enclosed(t_map *map);
t_error	ft_check_map_is_rectangular(t_map *map);
t_error	ft_check_sides(t_map *map);
t_error ft_check_top_bottom(t_map *map);
t_error	ft_check_walls(const char *line);
void	ft_find_player(t_map *map);
void	ft_flood_fill(t_map *map, int minotaur_x, int minotaur_y);
t_error	ft_flood_fill_handler(t_map *map);
void	ft_free_map(t_map *map);
char	*ft_get_to_last_line(t_map *map);
t_error	ft_is_charset(char c, int *c_count, int *e_count, int *p_count);
void	ft_reset_char(char *c, int *c_count, int *r_exit);

#endif
