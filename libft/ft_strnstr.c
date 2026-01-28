/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:16:12 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 13:39:38 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	ll;
	char	*cb;
	char	*cl;

	cb = (char *)big;
	cl = (char *)little;
	i = 0;
	ll = ft_strlen(little);
	if (!ll)
		return (cb);
	while (big[i] && len - i >= ll)
	{
		if (ft_strncmp(&cb[i], cl, ll) == 0)
			return (&cb[i]);
		i++;
	}
	return (NULL);
}
