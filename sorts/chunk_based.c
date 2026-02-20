/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:18:47 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/20 01:40:01 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static size_t	get_sqrt(size_t size)
{
	size_t	sqrt;

	if (size < 1)
		return (1);
	sqrt = 1;
	while (sqrt * sqrt < size)
		sqrt++;
	return (sqrt);
}

static void	push_a_to_b(t_stack **a, t_stack **b, t_ctx *ctx, size_t chunk)
{
	size_t	pushed;
	size_t	low;
	size_t	high;
	size_t	rank;
	size_t	count;

	pushed = 0;
	while (*a && (*a)->head)
	{
		high = pushed + chunk;
		low = pushed;
		count = 0;
		while (*a && (*a)->head && count != chunk)
		{
			rank = (*a)->head->rank;
			if (rank > low && rank <= high)
			{
				pb(a, b, ctx);
				count++;
				pushed++;
			}
			else
				ra(a, ctx);
		}
	}
}

static size_t	get_pos(t_stack **b)
{
	size_t	pos;
	size_t	max;
	t_node	*node;

	pos = 0;
	max = 0;
	node = (*b)->head;
	while (node != (*b)->tail)
	{
		if (node->rank > max)
			max = node->rank;
		node = node->next;
	}
	if (node->rank > max)
		max = node->rank;
	node = (*b)->head;
	while (node->rank != max)
	{
		pos++;
		node = node->next;
	}
	return (pos);
}

static void	push_b_to_a(t_stack **a, t_stack **b, t_ctx *ctx, size_t pos)
{
	if (!b || !a)
		return ;
	if (pos < ((*b)->size / 2))
	{
		while ((*b) && (*b)->head->rank != (*b)->size)
			rb(b, ctx);
		pa(b, a, ctx);
	}
	else
	{
		while ((*b) && (*b)->head->rank != (*b)->size)
			rrb(b, ctx);
		pa(b, a, ctx);
	}
}

void	chunk_based(t_stack **a, t_stack **b, t_ctx *ctx)
{
	size_t	chunk_size;

	if (!a || !(*a) || (*a)->size < 2)
		return ;
	chunk_size = get_sqrt((*a)->size);
	push_a_to_b(a, b, ctx, chunk_size);
	while (*b && (*b)->head)
	{
		push_b_to_a(a, b, ctx, get_pos(b));
	}
}
