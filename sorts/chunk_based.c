/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:18:47 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/17 16:50:14 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

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
	size_t	rank;

	pushed = 0;
	while (*a && (*a)->size > 0)
	{
		rank = (*a)->head->rank;
		if (rank <= pushed + 1)
		{
			pb(a, b, ctx);
			if (*b && (*b)->size > 1)
				rb(b, ctx);
			pushed++;
		}
		else if (rank <= pushed + chunk)
		{
			pb(a, b, ctx);
			pushed++;
		}
		else
			ra(a, ctx);
	}
}

void	chunk_based(t_stack **a, t_stack **b, t_ctx *ctx)
{
	size_t	chunk_size;
	size_t	rank;

	if (!a || !(*a) || (*a)->size < 2)
		return ;
	chunk_size = get_sqrt((*a)->size);
	push_a_to_b(a, b, ctx, chunk_size);
	rank = (*b)->size;
	while (*b && (*b)->size > 0)
	{
		if ((*b)->head->rank == rank)
		{
		  pa(b, a, ctx);
		  rank--;
		}
		else
		  rb(b, ctx);
	}
}
