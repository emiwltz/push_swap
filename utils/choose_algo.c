/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:35:00 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/16 11:51:15 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_adaptive(t_stack **a, t_stack **b, t_ctx *ctx, size_t disorder)
{
	ft_printf("%zu\n", disorder);
	ft_printf("--------------------------------------------------\n");
	if (disorder < 2000)
		selection(a, b, ctx);
	else if (disorder <= 5000)
		chunk_based(a, b, ctx);
	else
		radix(a, b, ctx);
}

void	choose_algo(t_stack **a, t_stack **b, t_ctx *ctx)
{
	size_t	disorder;

	disorder = compute_disorder(*a);
	(*ctx)->di
	if (!disorder)
	{
		ft_printf("Nothing to do !\n");
		return ;
	}
	ft_printf("--------------------------------------------------\n");
	if (ctx->algo == ALGO_SIMPLE)
		selection(a, b, ctx);
	else if (ctx->algo == ALGO_MEDIUM)
		chunk_based(a, b, ctx);
	else if (ctx->algo == ALGO_COMPLEX)
		radix(a, b, ctx);
	else if (ctx->algo == ALGO_UNSET || ctx->algo == ALGO_ADAPTIVE)
		run_adaptive(a, b, ctx, disorder);
	if (ctx->bench_enabled == 1)
		display_bench(&ctx, a);
}
