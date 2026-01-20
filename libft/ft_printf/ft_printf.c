/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:09:30 by ewaltz            #+#    #+#             */
/*   Updated: 2025/12/05 11:34:19 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_router(const char spec, va_list *args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_printf_char(args);
	if (spec == 's')
		count += ft_printf_string(args);
	if (spec == 'p')
		count += ft_printf_ptr(args);
	if (spec == 'i' || spec == 'd')
		count += ft_printf_int(args);
	if (spec == 'u')
		count += ft_printf_unsigned(args);
	if (spec == 'x')
		count += ft_printf_hexa_low(args);
	if (spec == 'X')
		count += ft_printf_hexa_up(args);
	if (spec == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_router(str[i + 1], &args);
			i += 2;
			continue ;
		}
		write(1, &str[i], 1);
		i++;
		count++;
	}
	va_end(args);
	return (count);
}
