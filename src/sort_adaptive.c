/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Adaptive algorithm: Selects strategy based on disorder
** Low disorder (< 0.2): O(n) - minimal rotation/swap
** Medium disorder (0.2 - 0.5): O(n√n) - chunk-based
** High disorder (>= 0.5): O(n log n) - radix sort
*/

static int	find_sorted_rotation(t_stack *stack)
{
	int	i;
	int	min_pos;
	int	sorted;

	min_pos = get_min_pos(stack);
	sorted = 1;
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[(min_pos + i) % stack->size]
			> stack->data[(min_pos + i + 1) % stack->size])
		{
			sorted = 0;
			break ;
		}
		i++;
	}
	if (sorted)
		return (min_pos);
	return (-1);
}

static void	sort_low_disorder(t_data *data)
{
	int	rot;
	int	size;

	rot = find_sorted_rotation(data->a);
	if (rot != -1)
	{
		size = data->a->size;
		if (rot <= size / 2)
		{
			while (rot-- > 0)
				op_ra(data, 1);
		}
		else
		{
			while (rot++ < size)
				op_rra(data, 1);
		}
		return ;
	}
	sort_medium(data);
}

static void	sort_medium_disorder(t_data *data)
{
	sort_medium(data);
}

static void	sort_high_disorder(t_data *data)
{
	sort_complex(data);
}

void	sort_adaptive(t_data *data)
{
	if (stack_is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
	{
		sort_small(data);
		return ;
	}
	if (data->disorder < 0.2)
		sort_low_disorder(data);
	else if (data->disorder < 0.5)
		sort_medium_disorder(data);
	else
		sort_high_disorder(data);
}
