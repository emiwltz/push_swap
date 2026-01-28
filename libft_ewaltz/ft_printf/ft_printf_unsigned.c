/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_printf_unsigned.c								:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ewaltz <ewaltz@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/12/03 15:03:00 by ewaltz			   #+#	  #+#			  */
/*	 Updated: 2025/12/05 11:05:53 by ewaltz			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

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
		write (1, "0", 1);
		return (1);
	}
	else
	{
		ft_putnbr_unsigned(nbr);
		return (ft_int_len_unsigned(nbr));
	}
}
