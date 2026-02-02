/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*get_sorted_array(t_stack *stack)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		arr[i] = stack->data[i];
		i++;
	}
	sort_array(arr, stack->size);
	return (arr);
}

void	normalize_stack(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = get_sorted_array(stack);
	if (!sorted)
		return ;
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->data[i] == sorted[j])
			{
				stack->data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}

void	rotate_to_top(t_data *data, int pos, char stack_name)
{
	int	size;

	if (stack_name == 'a')
		size = data->a->size;
	else
		size = data->b->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (stack_name == 'a')
				op_ra(data, 1);
			else
				op_rb(data, 1);
		}
	}
	else
	{
		while (pos++ < size)
		{
			if (stack_name == 'a')
				op_rra(data, 1);
			else
				op_rrb(data, 1);
		}
	}
}
