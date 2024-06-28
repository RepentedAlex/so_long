/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandropetitcollin <alessandropetitc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:12 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 21:27:38 by alessandrop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_eval_format(va_list args, const char format);
int		ft_hex_len(unsigned int nb);
int		ft_nb_len(unsigned int nb);
int		ft_pointer_len(uintptr_t nb);
int		ft_print_char(int c);
int		ft_print_hex(unsigned int nb, const char format);
int		ft_print_num(int n);
int		ft_print_pointer(unsigned long long ptr);
int		ft_print_string(char *str);
int		ft_print_unsigned_num(unsigned int n);
int		ft_printf(const char *format, ...);
void	ft_put_hex(unsigned int nb, const char format);
void	ft_put_pointer(uintptr_t nb);
char	*ft_uitoa(unsigned int n);

#endif
