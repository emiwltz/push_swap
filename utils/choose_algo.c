/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:35:00 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/24 17:54:23 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	biggest_rank(size_t a, size_t b, size_t c)
{
	if (a > b && a >= c)
		return (a);
	if (b > a && b > c)
		return (b);
	return (c);
}

static void	order_3(t_stack **a, t_ctx *ctx)
{
	size_t	first;
	size_t	second;
	size_t	third;
	size_t	max;

	first = (*a)->head->rank;
	second = (*a)->head->next->rank;
	third = (*a)->head->next->next->rank;
	max = biggest_rank(first, second, third);
	while (!check_order(a))
	{
		if (first == max)
			ra(a, ctx);
		else if (second == max)
			rra(a, ctx);
		if ((*a)->head->rank > (*a)->head->next->rank)
			sa(a, ctx);
	}
}

static void	run_optimal(t_stack **a, t_stack **b, t_ctx *ctx)
{
	if ((*a)->size <= 3)
		order_3(a, ctx);
	else
	{
		if (next_in_first_half(*a, 1))
			while ((*a)->head->rank != 1)
				ra(a, ctx);
		else
			while ((*a)->head->rank != 1)
				rra(a, ctx);
		pb(a, b, ctx);
		if (next_in_first_half(*a, 2))
			while ((*a)->head->rank != 2)
				ra(a, ctx);
		else
			while ((*a)->head->rank != 2)
				rra(a, ctx);
		pb(a, b, ctx);
		order_3(a, ctx);
		if (check_order(b))
			sb(b, ctx);
		pa(b, a, ctx);
		pa(b, a, ctx);
	}
}

static void	run_adaptive(t_stack **a, t_stack **b, t_ctx *ctx, size_t disorder)
{
	if (disorder < 2000)
	{
		selection(a, b, ctx);
		(*ctx).algo = ALGO_SIMPLE;
	}
	else if (disorder < 5000)
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
	if (ctx->algo == ALGO_ADAPTIVE && (*a)->size <= 5)
  {
		ctx->algo = ALGO_TINY;
    run_optimal(a, b, ctx);
  }
	else if (ctx->algo == ALGO_SIMPLE)
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
