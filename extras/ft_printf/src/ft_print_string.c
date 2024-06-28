/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandropetitcollin <alessandropetitc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:25:49 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 21:46:50 by alessandrop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints a string to the standard output.
 *
 * @param str The string to be printed.
 * @return The number of characters printed.
 */
int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}
