/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:15:35 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 13:15:36 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_int_len_unsigned(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	unsigned long	nbr;
	char			c;

	nbr = n;
	c = 'x';
	if (nbr >= 10)
	{
		ft_putnbr_unsigned(nbr / 10);
		ft_putnbr_unsigned(nbr % 10);
	}
	else
	{
		c = '0' + nbr;
		write(1, &c, 1);
	}
}

int	ft_printf_unsigned(va_list *args)
{
	unsigned int	nbr;

	nbr = va_arg(*args, int);
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		ft_putnbr_unsigned(nbr);
		return (ft_int_len_unsigned(nbr));
	}
}
