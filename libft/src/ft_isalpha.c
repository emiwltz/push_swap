/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:34:04 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/02 15:31:19 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//int main()
//{
//  printf("%i", ft_isalpha('e'));
//  printf("%i", ft_isalpha('4'));
//  printf("%i", ft_isalpha(' '));
//  printf("%i", ft_isalpha('Q'));
//  printf("%i", ft_isalpha('\n'));
//}
