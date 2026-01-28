/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:10:33 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:39:36 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] || (unsigned char)s2[i])
	{
		if (i < n)
		{
			if ((unsigned char)s1[i] > (unsigned char)s2[i])
				return (1);
			if ((unsigned char)s1[i] < (unsigned char)s2[i])
				return (-1);
		}
		i++;
	}
	return (0);
}
