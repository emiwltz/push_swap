/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_peek_bottom(t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	return (stack->data[stack->size - 1]);
}

int	stack_is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	stack_is_sorted(t_stack *stack)
{
	int	i;

	if (stack->size <= 1)
		return (1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	stack_copy(t_stack *dst, t_stack *src)
{
	int	i;

	dst->size = src->size;
	i = 0;
	while (i < src->size)
	{
		dst->data[i] = src->data[i];
		i++;
	}
}
