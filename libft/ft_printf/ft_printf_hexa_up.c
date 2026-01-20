/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_printf_hexa_up.c								:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ewaltz <ewaltz@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/12/04 11:09:41 by ewaltz			   #+#	  #+#			  */
/*	 Updated: 2025/12/04 11:28:47 by ewaltz			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_up(unsigned long nbr)
{
	char	c;
	int		count;
	char	*base;

	base = "0123456789ABCDEF";
	count = 0;
	c = 'x';
	if (nbr >= 16)
	{
		count += ft_putnbr_base_up(nbr / 16);
		count += ft_putnbr_base_up(nbr % 16);
	}
	else
	{
		c = base[nbr];
		count += write (1, &c, 1);
	}
	return (count);
}

int	ft_printf_hexa_up(va_list *args)
{
	int				count;
	unsigned int	i;

	count = 0;
	i = va_arg(*args, unsigned int);
	count += ft_putnbr_base_up((long)i);
	return (count);
}
