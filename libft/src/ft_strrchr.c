/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:13:04 by ewaltz            #+#    #+#             */
/*   Updated: 2025/11/18 13:22:35 by ewaltz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*res;

	cc = (char)c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			res = ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		res = ((char *) &s[i]);
	return (res);
}
