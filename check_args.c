/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:25:55 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/29 11:56:21 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
  if ((is_digit_string(s) == 1 || is_a_flag(s) == true) && only_spaces(s) == 0 && ( ft_atol(s) < INT_MAX && ft_atol(s) > INT_MIN))
    return (0);
  return (1);
}
