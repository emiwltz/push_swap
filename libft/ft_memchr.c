/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:41:05 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:38:50 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ucs;

	ucs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ucs[i] == (unsigned char)c)
			return (&((void *)ucs)[i]);
		i++;
	}
	return (NULL);
}
