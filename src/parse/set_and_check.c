/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:59 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/24 16:37:04 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_algo(char* flag, t_ctx *ctx)
{
  if (ft_strcmp(FLAG_SIMPLE, flag) == 0)
  {
	ctx->algo = ALGO_SIMPLE;
	ctx->flag_count += 1;
  }
  else if (ft_strcmp(FLAG_MEDIUM, flag) == 0)
  {
	ctx->algo = ALGO_MEDIUM;
	ctx->flag_count += 1;
  }
  else if (ft_strcmp(FLAG_COMPLEX, flag) == 0)
  {
	ctx->algo = ALGO_COMPLEX;
	ctx->flag_count += 1;
  }
  else if (ft_strcmp(FLAG_ADAPTIVE, flag) == 0)
  {
	ctx->algo = ALGO_ADAPTIVE;
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
  if (ft_strcmp((const char *) str, "--bench") == 0)
  {
	ctx->bench_enabled = true;
	ctx->bench_count += 1;
  }
	// return(ft_split((const char *)str, ' '));
  return (0);
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
	return (1);
  return (0);
}
