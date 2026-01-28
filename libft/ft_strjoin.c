/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:23:43 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/25 10:12:19 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	ls1;
	size_t	ls2;

	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	res = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ls1 + 1);
	ft_strlcat(res, s2, ls1 + ls2 + 1);
	return (res);
}
