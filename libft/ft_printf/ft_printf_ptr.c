/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:15:21 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 13:15:22 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_base(unsigned long nbr)
{
	char	c;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	c = 'x';
	if (nbr >= 16)
	{
		count += ft_putnbr_base(nbr / 16);
		count += ft_putnbr_base(nbr % 16);
	}
	else
	{
		c = base[nbr];
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_printf_ptr(va_list *args)
{
	void			*ptr;
	int				count;
	unsigned long	addr;

	count = 0;
	ptr = va_arg(*args, void *);
	addr = (unsigned long)ptr;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);
	count += ft_putnbr_base(addr);
	return (count);
}
