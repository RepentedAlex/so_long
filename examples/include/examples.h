/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examples.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:05:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/19 17:13:30 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLES_H
# define EXAMPLES_H



#define BUFFER_SIZE 65565
#include "../../extras/minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>

typedef bool t_error;

#define ERROR 1
#define NO_ERROR 0

typedef struct s_map
{
	char 	**map_array;
	int		x;
	int 	y;
	int 	player_x;
	int 	player_y;
	int 	collectibles;
}				t_map;

typedef struct s_texture
{
	void	*image;
	int 	width;
	int 	height;
}				t_texture;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_texture	textures[5];

}				t_data;

t_error	ft_ber_to_array(int fd, t_map *map);
t_error ft_check_if_finishable(t_map *map);
t_error	ft_check_if_map_is_enclosed(t_map *map);
t_error	ft_check_items_internal(t_map *map);
t_error	ft_check_map_exists(int *fd, const char *filename);
t_error	ft_check_map_is_rectangular(t_map *map);
void	ft_free_map(t_map *map);
void	ft_flood_fill(t_map *map, int minotaur_x, int minotaur_y);
t_error	ft_flood_fill_handler(t_map *map);
void	ft_test_map(const char *filename);
int		ft_test_displaying(void);


t_error get_char_in_map(t_map *map, int x, int y, char *out);





#endif