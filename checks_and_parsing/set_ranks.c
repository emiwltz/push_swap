/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ranks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:40:01 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/19 13:13:32 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	get_rank(t_node *selected)
{
	size_t	rank;
	t_node	*temp;

	rank = 1;
	temp = selected->next;
	temp = selected->next;
	while (temp != selected)
	{
		if (selected->value > temp->value)
			rank++;
		temp = temp->next;
	}
	return (rank);
}

void	set_ranks(t_stack **stack)
{
	t_node	*selected;

	selected = (*stack)->head;
	if ((*stack)->size > 1)
	{
		while (selected != (*stack)->tail)
		{
			selected->rank = get_rank(selected);
			selected = selected->next;
		}
		selected->rank = get_rank(selected);
	}
}
