/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:30:08 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/19 16:44:51 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

size_t	read_bit(size_t number, size_t bit_index)
{
	size_t	bit;

	bit = (number >> bit_index) & 1;
	return (bit);
}

void	radix(t_stack **a, t_stack **b, t_ctx *ctx)
{
	size_t	index_bit;
	size_t	i;
	size_t	stack_size;

	if (!a || !(*a) || (*a)->size < 2)
		return ;
	index_bit = 0;
	while (!check_order(a))
	{
		stack_size = (*a)->size;
		i = 0;
		while (i < stack_size && *a && (*a)->head)
		{
			if (read_bit((*a)->head->rank, index_bit))
				ra(a, ctx);
			else
				pb(a, b, ctx);
			i++;
		}
		while (*b && (*b)->size > 0)
			pa(b, a, ctx);
		index_bit++;
	}
}
