/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:09 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/22 16:38:32 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ctx_init(t_ctx *ctx)
{
	ctx->algo = ALGO_UNSET;
	ctx->bench_enabled = 0;
	ctx->flag_count = 0;
	ctx->bench_count = 0;
}


void	check_flags(char* flag, t_ctx *ctx)
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

char	**check_argv(char *str, t_ctx *ctx)
{
  int	i;

  i = 0;
  if (str[i] == '-' && str[i + 1] == '-')
  {
	check_flags(str, ctx);
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

int	is_digit_string(char *s)
{
  int	i;

  i = 0;
  while (s[i])
  {
	if(ft_isdigit((int)s[i]))
	  return (1);
	i++;
  }
  return (0);
}

char	*clean_flags(char **argv, int argc, t_ctx *ctx)
{
  char	*payload;
  int	i;

  payload = "";
  (void) ctx;
  i =0;
  while (i < argc)
  {
	if (is_digit_string(argv[i]))
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
	check_argv(argv[i], &ctx);
	i++;
  }
  clean_flags(argv, argc, &ctx);
}

int	main(int argc, char** argv)
{
  t_ctx	*ctx;

  ctx = malloc(sizeof(t_ctx));
  ctx_init(ctx);
  parsing(argv, argc, *ctx);
}
