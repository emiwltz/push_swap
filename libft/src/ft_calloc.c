/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:30:53 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:31:10 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;
	void			*ptr;

	i = 0;
	if (count == 0 || size == 0)
	{
		ptr = malloc (0);
		return (ptr);
	}
	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
