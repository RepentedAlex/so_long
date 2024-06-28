/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandropetitcollin <alessandropetitc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:32:06 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 21:44:38 by alessandrop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Calculates the length of a hexadecimal number.
 *
 * @param nb The unsigned integer to calculate the length of.
 * @return The length of the hexadecimal number.
 */
int	ft_hex_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

/**
 * @brief Prints the hexadecimal representation of a given number.
 * 
 * This function recursively converts the given number into its hexadecimal representation
 * and prints it to the standard output. The format parameter determines whether the
 * hexadecimal letters should be lowercase ('x') or uppercase ('X').
 * 
 * @param nb The number to be converted and printed.
 * @param format The format of the hexadecimal letters ('x' for lowercase, 'X' for uppercase).
 */
void	ft_put_hex(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, format);
		ft_put_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

/**
 * Prints the hexadecimal representation of a given number.
 *
 * @param nb The number to be printed in hexadecimal format.
 * @param format The format specifier for the hexadecimal representation.
 * @return The length of the hexadecimal representation.
 */
int	ft_print_hex(unsigned int nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(nb, format);
	return (ft_hex_len(nb));
}
