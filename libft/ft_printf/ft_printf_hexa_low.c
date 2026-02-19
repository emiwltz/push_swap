/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_low.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:14:09 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 13:14:10 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_base_low(unsigned long nbr)
{
	char	c;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	c = 'x';
	if (nbr >= 16)
	{
		count += ft_putnbr_base_low(nbr / 16);
		count += ft_putnbr_base_low(nbr % 16);
	}
	else
	{
		c = base[nbr];
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_printf_hexa_low(va_list *args)
{
	int				count;
	unsigned int	i;

	count = 0;
	i = va_arg(*args, unsigned int);
	count += ft_putnbr_base_low((long)i);
	return (count);
}
