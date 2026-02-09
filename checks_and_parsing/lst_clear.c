/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:15:49 by alemyre           #+#    #+#             */
/*   Updated: 2026/02/09 23:10:17 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_clear(t_stack **stack)
{
	t_node	*temp;
	t_node	*n;

	if ((*stack))
	{
		if ((*stack)->head)
		{
			temp = (*stack)->head;
			while (temp != (*stack)->tail)
			{
				n = temp->next;
				free(temp);
				temp = n;
			}
			free(temp);
		}
		free((*stack));
		(*stack) = NULL;
	}
}
