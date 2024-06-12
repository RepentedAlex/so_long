/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examples.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:05:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/12 15:58:08 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLES_H
# define EXAMPLES_H

#include "../../extras/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
}				t_data;

int	ft_test_displaying(void);

#endif