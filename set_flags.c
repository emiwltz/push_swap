/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:59 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/29 11:23:54 by ewaltz           ###   ########.fr       */
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
	set_algo(str, ctx);
  if (ft_strcmp((const char *) str, "--bench") == 0)
  {
	ctx->bench_enabled = true;
	ctx->bench_count += 1;
  }
  return (0);
}

int	second_check(char **argv, int argc)
{
  int	i;
  char **int_table;

  i = 0;
  int_table = clean_flags(argv, argc);
  while (int_table[i] != NULL)
  {
	if (is_valid_digit(int_table[i]) == 0)
	  return (1);
	i++;
  }
  if (third_check(int_table) == NULL)
	return (1);
  return (0);
}

int	first_check(char **argv, int argc, t_ctx ctx)
{
  int	i;

  i = 1;
  while(i < argc)
  {
	set_flags(argv[i], &ctx);
	if (argv[i][0] == '\0')
	  return (1);
	if (arg_is_valid(argv[i]) == 1)
	  return (1);
	i++;
  }
  if (ctx.flag_count > 1 || ctx.bench_count > 1)
	return (1);
  if (second_check(argv, argc) == 1)
	return (1);
  return (0);
}
