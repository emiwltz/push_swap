/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Simple O(n^2) algorithm: Selection sort adaptation
** Push all elements to B, keeping them sorted (max on top)
** Then push all back to A
*/

static int	find_max_in_b(t_data *data)
{
	int	max;
	int	max_pos;
	int	i;

	max = data->b->data[0];
	max_pos = 0;
	i = 1;
	while (i < data->b->size)
	{
		if (data->b->data[i] > max)
		{
			max = data->b->data[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

static void	push_max_to_a(t_data *data)
{
	int	max_pos;
	int	size;

	max_pos = find_max_in_b(data);
	size = data->b->size;
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			op_rb(data, 1);
	}
	else
	{
		while (max_pos++ < size)
			op_rrb(data, 1);
	}
	op_pa(data, 1);
}

void	sort_simple(t_data *data)
{
	if (stack_is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
	{
		sort_small(data);
		return ;
	}
	while (data->a->size > 0)
		op_pb(data, 1);
	while (data->b->size > 0)
		push_max_to_a(data);
}
