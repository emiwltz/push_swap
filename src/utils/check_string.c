/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:29:01 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/24 16:21:23 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"


int	is_digit_string(char *s)
{
  int	i;

  i = 0;
  while (s[i])
  {
	if(ft_isdigit(s[i]) == 0)
	  return (0);
	i++;
  }
  return (1);
}

int	is_not_digit_string(char *s)
{
  int	i;

  i = 0;
  while (s[i])
  {
	if(ft_isdigit(s[i]) == 1)
	  return (1);
	i++;
  }
  return (0);
}
