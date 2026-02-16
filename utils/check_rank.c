/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:13:01 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/16 13:13:05 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
