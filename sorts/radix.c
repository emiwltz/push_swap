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
  t_node	*node;
  size_t	rank;
  size_t	index_bit;
  size_t	i;
  size_t	stack_size;

  node = (*a)->head;
  rank = node->rank;
  i = 0;
  index_bit = 0;
  while (!check_rank(a))
  {
	stack_size = (*a)->size;
	while (i < stack_size)
	{
	  if (read_bit(rank, index_bit))
		ra(a);
	  else
		pb(a, b);
	  if (a)
	  {
		node = (*a)->head;
		rank = node->rank;
	  }
	  i++;
	}
	while ((*b)->head != (*b)->tail->next)
	  pa(b, a);
	index_bit++;
	i = 0;
  }
}
