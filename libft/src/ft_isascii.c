/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:35:13 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:31:21 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
