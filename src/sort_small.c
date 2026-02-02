/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	if (data->a->data[0] > data->a->data[1])
		op_sa(data, 1);
}

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->data[0];
	b = data->a->data[1];
	c = data->a->data[2];
	if (a > b && b < c && a < c)
		op_sa(data, 1);
	else if (a > b && b > c)
	{
		op_sa(data, 1);
		op_rra(data, 1);
	}
	else if (a > b && b < c && a > c)
		op_ra(data, 1);
	else if (a < b && b > c && a < c)
	{
		op_sa(data, 1);
		op_ra(data, 1);
	}
	else if (a < b && b > c && a > c)
		op_rra(data, 1);
}

void	sort_four(t_data *data)
{
	int	min_pos;

	min_pos = get_min_pos(data->a);
	rotate_to_top(data, min_pos, 'a');
	op_pb(data, 1);
	sort_three(data);
	op_pa(data, 1);
}

void	sort_five(t_data *data)
{
	int	min_pos;

	min_pos = get_min_pos(data->a);
	rotate_to_top(data, min_pos, 'a');
	op_pb(data, 1);
	min_pos = get_min_pos(data->a);
	rotate_to_top(data, min_pos, 'a');
	op_pb(data, 1);
	sort_three(data);
	op_pa(data, 1);
	op_pa(data, 1);
}

void	sort_small(t_data *data)
{
	if (stack_is_sorted(data->a))
		return ;
	if (data->a->size == 2)
		sort_two(data);
	else if (data->a->size == 3)
		sort_three(data);
	else if (data->a->size == 4)
		sort_four(data);
	else if (data->a->size == 5)
		sort_five(data);
}
