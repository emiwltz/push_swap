/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:47:10 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:39:40 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			ls;
	char			*cs;
	unsigned char	uc;

	cs = (char *)s;
	ls = ft_strlen(cs);
	uc = (unsigned char)c;
	if (uc == '\0')
		return (&cs[ls]);
	while (ls-- > 0)
		if (s[ls] == uc)
			return (&cs[ls]);
	return (NULL);
}
