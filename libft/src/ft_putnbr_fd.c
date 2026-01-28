/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_putnbr_fd.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ewaltz <ewaltz@student.42lyon.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/17 15:49:44 by ewaltz			   #+#	  #+#			  */
/*	 Updated: 2025/11/20 11:38:50 by ewaltz			  ###	########lyon.fr   */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (fd < 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd((char)(nbr + '0'), fd);
}
