/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:15:24 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/09 23:34:15 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

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
		ra(stack_a, ctx);
	}
	while ((*stack_b))
	{
		pa(stack_b, stack_a, ctx);
	}
}
