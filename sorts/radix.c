/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:30:08 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/10 19:02:58 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	read_bit(size_t number, size_t bit_index)
{
  int bit;

  bit = (number >> bit_index) & 1;
  return (bit);
}

int	check_rank(t_stack **a)
{
	t_node	*node;

	if (!a || !(*a) || !(*a)->head || (*a)->size < 2)
		return (1);
	node = (*a)->head;
	while (node != (*a)->tail)
	{
		if (node->rank > node->next->rank)
			return (0);
		node = node->next;
	}
	return (1);
}


void	radix(t_stack **a, t_stack **b)
{
	size_t	index_bit;
	size_t	i;
	size_t	stack_size;

	if (!a || !(*a) || (*a)->size < 2)
		return ;
	index_bit = 0;
	while (!check_rank(a))
	{
		stack_size = (*a)->size;
		i = 0;
		while (i < stack_size && *a && (*a)->head)
		{
			if (read_bit((*a)->head->rank, index_bit))
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (*b && (*b)->size > 0)
			pa(b, a);
		index_bit++;
	}
}
