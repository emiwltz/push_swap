/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:15:24 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 16:33:12 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static int	next_in_first_half(t_stack *stack, size_t pos)
{
	size_t	count;

	count = 0;
	while (stack->head->rank != pos)
	{
		count++;
		stack->head = stack->head->next;
	}
	if (count >= stack->size / 2)
		return (0);
	return (1);
}

void	selection(t_stack **stack_a, t_stack **stack_b, t_ctx *ctx)
{
	size_t	pos;

	pos = 1;
	while ((*stack_a))
	{
		if ((*stack_a)->head->rank == pos)
		{
			pb(stack_a, stack_b, ctx);
			pos++;
			continue ;
		}
		if (next_in_first_half(*stack_a, pos))
			ra(stack_a, ctx);
		else
			rra(stack_a, ctx);
	}
	while ((*stack_b))
	{
		pa(stack_b, stack_a, ctx);
	}
}
