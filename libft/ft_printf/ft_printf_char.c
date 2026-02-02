/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:16:08 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:33:21 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf_char(va_list *args)
{
	int		c_int;
	char	c;

	c_int = va_arg(*args, int);
	c = (char)c_int;
	write(1, &c, 1);
	return (1);
}
