/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:31:03 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:39:20 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	ls;
	size_t	i;

	i = 0;
	ls = ft_strlen(s);
	res = malloc(sizeof(char) * (ls + 1));
	if (!res)
		return (NULL);
	while (i < ls)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
