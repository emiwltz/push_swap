/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:53:15 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/20 12:58:11 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_in_first_half(t_stack *stack, size_t pos)
{
	size_t	count;
	t_node	*temp;

	count = 0;
	temp = stack->head;
	while (temp->rank != pos)
	{
		count++;
		temp = temp->next;
	}
	if (count > (stack->size / 2))
		return (0);
	return (1);
}
