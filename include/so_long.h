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

/*Size of the buffer used to read the .ber file*/
#define BUFFER_SIZE 256
#define ERROR 1
#define NO_ERROR 0

typedef bool	t_error;


t_error ft_check_file_is_ber(const char *filename);

t_error	ft_check_map_exists(int *fd, const char *filename);

t_error	ft_check_walls(const char *line);

t_error	ft_is_charset(char c, int *c_count, int *e_count, int *p_count);
void	ft_reset_char(char *c, int *c_count, int *r_exit);

#endif
