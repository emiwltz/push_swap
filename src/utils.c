/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	int	min;
	int	i;

	if (stack->size == 0)
		return (0);
	min = stack->data[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] < min)
			min = stack->data[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	if (stack->size == 0)
		return (0);
	max = stack->data[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] > max)
			max = stack->data[i];
		i++;
	}
	return (max);
}

int	get_min_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	i;

	if (stack->size == 0)
		return (-1);
	min = stack->data[0];
	pos = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] < min)
		{
			min = stack->data[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_max_pos(t_stack *stack)
{
	int	max;
	int	pos;
	int	i;

	if (stack->size == 0)
		return (-1);
	max = stack->data[0];
	pos = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] > max)
		{
			max = stack->data[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_pos_of_value(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
