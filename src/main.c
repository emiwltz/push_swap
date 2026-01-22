/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:09 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/22 10:51:41 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ctx_init(t_ctx *ctx)
{
	ctx->algo = ALGO_ADAPTIVE;
	ctx->bench_enabled = 0;
}


void	check_flags(char* flag)
{

}

void	check_argv(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '-' && str[i + 1] == '-')
  {
	check_flags(str);
	return ;
  }
  else
  {
	ft_split((const char *)str, ' ');
	return ;
  }
}

int	main(int argc, char** argv)
{
  int	i;
  t_ctx	ctx;

  i = 1;
  ctx_init(&ctx);
  while(argc > i)
  {
	check_argv(argv[i]);
	i++;
  }
}
