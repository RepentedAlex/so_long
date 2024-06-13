/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:58:12 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/13 16:42:20 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Concatenates two strings.
 *
 * This function concatenates the strings `s1` and `s2` into a newly allocated
 * string. The resulting string is terminated with a null character ('\0').
 *
 * @param s1 The first string to be concatenated.
 * @param s2 The second string to be concatenated.
 * @return A pointer to the newly allocated string,
 * or NULL if the allocation fails.
 */
char *ft_strjoin(char *s1, char const *s2)
{
	char *cat_str;
	int i;
	int j;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	cat_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!cat_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		cat_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		cat_str[i++] = s2[j++];
	cat_str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (cat_str);
}
