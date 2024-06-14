/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:44:49 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 17:16:10 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sets the first 'n' bytes of the memory area pointed to by 's' to zero.
 *
 * @param to_duplicate - Pointer to the memory area to be zeroed.
 * @param n - Number of bytes to be zeroed.
 */
void	ft_bzero(void *to_duplicate, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = to_duplicate;
	i = 0;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
