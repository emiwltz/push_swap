/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:16:08 by ewaltz            #+#    #+#             */
/*   Updated: 2025/12/03 13:07:53 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(va_list *args)
{
	int		c_int;
	char	c;

	c_int = va_arg(*args, int);
	c = (char)c_int;
	write(1, &c, 1);
	return (1);
}
