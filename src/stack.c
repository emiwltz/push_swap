/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = (int *)malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	stack_free(t_stack *stack)
{
	if (stack)
	{
		if (stack->data)
			free(stack->data);
		free(stack);
	}
}

void	stack_push(t_stack *stack, int value)
{
	int	i;

	if (stack->size >= stack->capacity)
		return ;
	i = stack->size;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = value;
	stack->size++;
}

int	stack_pop(t_stack *stack)
{
	int	value;
	int	i;

	if (stack->size == 0)
		return (0);
	value = stack->data[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->size--;
	return (value);
}

int	stack_peek(t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	return (stack->data[0]);
}
