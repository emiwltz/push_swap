/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:44:24 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/23 14:56:51 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnotdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

// int	is_not_digit_string(char *s)
// {
//   int	i;
//
//   i = 0;
//   while (s[i])
//   {
// 	if(ft_isnotdigit(s[i]) == 0)
// 	  return (1);
// 	i++;
//   }
//   return (0);
// }
