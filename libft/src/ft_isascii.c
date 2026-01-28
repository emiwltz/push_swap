/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:35:13 by ewaltz            #+#    #+#             */
/*   Updated: 2025/11/18 10:47:55 by ewaltz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//int main()
//{
//  printf("%i", ft_isascii('e'));
//  printf("%i", ft_isascii('4'));
//  printf("%i", ft_isascii(' '));
//  printf("%i", ft_isascii('Q'));
//  printf("%i", ft_isascii('\n'));
//}
