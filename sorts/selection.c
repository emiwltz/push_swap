/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:15:24 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/20 12:59:25 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		pa(stack_b, stack_a, ctx);
}
