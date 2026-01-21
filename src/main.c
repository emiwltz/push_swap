/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:13:09 by ewaltz            #+#    #+#             */
/*   Updated: 2026/01/21 17:41:39 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
  t_ctx	ctx;
  ctx_init(&ctx);
  if(argc == 1)
	error_msg();
}

void	ctx_init(t_ctx *ctx)
{
	ctx->algo = ALGO_ADAPTIVE;
	ctx->bench_enabled = 0;
}
