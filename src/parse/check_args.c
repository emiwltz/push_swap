/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:25:55 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/27 15:44:06 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**clean_flags(char **argv, int argc)
{
  char	*payload;
  int	i;

  payload = "";
  i = 1;
  while (i < argc)
  {
	if (is_digit_string(argv[i]) == 1)
	{
	  payload = ft_strjoin(payload, argv[i]);
	  payload = ft_strjoin(payload, " ");
	}
	i++;
  }
  ft_printf("%s\n", payload);
  return (ft_split(payload, ' '));
}

bool	is_a_flag(char *s)
{
  if (ft_strcmp(s, FLAG_BENCH) == 0 || ft_strcmp(s, FLAG_SIMPLE) == 0
	|| ft_strcmp(s, FLAG_MEDIUM) == 0 || ft_strcmp(s, FLAG_COMPLEX) == 0
	|| ft_strcmp(s, FLAG_ADAPTIVE) == 0)
	return (true);
  return (false);
}

int	arg_is_valid(char *s)
{
  if (is_digit_string(s) == 1 || is_a_flag(s) == true)
	return (0);
  print_error();
  return (1);
}
