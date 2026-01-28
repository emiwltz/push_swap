/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:40:08 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:39:46 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	ls;
	char	*res;

	i = -1;
	ls = ft_strlen(s);
	if (ls == 0 || start >= ft_strlen(s) || len == 0)
	{
		res = malloc(sizeof(char) * 1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (len >= ls - start + 1)
		res = malloc(sizeof(char) * (ls - start + 1));
	else
		res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s[++i] && i < len)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}
