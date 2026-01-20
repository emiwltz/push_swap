/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strmapi.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ewaltz <ewaltz@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/11/14 16:45:27 by ewaltz			   #+#	  #+#			  */
/*	 Updated: 2025/11/18 14:35:45 by ewaltz			  ###	########lyon.fr   */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (!s || !f)
		return (NULL);
	dest = malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
