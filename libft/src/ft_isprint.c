/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:44:27 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:31:27 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//int main()
//{
//  printf("%i", ft_isprint('e'));
//  printf("%i", ft_isprint('4'));
//  printf("%i", ft_isprint(' '));
//  printf("%i", ft_isprint('Q'));
//  printf("%i", ft_isprint('\n'));
//}
