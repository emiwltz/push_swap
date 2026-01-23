/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:59 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/23 16:29:37 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_algo(char* flag, t_ctx *ctx)
{
  const char	*algo_simple;
  const char	*algo_medium;
  const char	*algo_complex;

  algo_simple = FLAG_SIMPLE;
  algo_medium = FLAG_MEDIUM;
  algo_complex = FLAG_COMPLEX;
  if (ft_strcmp(algo_simple, flag) == 0)
  {
	ctx->algo = ALGO_SIMPLE;
	ctx->flag_count += 1;
  }
  if (ft_strcmp(algo_medium, flag) == 0)
  {
	ctx->algo = ALGO_MEDIUM;
	ctx->flag_count += 1;
  }
  if (ft_strcmp(algo_complex, flag) == 0)
  {
	ctx->algo = ALGO_COMPLEX;
	ctx->flag_count += 1;
  }
}


char	**set_flags(char *str, t_ctx *ctx)
{
  int	i;

  i = 0;
  if (str[i] == '-' && str[i + 1] == '-')
  {
	set_algo(str, ctx);
	return (0);
  }
  if (ft_strcmp((const char *) str, "--bench"))
  {
	ctx->bench_enabled = true;
	ctx->bench_count += 1;
  }
  else
	return(ft_split((const char *)str, ' '));
  return (0);
}


int	is_mixed(char *s)
{
  bool	digit;
  bool	alpha;

  digit = false;
  if (is_not_digit_string(s) == 1)
	  alpha = true;
  if (is_digit_string(s) == 1)
	  digit = true;
  if (digit == true && alpha == true)
	return (ft_printf("%s", "error"));
  return (ft_printf("%s", "gooood"));
}
