/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:37:15 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:39:43 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_in_set(char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ls1;
	size_t	start;
	size_t	end;
	size_t	lres;
	char	*res;

	ls1 = ft_strlen(s1);
	start = 0;
	end = 0;
	while (s1[start] && is_in_set((char *)set, s1[start]))
		start++;
	if (start != ls1)
		while (s1[end] && is_in_set((char *)set, s1[ls1 - end - 1]))
			end++;
	lres = ls1 - start - end;
	res = malloc(sizeof(char) * (lres + 1));
	if (!res)
		return (NULL);
	ls1 = 0;
	while (ls1 < lres)
		res[ls1++] = s1[start++];
	res[ls1] = '\0';
	return (res);
}
