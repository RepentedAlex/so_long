/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandropetitcollin <alessandropetitc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:33:16 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 21:50:05 by alessandrop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints a number to the standard output.
 *
 * This function converts the given integer `n` into a string representation
 * using the `ft_itoa` function, and then prints the resulting string using
 * the `ft_print_string` function. The memory allocated for the string is
 * freed before returning the length of the printed string.
 *
 * @param n The number to be printed.
 * @return The length of the printed string.
 */
int	ft_print_num(int n)
{
	int		len;
	char	*nb;

	len = 0;
	nb = ft_itoa(n);
	len = ft_print_string(nb);
	free(nb);
	return (len);
}
