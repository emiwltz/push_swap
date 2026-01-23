/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:25:55 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/23 16:26:06 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*clean_flags(char **argv, int argc, t_ctx *ctx)
{
  char	*payload;
  int	i;

  payload = "";
  (void) ctx;
  i =0;
  while (i < argc)
  {
	if (is_digit_string(argv[i]) == 0)
	{
	  payload = ft_strjoin(payload, argv[i]);
	  payload = ft_strjoin(payload, " ");
	}
	i++;
  }
  ft_printf("%s", payload);
  return (payload);
}


void	parsing(char **argv, int argc, t_ctx ctx)
{
  int	i;

  i = 1;
  while(i < argc)
  {
	set_flags(argv[i], &ctx);
	is_mixed(argv[i]);
	i++;
  }
  clean_flags(argv, argc, &ctx);
}
