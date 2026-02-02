/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:36:25 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:31:25 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//int main()
//{
//  printf("%i", ft_isdigit('e'));
//  printf("%i", ft_isdigit('4'));
//  printf("%i", ft_isdigit(' '));
//  printf("%i", ft_isdigit('Q'));
//  printf("%i", ft_isdigit('\n'));
//}
