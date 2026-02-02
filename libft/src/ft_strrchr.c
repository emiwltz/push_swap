/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:13:04 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:32:50 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
