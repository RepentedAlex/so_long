/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandropetitcollin <alessandropetitc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:26:59 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 21:46:14 by alessandrop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Calculates the length of a pointer value in hexadecimal format.
 *
 * @param nb The pointer value to calculate the length for.
 * @return The length of the pointer value in hexadecimal format.
 */
int	ft_pointer_len(uintptr_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

/**
 * Prints the hexadecimal representation of a pointer.
 * 
 * @param nb The pointer value to be printed.
 */
void	ft_put_pointer(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_put_pointer(nb / 16);
		ft_put_pointer(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

/**
 * Prints the value of a pointer in hexadecimal format.
 * If the pointer is NULL, it prints "(nil)".
 * Returns the total number of characters printed.
 *
 * @param ptr The pointer value to be printed.
 * @return The total number of characters printed.
 */
int	ft_print_pointer(unsigned long long ptr)
{
	int	print_len;

	print_len = 0;
	if (ptr == 0)
	{
		print_len += write(1, "(nil)", 5);
	}
	else
	{
		print_len += write(1, "0x", 2);
		ft_put_pointer(ptr);
		print_len += ft_pointer_len(ptr);
	}
	return (print_len);
}
