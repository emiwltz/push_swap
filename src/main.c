/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:09 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/27 11:16:46 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ctx_init(t_ctx *ctx)
{
	ctx->algo = ALGO_UNSET;
	ctx->bench_enabled = 0;
	ctx->flag_count = 0;
	ctx->bench_count = 0;
}


int	main(int argc, char** argv)
{
  t_ctx	*ctx;

  ctx = malloc(sizeof(t_ctx));
  ctx_init(ctx);
  if(first_check(argv, argc, *ctx) == 1)
  {
	print_error();
	return (1);
  }
  return (0);
}
