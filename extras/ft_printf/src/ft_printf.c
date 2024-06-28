/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandropetitcollin <alessandropetitc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:08:52 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 21:49:40 by alessandrop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints a single character to the standard output.
 *
 * @param c The character to be printed.
 * @return The number of characters written, or -1 if an error occurred.
 */
int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * Evaluates the format specifier and prints the corresponding value.
 * 
 * @param args The variable argument list.
 * @param format The format specifier character.
 * @return The length of the printed output.
 */
int	ft_eval_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	if (format == 's')
		print_len += ft_print_string(va_arg(args, char *));
	if (format == 'p')
		print_len += ft_print_pointer(va_arg(args, unsigned long long));
	if (format == 'd' || format == 'i')
		print_len += ft_print_num(va_arg(args, int));
	if (format == 'u')
		print_len += ft_print_unsigned_num(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), format);
	if (format == '%')
		print_len += write(1, "%", 1);
	return (print_len);
}

/**
 * Prints formatted output to the standard output stream.
 *
 * @param format The format string specifying the output format.
 * @param ...    Additional arguments to be formatted according to the format string.
 * @return       The total number of characters written.
 */
int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	args;

	if (format == NULL)
		return (-1);
	i = 0;
	ret = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret += ft_eval_format(args, format[i + 1]);
			i++;
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (ret);
}
