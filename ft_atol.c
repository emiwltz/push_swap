/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:45:41 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/29 11:47:02 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	nbr;
	long	neg;

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
