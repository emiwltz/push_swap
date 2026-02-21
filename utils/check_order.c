/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:28:17 by ewaltz            #+#    #+#             */
/*   Updated: 2026/02/21 17:28:19 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack **a)
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
