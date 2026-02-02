/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:34:55 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:32:01 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
