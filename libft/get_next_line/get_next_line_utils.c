/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:32:41 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/20 15:32:44 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_index(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_rest(char *str, int start)
{
	int		len;
	int		i;
	char	*new_str;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (start >= len)
	{
		free(str);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (len - start + 1));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	while (str[start])
		new_str[i++] = str[start++];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*str_join(char *rest, char *buffer)
{
	int		y;
	int		i;
	char	*new_rest;

	i = 0;
	y = 0;
	new_rest = malloc(sizeof(char) * (ft_strlen(rest) + ft_strlen(buffer) + 1));
	if (!new_rest)
	{
		free(rest);
		return (NULL);
	}
	if (rest)
	{
		while (rest[i])
		{
			new_rest[i] = rest[i];
			i++;
		}
	}
	while (buffer[y])
		new_rest[i++] = buffer[y++];
	new_rest[i] = '\0';
	free(rest);
	return (new_rest);
}
