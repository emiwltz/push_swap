/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:35:00 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 16:44:51 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_adaptive(t_stack **a, t_stack **b, t_ctx *ctx, size_t disorder)
{
	if (disorder < 2000)
	{
		selection(a, b, ctx);
		(*ctx).algo = ALGO_SIMPLE;
	}
	else if (disorder <= 5000)
	{
		chunk_based(a, b, ctx);
		(*ctx).algo = ALGO_MEDIUM;
	}
	else
	{
		radix(a, b, ctx);
		(*ctx).algo = ALGO_COMPLEX;
	}
}

void	choose_algo(t_stack **a, t_stack **b, t_ctx *ctx)
{
	ctx->disorder = compute_disorder(*a);
	if (check_order(a))
	{
		if (ctx->bench_enabled == 1)
			display_bench(&ctx, a);
		return ;
	}
	if (ctx->algo == ALGO_SIMPLE)
		selection(a, b, ctx);
	else if (ctx->algo == ALGO_MEDIUM)
		chunk_based(a, b, ctx);
	else if (ctx->algo == ALGO_COMPLEX)
		radix(a, b, ctx);
	else if (ctx->algo == ALGO_ADAPTIVE)
		run_adaptive(a, b, ctx, ctx->disorder);
	if (ctx->bench_enabled == 1)
		display_bench(&ctx, a);
}
