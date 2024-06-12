/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examples.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:03:16 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/12 16:48:52 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/examples.h"
#include <string.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	if (!strcmp(argv[1], "display"))
		return (ft_test_displaying(), 0);
	if (!strcmp(argv[1], "map"))
		return (0);
	if (!strcmp(argv[1], "loop"))
		return (0);
	if (!strcmp(argv[1], "data"))
		return (0);
}