/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:34:55 by ewaltz            #+#    #+#             */
/*   Updated: 2025/11/18 10:57:54 by ewaltz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			t;
	const unsigned char		*str;

	str = (const unsigned char *)s;
	t = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == t)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
