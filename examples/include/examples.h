/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examples.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:05:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/12 17:43:40 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLES_H
# define EXAMPLES_H

#include "../../extras/minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>

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

bool	ft_check_if_map_is_enclosed(t_map *map);
bool	ft_check_items(t_map *map);
int		ft_check_map_exists(int *fd, const char *filename);
bool	ft_check_map_is_rectangular(t_map *map);
char	**ft_duplicate_map(t_map *source);
void	ft_duplicate_map_data(t_map *source, t_map *duplicate);
void	ft_ber_to_array(int fd, t_map *map);
void	ft_free_map(t_map *map);
bool	ft_flood_fill_handler(t_map *map);
void	ft_test_map(const char *filename);
int		ft_test_displaying(void);


#endif