/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:19:54 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:39:17 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*cs;
	unsigned char	uc;

	uc = (unsigned char)c;
	cs = (char *)s;
	i = -1;
	if (uc == '\0' && s[0] == '\0')
		return (cs);
	while (s[++i])
	{
		if (s[i] == uc)
			return (&cs[i]);
		if (uc == '\0' && s[i + 1] == uc)
			return (&cs[i + 1]);
	}
	return (NULL);
}
