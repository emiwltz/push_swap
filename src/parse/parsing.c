/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:25:55 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/26 13:40:28 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	**clean_flags(char **argv, int argc, t_ctx *ctx)
{
  char	*payload;
  int	i;

  payload = "";
  (void) ctx;
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


int	parsing(char **argv, int argc, t_ctx ctx)
{
  int	i;

  i = 1;
  while(i < argc)
  {
	set_flags(argv[i], &ctx);
	if (arg_is_valid(argv[i]) == 1)
	  return (1);
	i++;
  }
  if (ctx.flag_count > 1 || ctx.bench_count > 1)
  {
	print_error();
	return (1);
	}
  clean_flags(argv, argc, &ctx);
  return (0);
}
