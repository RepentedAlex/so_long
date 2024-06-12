/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examples.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:05:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/12 16:53:27 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLES_H
# define EXAMPLES_H

#include "../../extras/minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

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
	t_texture	textures[5];
}				t_data;

void	ft_test_map(const char *filename);
int		ft_test_displaying(void);

#endif