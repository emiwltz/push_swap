/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:20:55 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:39:33 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	ls;
	char	*res;

	ls = 0;
	i = 0;
	ls = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	res = malloc(sizeof(char) * (ls + 1));
	if (!res)
		return (NULL);
	while (i < ls)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
