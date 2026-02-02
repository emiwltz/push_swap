/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:30:07 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:30:54 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	neg;

	nbr = 0;
	neg = 1;
	while ((*str == ' ') || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (*str - 48) + (nbr * 10);
		str++;
	}
	nbr = nbr * neg;
	return (nbr);
}

/* #include <stdio.h>
int	main(void)
{
	char *i = "   \n -56";
	printf("%d\n", atoi(i));
	printf("%d\n", ft_atoi(i));
	return (0);
} */
