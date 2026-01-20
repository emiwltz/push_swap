/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_printf_int.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ewaltz <ewaltz@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/12/02 16:52:29 by ewaltz			   #+#	  #+#			  */
/*	 Updated: 2025/12/04 13:18:44 by ewaltz			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

long	ft_int_len(long nbr)
{
	long	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_putnbr(int n)
{
	long	nbr;
	char	c;

	nbr = n;
	c = 'x';
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = '0' + nbr;
		write(1, &c, 1);
	}
}

int	ft_printf_int(va_list *args)
{
	int	nbr;

	nbr = va_arg(*args, int);
	ft_putnbr(nbr);
	return (ft_int_len(nbr));
}
