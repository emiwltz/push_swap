/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emi <emi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by emi               #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by emi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Complex O(n log n) algorithm: Radix sort (LSD - Least Significant Digit)
** Uses binary representation, sorts bit by bit from LSB to MSB
*/

static int	get_max_bits(int max_val)
{
	int	bits;

	bits = 0;
	while ((max_val >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_sort_bit(t_data *data, int bit, int size)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	while (i < size)
	{
		if (((data->a->data[0] >> bit) & 1) == 0)
		{
			op_pb(data, 1);
			pushed++;
		}
		else
			op_ra(data, 1);
		i++;
	}
	while (pushed > 0)
	{
		op_pa(data, 1);
		pushed--;
	}
}

void	sort_complex(t_data *data)
{
	int	max_bits;
	int	bit;
	int	size;

	if (stack_is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
	{
		sort_small(data);
		return ;
	}
	normalize_stack(data->a);
	size = data->a->size;
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		radix_sort_bit(data, bit, size);
		bit++;
	}
}
