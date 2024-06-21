/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:27:03 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/21 14:27:03 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_error	ft_is_charset(char c, int *c_count, int *e_count, int *p_count)
{
	if (c == 'C')
		*c_count += 1;
	else if (c == 'E')
		*e_count += 1;
	else if (c == 'P')
		*p_count += 1;
	else if (c != '0' && c != '1')
		return (printf("Error: Invalid characters detected on map.\n"), ERROR);
	return (NO_ERROR);
}
