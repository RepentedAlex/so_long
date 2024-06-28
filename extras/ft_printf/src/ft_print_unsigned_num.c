/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_num.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandropetitcollin <alessandropetitc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:29:30 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 21:48:21 by alessandrop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Calculates the number of digits in an unsigned integer.
 *
 * @param nb The unsigned integer for which to calculate the number of digits.
 * @return The number of digits in the unsigned integer.
 */
int	ft_nb_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

/**
 * Converts an unsigned integer to a string representation.
 *
 * @param n The unsigned integer to be converted.
 * @return A dynamically allocated string representing the unsigned integer.
 *         The caller is responsible for freeing the memory.
 */
char	*ft_uitoa(unsigned int n)
{
	char	*nb;
	int		len;

	len = ft_nb_len(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	nb[len] = 0;
	while (n != 0)
	{
		nb[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (nb);
}

/**
 * Prints an unsigned integer to the standard output.
 *
 * @param n The unsigned integer to be printed.
 * @return The number of characters printed.
 */
int	ft_print_unsigned_num(unsigned int n)
{
	int		print_len;
	char	*nb;

	print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else
	{
		nb = ft_uitoa(n);
		print_len += ft_print_string(nb);
		free(nb);
	}
	return (print_len);
}
