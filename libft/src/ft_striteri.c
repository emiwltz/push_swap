/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_striteri.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ewaltz <ewaltz@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/14 17:19:49 by ewaltz			   #+#	  #+#			  */
/*	 Updated: 2025/11/18 11:20:22 by ewaltz			  ###	########lyon.fr   */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
