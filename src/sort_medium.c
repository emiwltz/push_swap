/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Medium O(n√n) algorithm: Chunk-based sorting
** Divide elements into √n chunks, push to B, then push back in order
*/

static int	ft_sqrt_approx(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	get_chunk_size(int total_size)
{
	int	sqrt_n;

	sqrt_n = ft_sqrt_approx(total_size);
	if (sqrt_n < 2)
		return (2);
	if (total_size <= 100)
		return (total_size / 5);
	return (total_size / 11);
}

static int	find_closest_in_range(t_data *data, int min, int max)
{
	int	i;
	int	top_dist;
	int	bot_dist;
	int	top_idx;
	int	bot_idx;

	top_idx = -1;
	bot_idx = -1;
	i = 0;
	while (i < data->a->size)
	{
		if (data->a->data[i] >= min && data->a->data[i] <= max)
		{
			top_idx = i;
			break ;
		}
		i++;
	}
	i = data->a->size - 1;
	while (i >= 0)
	{
		if (data->a->data[i] >= min && data->a->data[i] <= max)
		{
			bot_idx = i;
			break ;
		}
		i--;
	}
	if (top_idx == -1)
		return (-1);
	top_dist = top_idx;
	bot_dist = data->a->size - bot_idx;
	if (top_dist <= bot_dist)
		return (top_idx);
	return (bot_idx);
}

static void	push_chunks_to_b(t_data *data, int chunk_size, int total)
{
	int	chunk_min;
	int	chunk_max;
	int	pushed;
	int	pos;
	int	mid;

	pushed = 0;
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	mid = chunk_size / 2;
	while (pushed < total)
	{
		pos = find_closest_in_range(data, chunk_min, chunk_max);
		if (pos == -1)
		{
			chunk_min += chunk_size;
			chunk_max += chunk_size;
			if (chunk_max >= total)
				chunk_max = total - 1;
			mid = chunk_min + chunk_size / 2;
			continue ;
		}
		rotate_to_top(data, pos, 'a');
		op_pb(data, 1);
		if (data->b->size > 1 && data->b->data[0] < mid)
			op_rb(data, 1);
		pushed++;
	}
}

static void	push_back_to_a(t_data *data)
{
	int	max_pos;
	int	size;

	while (data->b->size > 0)
	{
		max_pos = get_max_pos(data->b);
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
}

void	sort_medium(t_data *data)
{
	int	total;
	int	chunk_size;

	if (stack_is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
	{
		sort_small(data);
		return ;
	}
	total = data->a->size;
	normalize_stack(data->a);
	chunk_size = get_chunk_size(total);
	push_chunks_to_b(data, chunk_size, total);
	push_back_to_a(data);
}
