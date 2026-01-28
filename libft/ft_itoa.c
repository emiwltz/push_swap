/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:26:52 by alemyre           #+#    #+#             */
/*   Updated: 2025/11/24 15:32:49 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_get_length(int n)
{
	long	nb;
	int		length;

	length = 0;
	nb = n;
	if (nb <= 0)
	{
		length++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		length++;
		nb = nb / 10;
	}
	return (length);
}

static char	*ft_get_nbr(int n, char *res, int length)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		res[0] = '-';
		nb = nb * -1;
		while (--length > 0)
		{
			res[length] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
	else
	{
		while (--length >= 0)
		{
			res[length] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*res;

	length = ft_get_length(n);
	res = malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	res[length] = '\0';
	res = ft_get_nbr(n, res, length);
	return (res);
}
