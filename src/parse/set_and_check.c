/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:59 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/24 14:27:56 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	// return(ft_split((const char *)str, ' '));
  return (0);
}

bool	is_a_flag(char *s)
{
  bool	flag;

  flag = false;
  if (ft_strcmp(s, "--bench") || ft_strcmp(s, "--simple") || ft_strcmp(s, "--medium") || ft_strcmp(s, "--complex") || ft_strcmp(s, "--adaptive"))
  {
	ft_printf("%s\n", "flag pas good");
	return (flag);
	flag = true;
  }
  else 
	ft_printf("%s\n", "flag good");
  return (flag);
}

int	arg_is_valid(char *s)
{
  bool	arg;

  arg = false;
  if (is_digit_string(s) == 1 || is_a_flag(s) == true)
  {
	arg = true;
	// return (ft_printf("%s\n", "gooood"));
	return (arg);
  }
  else;
  {
	arg = false;
	// return (ft_printf("%s\n", "gooood"));
	return (arg);
  }
}
