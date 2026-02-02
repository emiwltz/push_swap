/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:29:11 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:32:08 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_src;
	unsigned char	*c_dst;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	c_src = (unsigned char *)src;
	c_dst = (unsigned char *)dst;
	i = 0;
	if (c_dst > c_src)
	{
		while (len--)
			c_dst[len] = c_src[len];
	}
	else
	{
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}
